#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <go2_sensors/lidar.hpp>
#include <go2_sensors/robot_imu.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <memory>
#include <filesystem>

using json = nlohmann::json;

/**
 * @brief Search upward from current working directory and executable path
 * to find the go2_config.json file.
 * @param exec_path The path to the executable (argv[0]).
 * @return The absolute path to the configuration file, or fallback default path.
 */
std::string findConfigPath(const std::string& exec_path)
{
  namespace fs = std::filesystem;
  try {
    // 1. Try search upward from current working directory
    fs::path cwd = fs::current_path();
    for (int i = 0; i < 6; ++i) {
      fs::path check_path = cwd / "go2_config.json";
      if (fs::exists(check_path)) {
        return fs::absolute(check_path).string();
      }
      if (!cwd.has_parent_path() || cwd == cwd.parent_path()) {
        break;
      }
      cwd = cwd.parent_path();
    }

    // 2. Try search upward from executable directory
    if (!exec_path.empty()) {
      fs::path exec_dir = fs::absolute(exec_path).parent_path();
      for (int i = 0; i < 6; ++i) {
        fs::path check_path = exec_dir / "go2_config.json";
        if (fs::exists(check_path)) {
          return fs::absolute(check_path).string();
        }
        if (!exec_dir.has_parent_path() || exec_dir == exec_dir.parent_path()) {
          break;
        }
        exec_dir = exec_dir.parent_path();
      }
    }
  } catch (const std::exception&) {
    // Fallback to default
  }

  // Fallback to absolute path on developer PC
  return "/home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/go2_config.json";
}

/**
 * @brief Helper utility to parse configuration settings from the go2_config.json file
 * using the nlohmann/json library.
 */
class SimpleConfig
{
public:
  /**
   * @brief Reads a nested string value from the JSON configuration file.
   * @param filepath Absolute path to the JSON configuration file.
   * @param section The root key / section name (e.g. "nodes", "topics").
   * @param key The sub-key / variable name (e.g. "sensor_publisher_node_name").
   * @param default_val The fallback value if key or file is missing.
   * @return The configuration value as a string.
   */
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
      // Fallback to default on parse errors or file issues
    }
    return default_val;
  }
};

/**
 * @brief ROS 2 Node that manages the physical sensor drivers and republishes
 * their telemetry data to standardized ROS 2 topics.
 */
class SensorPublisherNode : public rclcpp::Node
{
public:
  /**
   * @brief Construct the node, load configurations, and initialize publishers.
   * @param node_name The name of the node.
   */
  SensorPublisherNode(const std::string& node_name)
    : Node(node_name)
  {
    RCLCPP_INFO(this->get_logger(), "Starting SensorPublisherNode: %s", node_name.c_str());

    // Declare and retrieve the parameter for the configuration file path
    this->declare_parameter<std::string>("config_path", "");
    config_path_ = this->get_parameter("config_path").as_string();

    // Fallback if no parameter was passed via launch file or CLI
    if (config_path_.empty()) {
      config_path_ = findConfigPath("");
      RCLCPP_WARN(this->get_logger(), "No config_path parameter specified. Found fallback path: %s", config_path_.c_str());
    } else {
      RCLCPP_INFO(this->get_logger(), "Using config path parameter: %s", config_path_.c_str());
    }

    // Retrieve topic mapping configurations
    std::string l1_output = SimpleConfig::getValue(config_path_, "topics", "l1_lidar_output", "/go2/l1_lidar");
    std::string l2_output = SimpleConfig::getValue(config_path_, "topics", "l2_lidar_output", "/go2/l2_lidar");
    std::string imu_output = SimpleConfig::getValue(config_path_, "topics", "imu_output", "/go2/imu");

    // Initialize publishers
    l1_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>(l1_output, 10);
    l2_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>(l2_output, 10);
    imu_pub_ = this->create_publisher<sensor_msgs::msg::Imu>(imu_output, 50);
  }

  /**
   * @brief Initialize and start the underlying sensor driver subscriber callbacks.
   */
  void InitializeSensors()
  {
    auto shared_node = shared_from_this();
    std::string l1_input = SimpleConfig::getValue(config_path_, "topics", "l1_lidar_input", "/utlidar/cloud");
    std::string l2_input = SimpleConfig::getValue(config_path_, "topics", "l2_lidar_input", "/utlidar/cloud_l2");
    std::string imu_input = SimpleConfig::getValue(config_path_, "topics", "imu_input", "/utlidar/imu");

    // Instantiate LiDARs using the unified Lidar class
    l1_lidar_ = std::make_unique<go2_sensors::Lidar>(shared_node, "L1Lidar", l1_input);
    l2_lidar_ = std::make_unique<go2_sensors::Lidar>(shared_node, "L2Lidar", l2_input);
    robot_imu_ = std::make_unique<go2_sensors::RobotImu>(shared_node, imu_input);

    // Register forwarding callbacks to publish the data
    l1_lidar_->SetCallback([this](const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
      l1_pub_->publish(*msg);
    });

    l2_lidar_->SetCallback([this](const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
      l2_pub_->publish(*msg);
    });

    robot_imu_->SetCallback([this](const sensor_msgs::msg::Imu::SharedPtr msg) {
      imu_pub_->publish(*msg);
    });

    // Initialize and start the driver streams
    l1_lidar_->Init();
    l2_lidar_->Init();
    robot_imu_->Init();

    l1_lidar_->Start();
    l2_lidar_->Start();
    robot_imu_->Start();
  }

  ~SensorPublisherNode()
  {
    // Stop all streaming interfaces on shutdown
    if (l1_lidar_) l1_lidar_->Stop();
    if (l2_lidar_) l2_lidar_->Stop();
    if (robot_imu_) robot_imu_->Stop();
  }

private:
  std::string config_path_;
  std::unique_ptr<go2_sensors::Lidar> l1_lidar_;
  std::unique_ptr<go2_sensors::Lidar> l2_lidar_;
  std::unique_ptr<go2_sensors::RobotImu> robot_imu_;

  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr l1_pub_;
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr l2_pub_;
  rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);

  // Default node name; can be overridden in launch description or via __node mapping
  auto node = std::make_shared<SensorPublisherNode>("go2_sensor_publisher");
  node->InitializeSensors();

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
