#include <go2_sensors/l2_lidar.hpp>

namespace go2_sensors
{

L2Lidar::L2Lidar(rclcpp::Node::SharedPtr node, const std::string& input_topic)
  : node_(node), input_topic_(input_topic), is_active_(false) {}

bool L2Lidar::Init()
{
  RCLCPP_INFO(node_->get_logger(), "Initializing L2 Lidar on input topic: %s", input_topic_.c_str());
  return true;
}

bool L2Lidar::Start()
{
  if (is_active_) {
    return true;
  }
  RCLCPP_INFO(node_->get_logger(), "Starting L2 Lidar subscriber");
  sub_ = node_->create_subscription<sensor_msgs::msg::PointCloud2>(
    input_topic_,
    10,
    std::bind(&L2Lidar::LidarCallback, this, std::placeholders::_1)
  );
  is_active_ = true;
  return true;
}

bool L2Lidar::Stop()
{
  if (!is_active_) {
    return true;
  }
  RCLCPP_INFO(node_->get_logger(), "Stopping L2 Lidar subscriber");
  sub_.reset();
  is_active_ = false;
  return true;
}

bool L2Lidar::IsActive() const
{
  return is_active_;
}

std::string L2Lidar::GetSensorName() const
{
  return "L2Lidar";
}

std::string L2Lidar::GetSensorType() const
{
  return "lidar";
}

void L2Lidar::SetCallback(std::function<void(const sensor_msgs::msg::PointCloud2::SharedPtr)> callback)
{
  callback_ = callback;
}

void L2Lidar::LidarCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{
  if (callback_) {
    callback_(msg);
  }
}

}  // namespace go2_sensors

