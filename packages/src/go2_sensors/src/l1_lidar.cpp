#include <go2_sensors/l1_lidar.hpp>

namespace go2_sensors
{

L1Lidar::L1Lidar(rclcpp::Node::SharedPtr node, const std::string& input_topic)
  : node_(node), input_topic_(input_topic), is_active_(false) {}

bool L1Lidar::Init()
{
  RCLCPP_INFO(node_->get_logger(), "Initializing L1 Lidar on input topic: %s", input_topic_.c_str());
  return true;
}

bool L1Lidar::Start()
{
  if (is_active_) {
    return true;
  }
  RCLCPP_INFO(node_->get_logger(), "Starting L1 Lidar subscriber");
  sub_ = node_->create_subscription<sensor_msgs::msg::PointCloud2>(
    input_topic_,
    10,
    std::bind(&L1Lidar::LidarCallback, this, std::placeholders::_1)
  );
  is_active_ = true;
  return true;
}

bool L1Lidar::Stop()
{
  if (!is_active_) {
    return true;
  }
  RCLCPP_INFO(node_->get_logger(), "Stopping L1 Lidar subscriber");
  sub_.reset();
  is_active_ = false;
  return true;
}

bool L1Lidar::IsActive() const
{
  return is_active_;
}

std::string L1Lidar::GetSensorName() const
{
  return "L1Lidar";
}

std::string L1Lidar::GetSensorType() const
{
  return "lidar";
}

void L1Lidar::SetCallback(std::function<void(const sensor_msgs::msg::PointCloud2::SharedPtr)> callback)
{
  callback_ = callback;
}

void L1Lidar::LidarCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{
  if (callback_) {
    callback_(msg);
  }
}

}  // namespace go2_sensors

