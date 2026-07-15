#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <go2_sensors/l1_lidar.hpp>
#include <go2_sensors/l2_lidar.hpp>
#include <go2_sensors/robot_imu.hpp>
#include <fstream>
#include <string>
#include <memory>

class SimpleConfig
{
public:
  static std::string getValue(const std::string& filepath, const std::string& key, const std::string& default_val = "")
  {
    std::ifstream file(filepath);
    if (!file.is_open()) {
      return default_val;
    }
    std::string line;
    while (std::getline(file, line)) {
      size_t pos = line.find("\"" + key + "\"");
      if (pos != std::string::npos) {
        size_t colon_pos = line.find(":", pos);
        if (colon_pos != std::string::npos) {
          size_t start_quote = line.find("\"", colon_pos);
          if (start_quote != std::string::npos) {
            size_t end_quote = line.find("\"", start_quote + 1);
            if (end_quote != std::string::npos) {
              return line.substr(start_quote + 1, end_quote - start_quote - 1);
            }
          } else {
            size_t val_start = line.find_first_not_of(" \t:,", colon_pos + 1);
            size_t val_end = line.find_last_not_of(" \t,}");
            if (val_start != std::string::npos && val_end != std::string::npos && val_end >= val_start) {
              return line.substr(val_start, val_end - val_start + 1);
            }
          }
        }
      }
    }
    return default_val;
  }
};

class SensorPublisherNode : public rclcpp::Node
{
public:
  SensorPublisherNode(const std::string& node_name, const std::string& config_path)
    : Node(node_name), config_path_(config_path)
  {
    RCLCPP_INFO(this->get_logger(), "Starting SensorPublisherNode with name: %s", node_name.c_str());

    // Read topic configurations
    std::string l1_input = SimpleConfig::getValue(config_path_, "l1_lidar_input", "/utlidar/cloud");
    std::string l1_output = SimpleConfig::getValue(config_path_, "l1_lidar_output", "/go2/l1_lidar");
    std::string l2_input = SimpleConfig::getValue(config_path_, "l2_lidar_input", "/utlidar/cloud_l2");
    std::string l2_output = SimpleConfig::getValue(config_path_, "l2_lidar_output", "/go2/l2_lidar");
    std::string imu_input = SimpleConfig::getValue(config_path_, "imu_input", "/utlidar/imu");
    std::string imu_output = SimpleConfig::getValue(config_path_, "imu_output", "/go2/imu");

    // Initialize publishers
    l1_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>(l1_output, 10);
    l2_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>(l2_output, 10);
    imu_pub_ = this->create_publisher<sensor_msgs::msg::Imu>(imu_output, 50);

    // Instantiate sensors
    // Passing shared_from_this() requires the node to be fully constructed.
    // We will initialize them in a separate Init method.
  }

  void InitializeSensors()
  {
    auto shared_node = shared_from_this();
    std::string l1_input = SimpleConfig::getValue(config_path_, "l1_lidar_input", "/utlidar/cloud");
    std::string l2_input = SimpleConfig::getValue(config_path_, "l2_lidar_input", "/utlidar/cloud_l2");
    std::string imu_input = SimpleConfig::getValue(config_path_, "imu_input", "/utlidar/imu");

    l1_lidar_ = std::make_unique<go2_sensors::L1Lidar>(shared_node, l1_input);
    l2_lidar_ = std::make_unique<go2_sensors::L2Lidar>(shared_node, l2_input);
    robot_imu_ = std::make_unique<go2_sensors::RobotImu>(shared_node, imu_input);

    // Set callbacks
    l1_lidar_->SetCallback([this](const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
      l1_pub_->publish(*msg);
    });

    l2_lidar_->SetCallback([this](const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
      l2_pub_->publish(*msg);
    });

    robot_imu_->SetCallback([this](const sensor_msgs::msg::Imu::SharedPtr msg) {
      imu_pub_->publish(*msg);
    });

    // Lifecycle Init & Start
    l1_lidar_->Init();
    l2_lidar_->Init();
    robot_imu_->Init();

    l1_lidar_->Start();
    l2_lidar_->Start();
    robot_imu_->Start();
  }

  ~SensorPublisherNode()
  {
    if (l1_lidar_) l1_lidar_->Stop();
    if (l2_lidar_) l2_lidar_->Stop();
    if (robot_imu_) robot_imu_->Stop();
  }

private:
  std::string config_path_;
  std::unique_ptr<go2_sensors::L1Lidar> l1_lidar_;
  std::unique_ptr<go2_sensors::L2Lidar> l2_lidar_;
  std::unique_ptr<go2_sensors::RobotImu> robot_imu_;

  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr l1_pub_;
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr l2_pub_;
  rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);

  std::string config_path = "/home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/go2_config.json";
  std::string node_name = SimpleConfig::getValue(config_path, "sensor_publisher_node_name", "go2_sensor_publisher");

  auto node = std::make_shared<SensorPublisherNode>(node_name, config_path);
  node->InitializeSensors();

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
