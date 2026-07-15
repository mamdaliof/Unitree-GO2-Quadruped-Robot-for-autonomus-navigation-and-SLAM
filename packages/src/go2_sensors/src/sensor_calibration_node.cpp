#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <unitree_api/msg/request.hpp>
#include <common/ros2_sport_client.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <memory>
#include <cmath>
#include <filesystem>
#include <ctime>
#include <iomanip>
#include <sstream>

using json = nlohmann::json;

/**
 * @brief Helper utility to parse configuration settings from the go2_config.json file.
 */
class SimpleConfig
{
public:
  static std::string getValue(const std::string& filepath, const std::string& section, const std::string& key, const std::string& default_val = "")
  {
    try {
      std::ifstream file(filepath);
      if (!file.is_open()) {
        return default_val;
      }
      json data;
      file >> data;
      if (data.contains(section) && data[section].contains(key)) {
        if (data[section][key].is_string()) {
          return data[section][key].get<std::string>();
        } else {
          return data[section][key].dump();
        }
      }
    } catch (const std::exception&) {
      // Return default on error
    }
    return default_val;
  }

  static bool getBoolValue(const std::string& filepath, const std::string& section, const std::string& key, bool default_val = false)
  {
    try {
      std::ifstream file(filepath);
      if (!file.is_open()) {
        return default_val;
      }
      json data;
      file >> data;
      if (data.contains(section) && data[section].contains(key)) {
        if (data[section][key].is_boolean()) {
          return data[section][key].get<bool>();
        }
      }
    } catch (const std::exception&) {
      // Return default on error
    }
    return default_val;
  }

  static double getDoubleValue(const std::string& filepath, const std::string& section, const std::string& key, double default_val = 0.0)
  {
    try {
      std::ifstream file(filepath);
      if (!file.is_open()) {
        return default_val;
      }
      json data;
      file >> data;
      if (data.contains(section) && data[section].contains(key)) {
        if (data[section][key].is_number()) {
          return data[section][key].get<double>();
        }
      }
    } catch (const std::exception&) {
      // Return default on error
    }
    return default_val;
  }
};

class SensorCalibrationNode : public rclcpp::Node
{
public:
  SensorCalibrationNode() : Node("sensor_calibration_node"), state_(-1), file_written_(false)
  {
    // Declare parameters
    this->declare_parameter<std::string>("config_path", "/home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/go2_config.json");
    this->declare_parameter<std::string>("log_dir", "/home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/packages/src/go2_sensors/log");

    config_path_ = this->get_parameter("config_path").as_string();
    log_dir_ = this->get_parameter("log_dir").as_string();

    // Check if calibration is enabled in configuration
    bool calib_enabled = SimpleConfig::getBoolValue(config_path_, "sensors", "calibration_phase", true);
    if (!calib_enabled) {
      RCLCPP_INFO(this->get_logger(), "Calibration phase is disabled in configuration. Exiting node.");
      rclcpp::shutdown();
      return;
    }

    // Read LiDAR tilt angle to calculate theta
    double tilt_deg = SimpleConfig::getDoubleValue(config_path_, "sensors", "lidar_tilt_angle_deg", 13.0);
    theta_ = tilt_deg * M_PI / 180.0;
    RCLCPP_INFO(this->get_logger(), "Starting sensor calibration. LiDAR tilt angle: %.2f deg (theta = %.4f rad)", tilt_deg, theta_);

    // Read configured topics
    std::string imu_topic = SimpleConfig::getValue(config_path_, "topics", "imu_input", "/utlidar/imu");

    // Initialize publishers and subscribers
    pub_sport_request_ = this->create_publisher<unitree_api::msg::Request>("/api/sport/request", 10);
    pub_cmd_vel_ = this->create_publisher<geometry_msgs::msg::TwistStamped>("/cmd_vel", 5);
    sub_imu_ = this->create_subscription<sensor_msgs::msg::Imu>(
      imu_topic, 300, std::bind(&SensorCalibrationNode::ImuCallback, this, std::placeholders::_1)
    );

    beginning_time_ = std::chrono::system_clock::now();

    // Run calibration timer loop at 100 Hz
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(10), std::bind(&SensorCalibrationNode::TimerCallback, this)
    );
  }

