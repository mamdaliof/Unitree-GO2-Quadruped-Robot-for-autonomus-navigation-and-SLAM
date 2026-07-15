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

    // Read LiDAR tilt angles to calculate thetas
    double tilt_deg_l1 = SimpleConfig::getDoubleValue(config_path_, "sensors", "l1_lidar_tilt_angle_deg", 13.0);
    double tilt_deg_l2 = SimpleConfig::getDoubleValue(config_path_, "sensors", "l2_lidar_tilt_angle_deg", 15.0);
    theta_l1_ = tilt_deg_l1 * M_PI / 180.0;
    theta_l2_ = tilt_deg_l2 * M_PI / 180.0;

    RCLCPP_INFO(this->get_logger(), "Starting sensor calibration.");
    RCLCPP_INFO(this->get_logger(), "L1 LiDAR tilt angle: %.2f deg (theta_l1 = %.4f rad)", tilt_deg_l1, theta_l1_);
    RCLCPP_INFO(this->get_logger(), "L2 LiDAR tilt angle: %.2f deg (theta_l2 = %.4f rad)", tilt_deg_l2, theta_l2_);

    // Read configured topics
    std::string imu1_topic = SimpleConfig::getValue(config_path_, "topics", "l1_imu_input", "/utlidar/imu");
    std::string imu2_topic = SimpleConfig::getValue(config_path_, "topics", "l2_imu_input", "/utlidar/imu_l2");

    // Initialize publishers and subscribers
    pub_sport_request_ = this->create_publisher<unitree_api::msg::Request>("/api/sport/request", 10);
    pub_cmd_vel_ = this->create_publisher<geometry_msgs::msg::TwistStamped>("/cmd_vel", 5);

    if (!imu1_topic.empty()) {
      RCLCPP_INFO(this->get_logger(), "Subscribing to L1 IMU: %s", imu1_topic.c_str());
      sub_imu_l1_ = this->create_subscription<sensor_msgs::msg::Imu>(
        imu1_topic, 300, std::bind(&SensorCalibrationNode::Imu1Callback, this, std::placeholders::_1)
      );
    }

    if (!imu2_topic.empty()) {
      RCLCPP_INFO(this->get_logger(), "Subscribing to L2 IMU: %s", imu2_topic.c_str());
      sub_imu_l2_ = this->create_subscription<sensor_msgs::msg::Imu>(
        imu2_topic, 300, std::bind(&SensorCalibrationNode::Imu2Callback, this, std::placeholders::_1)
      );
    }

    beginning_time_ = std::chrono::system_clock::now();

    // Run calibration timer loop at 100 Hz
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(10), std::bind(&SensorCalibrationNode::TimerCallback, this)
    );
  }

