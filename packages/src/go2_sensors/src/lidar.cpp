#include <go2_sensors/lidar.hpp>

namespace go2_sensors
{

Lidar::Lidar(rclcpp::Node::SharedPtr node, const std::string& sensor_name, const std::string& input_topic)
  : node_(node), sensor_name_(sensor_name), input_topic_(input_topic), is_active_(false) {}

bool Lidar::Init()
{
  RCLCPP_INFO(node_->get_logger(), "Initializing %s on input topic: %s", sensor_name_.c_str(), input_topic_.c_str());
  return true;
}

bool Lidar::Start()
{
  if (is_active_) {
    return true;
  }
  RCLCPP_INFO(node_->get_logger(), "Starting %s subscriber", sensor_name_.c_str());
  sub_ = node_->create_subscription<sensor_msgs::msg::PointCloud2>(
    input_topic_,
    10,
    std::bind(&Lidar::LidarCallback, this, std::placeholders::_1)
  );
  is_active_ = true;
  return true;
}

bool Lidar::Stop()
{
  if (!is_active_) {
    return true;
  }
  RCLCPP_INFO(node_->get_logger(), "Stopping %s subscriber", sensor_name_.c_str());
  sub_.reset();
  is_active_ = false;
  return true;
}

bool Lidar::IsActive() const
{
  return is_active_;
}

std::string Lidar::GetSensorName() const
{
  return sensor_name_;
}

std::string Lidar::GetSensorType() const
{
  return "lidar";
}

void Lidar::SetCallback(std::function<void(const sensor_msgs::msg::PointCloud2::SharedPtr)> callback)
{
  callback_ = callback;
}

/**
 * @brief This callback function is triggered whenever a PointCloud2 message
 * is received on the configured LiDAR input topic. It performs minimal checks
 * and forwards the point cloud data to the registered subscriber callback.
 * 
 * @param msg The shared pointer to the received PointCloud2 message.
 */
void Lidar::LidarCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{
  // Forward the message to the registered callback if it has been set
  if (callback_) {
    callback_(msg);
  }
}

}  // namespace go2_sensors