private:
  void ImuCallback(const sensor_msgs::msg::Imu::ConstSharedPtr msg_in)
  {
    // Coordinates conversion to Z-up base frame (pitch rotation by theta about Y-axis)
    double x = msg_in->angular_velocity.x;
    double y = -msg_in->angular_velocity.y;
    double z = -msg_in->angular_velocity.z;

    double x2 = x * cos(theta_) - z * sin(theta_);
    double y2 = y;
    double z2 = x * sin(theta_) + z * cos(theta_);

    double acc_x = msg_in->linear_acceleration.x;
    double acc_y = -msg_in->linear_acceleration.y;
    double acc_z = -msg_in->linear_acceleration.z;

    double acc_x2 = acc_x * cos(theta_) - acc_z * sin(theta_);
    double acc_y2 = acc_y;
    double acc_z2 = acc_x * sin(theta_) + acc_z * cos(theta_);

    sensor_msgs::msg::Imu msg_store = *msg_in;
    msg_store.angular_velocity.x = x2;
    msg_store.angular_velocity.y = y2;
    msg_store.angular_velocity.z = z2;
    msg_store.linear_acceleration.x = acc_x2;
    msg_store.linear_acceleration.y = acc_y2;
    msg_store.linear_acceleration.z = acc_z2;

    if (state_ == 1) {
      imu_static_.push_back(msg_store);
    } else if (state_ == 2) {
      imu_rotation_positive_z_.push_back(msg_store);
    }
  }

  void TimerCallback()
  {
    auto current = std::chrono::system_clock::now();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(current - beginning_time_).count();

    geometry_msgs::msg::TwistStamped cmd_vel;
    cmd_vel.header.stamp = this->now();
    cmd_vel.header.frame_id = "vehicle";

    unitree_api::msg::Request req;
    SportClient sport_req;

    double ang_vel = 1.396; // Yaw speed for rotation phase

    if (seconds < 2) {
      // State 0: Adjusting position / Standing still
      cmd_vel.twist.linear.x = 0;
      cmd_vel.twist.linear.y = 0;
      cmd_vel.twist.angular.z = 0;
      pub_cmd_vel_->publish(cmd_vel);

      sport_req.Move(req, 0, 0, 0);
      pub_sport_request_->publish(req);

      state_ = 0;
      RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000, "Calibration state 0: Adjusting robot to initial position...");
    }
    else if (seconds >= 2 && seconds < 15) {
      // State 1: Collecting static bias data
      cmd_vel.twist.linear.x = 0;
      cmd_vel.twist.linear.y = 0;
      cmd_vel.twist.angular.z = 0;
      pub_cmd_vel_->publish(cmd_vel);

      sport_req.StopMove(req);
      pub_sport_request_->publish(req);

      if (seconds >= 5) {
        state_ = 1;
      }
      RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000, "Calibration state 1: Collecting static bias data...");
    }
    else if (seconds >= 15 && seconds < 35) {
      // State 2: Rotating yaw to calibrate projection misalignment
      cmd_vel.twist.linear.x = 0;
      cmd_vel.twist.linear.y = 0;
      cmd_vel.twist.angular.z = ang_vel;
      pub_cmd_vel_->publish(cmd_vel);

      sport_req.Move(req, cmd_vel.twist.linear.x, cmd_vel.twist.linear.y, cmd_vel.twist.angular.z);
      pub_sport_request_->publish(req);

      state_ = 2;
      RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000, "Calibration state 2: Collecting rotation data (active rotation)...");
    }
    else if (seconds >= 35 && seconds < 37) {
      // State 3: Stopping and processing results
      cmd_vel.twist.linear.x = 0;
      cmd_vel.twist.linear.y = 0;
      cmd_vel.twist.angular.z = 0;
      pub_cmd_vel_->publish(cmd_vel);

      sport_req.StopMove(req);
      pub_sport_request_->publish(req);

      state_ = 3;
    }

    if (state_ == 3 && !file_written_) {
      RCLCPP_INFO(this->get_logger(), "Calibration sequence complete. Processing data...");
      ComputeCalibration();
      file_written_ = true;
      RCLCPP_INFO(this->get_logger(), "Calibration node complete. Shutting down.");
      rclcpp::shutdown();
    }
  }

  void ComputeCalibration()
  {
    if (imu_static_.empty() || imu_rotation_positive_z_.empty()) {
      RCLCPP_ERROR(this->get_logger(), "Insufficient IMU data collected! Static samples: %zu, Rotation samples: %zu",
                   imu_static_.size(), imu_rotation_positive_z_.size());
      return;
    }

    double acc_bias_x = 0;
    double acc_bias_y = 0;
    double acc_bias_z = 0;
    double ang_bias_x = 0;
    double ang_bias_y = 0;
    double ang_bias_z = 0;

    for (const auto& imu : imu_static_) {
      acc_bias_x += imu.linear_acceleration.x;
      acc_bias_y += imu.linear_acceleration.y;
      acc_bias_z += imu.linear_acceleration.z;
      ang_bias_x += imu.angular_velocity.x;
      ang_bias_y += imu.angular_velocity.y;
      ang_bias_z += imu.angular_velocity.z;
    }

    acc_bias_x /= imu_static_.size();
    acc_bias_y /= imu_static_.size();
    acc_bias_z /= imu_static_.size();
    ang_bias_x /= imu_static_.size();
    ang_bias_y /= imu_static_.size();
    ang_bias_z /= imu_static_.size();

    // Subtract gravity constant from z bias
    acc_bias_z -= 9.81;

    double ang_rot_x = 0;
    double ang_rot_y = 0;
    double ang_rot_z = 0;

    for (const auto& imu : imu_rotation_positive_z_) {
      ang_rot_x += imu.angular_velocity.x;
      ang_rot_y += imu.angular_velocity.y;
      ang_rot_z += imu.angular_velocity.z;
    }

    ang_rot_x = (ang_rot_x / imu_rotation_positive_z_.size()) - ang_bias_x;
    ang_rot_y = (ang_rot_y / imu_rotation_positive_z_.size()) - ang_bias_y;
    ang_rot_z = (ang_rot_z / imu_rotation_positive_z_.size()) - ang_bias_z;

    double ang_z2x_proj = -ang_rot_x / ang_rot_z;
    double ang_z2y_proj = -ang_rot_y / ang_rot_z;

    // Log values
    RCLCPP_INFO(this->get_logger(), "--- CALIBRATION RESULTS ---");
    RCLCPP_INFO(this->get_logger(), "Acc Bias X: %.6f, Y: %.6f, Z: %.6f", acc_bias_x, acc_bias_y, acc_bias_z);
    RCLCPP_INFO(this->get_logger(), "Ang Bias X: %.6f, Y: %.6f, Z: %.6f", ang_bias_x, ang_bias_y, ang_bias_z);
    RCLCPP_INFO(this->get_logger(), "Z-axis Projection X: %.6f, Y: %.6f", ang_z2x_proj, ang_z2y_proj);

    SerializeResults(acc_bias_x, acc_bias_y, acc_bias_z, ang_bias_x, ang_bias_y, ang_bias_z, ang_z2x_proj, ang_z2y_proj);
  }

  void SerializeResults(double ax, double ay, double az, double gx, double gy, double gz, double px, double py)
  {
    try {
      std::filesystem::create_directories(log_dir_);

      std::time_t t = std::time(nullptr);
      std::tm tm = *std::localtime(&t);
      std::ostringstream oss;
      oss << log_dir_ << "/calib_" << std::put_time(&tm, "%Y_%m_%d") << ".yaml";
      std::string log_file = oss.str();

      std::ofstream file(log_file, std::ios::out);
      if (!file.is_open()) {
        RCLCPP_ERROR(this->get_logger(), "Failed to open calibration log file: %s", log_file.c_str());
        return;
      }

      file << "# Unitree Go2 Sensor Daily Calibration Parameters" << std::endl;
      file << "timestamp: " << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S") << std::endl;
      file << "acc_bias_x: " << ax << std::endl;
      file << "acc_bias_y: " << ay << std::endl;
      file << "acc_bias_z: " << az << std::endl;
      file << "ang_bias_x: " << gx << std::endl;
      file << "ang_bias_y: " << gy << std::endl;
      file << "ang_bias_z: " << gz << std::endl;
      file << "ang_z2x_proj: " << px << std::endl;
      file << "ang_z2y_proj: " << py << std::endl;
      file.close();

      RCLCPP_INFO(this->get_logger(), "Calibration results written to: %s", log_file.c_str());
    } catch (const std::exception& e) {
      RCLCPP_ERROR(this->get_logger(), "Failed to write calibration results: %s", e.what());
    }
  }

  std::string config_path_;
  std::string log_dir_;
  double theta_;

  int state_;
  bool file_written_;
  std::chrono::system_clock::time_point beginning_time_;

  std::vector<sensor_msgs::msg::Imu> imu_static_;
  std::vector<sensor_msgs::msg::Imu> imu_rotation_positive_z_;

  rclcpp::Publisher<unitree_api::msg::Request>::SharedPtr pub_sport_request_;
  rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr pub_cmd_vel_;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr sub_imu_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SensorCalibrationNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