private:
  void ProcessImuData(const sensor_msgs::msg::Imu::ConstSharedPtr msg_in, double theta, 
                      std::vector<sensor_msgs::msg::Imu>& static_vec, 
                      std::vector<sensor_msgs::msg::Imu>& rot_vec)
  {
    // Coordinates conversion to Z-up base frame (pitch rotation by theta about Y-axis)
    double x = msg_in->angular_velocity.x;
    double y = -msg_in->angular_velocity.y;
    double z = -msg_in->angular_velocity.z;

    double x2 = x * cos(theta) - z * sin(theta);
    double y2 = y;
    double z2 = x * sin(theta) + z * cos(theta);

    double acc_x = msg_in->linear_acceleration.x;
    double acc_y = -msg_in->linear_acceleration.y;
    double acc_z = -msg_in->linear_acceleration.z;

    double acc_x2 = acc_x * cos(theta) - acc_z * sin(theta);
    double acc_y2 = acc_y;
    double acc_z2 = acc_x * sin(theta) + acc_z * cos(theta);

    sensor_msgs::msg::Imu msg_store = *msg_in;
    msg_store.angular_velocity.x = x2;
    msg_store.angular_velocity.y = y2;
    msg_store.angular_velocity.z = z2;
    msg_store.linear_acceleration.x = acc_x2;
    msg_store.linear_acceleration.y = acc_y2;
    msg_store.linear_acceleration.z = acc_z2;

    if (state_ == 1) {
      static_vec.push_back(msg_store);
    } else if (state_ == 2) {
      rot_vec.push_back(msg_store);
    }
  }

  void Imu1Callback(const sensor_msgs::msg::Imu::ConstSharedPtr msg_in)
  {
    ProcessImuData(msg_in, theta_l1_, imu1_static_, imu1_rotation_positive_z_);
  }

  void Imu2Callback(const sensor_msgs::msg::Imu::ConstSharedPtr msg_in)
  {
    ProcessImuData(msg_in, theta_l2_, imu2_static_, imu2_rotation_positive_z_);
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
      ComputeCalibrationAll();
      file_written_ = true;
      RCLCPP_INFO(this->get_logger(), "Calibration node complete. Shutting down.");
      rclcpp::shutdown();
    }
  }

  struct CalibrationResult {
    bool valid = false;
    double acc_bias_x = 0;
    double acc_bias_y = 0;
    double acc_bias_z = 0;
    double ang_bias_x = 0;
    double ang_bias_y = 0;
    double ang_bias_z = 0;
    double ang_z2x_proj = 0;
    double ang_z2y_proj = 0;
  };

  CalibrationResult CalibrateSensor(const std::vector<sensor_msgs::msg::Imu>& static_data,
                                    const std::vector<sensor_msgs::msg::Imu>& rot_data,
                                    const std::string& name)
  {
    CalibrationResult res;
    if (static_data.empty() || rot_data.empty()) {
      RCLCPP_WARN(this->get_logger(), "IMU %s has insufficient data. Skipping. Static: %zu, Rot: %zu",
                  name.c_str(), static_data.size(), rot_data.size());
      return res;
    }

    for (const auto& imu : static_data) {
      res.acc_bias_x += imu.linear_acceleration.x;
      res.acc_bias_y += imu.linear_acceleration.y;
      res.acc_bias_z += imu.linear_acceleration.z;
      res.ang_bias_x += imu.angular_velocity.x;
      res.ang_bias_y += imu.angular_velocity.y;
      res.ang_bias_z += imu.angular_velocity.z;
    }

    res.acc_bias_x /= static_data.size();
    res.acc_bias_y /= static_data.size();
    res.acc_bias_z /= static_data.size();
    res.ang_bias_x /= static_data.size();
    res.ang_bias_y /= static_data.size();
    res.ang_bias_z /= static_data.size();

    // Subtract gravity constant from Z bias
    res.acc_bias_z -= 9.81;

    double ang_rot_x = 0;
    double ang_rot_y = 0;
    double ang_rot_z = 0;

    for (const auto& imu : rot_data) {
      ang_rot_x += imu.angular_velocity.x;
      ang_rot_y += imu.angular_velocity.y;
      ang_rot_z += imu.angular_velocity.z;
    }

    ang_rot_x = (ang_rot_x / rot_data.size()) - res.ang_bias_x;
    ang_rot_y = (ang_rot_y / rot_data.size()) - res.ang_bias_y;
    ang_rot_z = (ang_rot_z / rot_data.size()) - res.ang_bias_z;

    if (std::abs(ang_rot_z) > 1e-4) {
      res.ang_z2x_proj = -ang_rot_x / ang_rot_z;
      res.ang_z2y_proj = -ang_rot_y / ang_rot_z;
      res.valid = true;
    } else {
      RCLCPP_ERROR(this->get_logger(), "IMU %s rotation velocity in Z-axis is too low (%.4f rad/s). Cannot calibrate alignment.", 
                   name.c_str(), ang_rot_z);
    }

    return res;
  }

  void ComputeCalibrationAll()
  {
    CalibrationResult calib_l1 = CalibrateSensor(imu1_static_, imu1_rotation_positive_z_, "L1");
    CalibrationResult calib_l2 = CalibrateSensor(imu2_static_, imu2_rotation_positive_z_, "L2");

    // Print results
    if (calib_l1.valid) {
      RCLCPP_INFO(this->get_logger(), "--- L1 IMU CALIBRATION RESULTS ---");
      RCLCPP_INFO(this->get_logger(), "Acc Bias X: %.6f, Y: %.6f, Z: %.6f", calib_l1.acc_bias_x, calib_l1.acc_bias_y, calib_l1.acc_bias_z);
      RCLCPP_INFO(this->get_logger(), "Ang Bias X: %.6f, Y: %.6f, Z: %.6f", calib_l1.ang_bias_x, calib_l1.ang_bias_y, calib_l1.ang_bias_z);
      RCLCPP_INFO(this->get_logger(), "Z-axis Projection X: %.6f, Y: %.6f", calib_l1.ang_z2x_proj, calib_l1.ang_z2y_proj);
    }
    if (calib_l2.valid) {
      RCLCPP_INFO(this->get_logger(), "--- L2 IMU CALIBRATION RESULTS ---");
      RCLCPP_INFO(this->get_logger(), "Acc Bias X: %.6f, Y: %.6f, Z: %.6f", calib_l2.acc_bias_x, calib_l2.acc_bias_y, calib_l2.acc_bias_z);
      RCLCPP_INFO(this->get_logger(), "Ang Bias X: %.6f, Y: %.6f, Z: %.6f", calib_l2.ang_bias_x, calib_l2.ang_bias_y, calib_l2.ang_bias_z);
      RCLCPP_INFO(this->get_logger(), "Z-axis Projection X: %.6f, Y: %.6f", calib_l2.ang_z2x_proj, calib_l2.ang_z2y_proj);
    }

    SerializeResultsAll(calib_l1, calib_l2);
  }

  void SerializeResultsAll(const CalibrationResult& cal1, const CalibrationResult& cal2)
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

      if (cal1.valid) {
        file << "l1_imu:" << std::endl;
        file << "  acc_bias_x: " << cal1.acc_bias_x << std::endl;
        file << "  acc_bias_y: " << cal1.acc_bias_y << std::endl;
        file << "  acc_bias_z: " << cal1.acc_bias_z << std::endl;
        file << "  ang_bias_x: " << cal1.ang_bias_x << std::endl;
        file << "  ang_bias_y: " << cal1.ang_bias_y << std::endl;
        file << "  ang_bias_z: " << cal1.ang_bias_z << std::endl;
        file << "  ang_z2x_proj: " << cal1.ang_z2x_proj << std::endl;
        file << "  ang_z2y_proj: " << cal1.ang_z2y_proj << std::endl;
      }

      if (cal2.valid) {
        file << "l2_imu:" << std::endl;
        file << "  acc_bias_x: " << cal2.acc_bias_x << std::endl;
        file << "  acc_bias_y: " << cal2.acc_bias_y << std::endl;
        file << "  acc_bias_z: " << cal2.acc_bias_z << std::endl;
        file << "  ang_bias_x: " << cal2.ang_bias_x << std::endl;
        file << "  ang_bias_y: " << cal2.ang_bias_y << std::endl;
        file << "  ang_bias_z: " << cal2.ang_bias_z << std::endl;
        file << "  ang_z2x_proj: " << cal2.ang_z2x_proj << std::endl;
        file << "  ang_z2y_proj: " << cal2.ang_z2y_proj << std::endl;
      }

      file.close();
      RCLCPP_INFO(this->get_logger(), "Calibration results written to: %s", log_file.c_str());
    } catch (const std::exception& e) {
      RCLCPP_ERROR(this->get_logger(), "Failed to write calibration results: %s", e.what());
    }
  }

  std::string config_path_;
  std::string log_dir_;
  double theta_l1_;
  double theta_l2_;

  int state_;
  bool file_written_;
  std::chrono::system_clock::time_point beginning_time_;

  std::vector<sensor_msgs::msg::Imu> imu1_static_;
  std::vector<sensor_msgs::msg::Imu> imu1_rotation_positive_z_;
  std::vector<sensor_msgs::msg::Imu> imu2_static_;
  std::vector<sensor_msgs::msg::Imu> imu2_rotation_positive_z_;

  rclcpp::Publisher<unitree_api::msg::Request>::SharedPtr pub_sport_request_;
  rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr pub_cmd_vel_;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr sub_imu_l1_;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr sub_imu_l2_;
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
