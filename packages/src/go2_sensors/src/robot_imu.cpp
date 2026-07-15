#include <go2_sensors/robot_imu.hpp>

namespace go2_sensors
{

RobotImu::RobotImu(rclcpp::Node::SharedPtr node, const std::string& input_topic)
  : node_(node), input_topic_(input_topic), is_active_(false) {}

bool RobotImu::Init()
{
  RCLCPP_INFO(node_->get_logger(), "Initializing Robot IMU on input topic: %s", input_topic_.c_str());
  return true;
}

bool RobotImu::Start()
{
  if (is_active_) {
    return true;
  }
  RCLCPP_INFO(node_->get_logger(), "Starting Robot IMU subscriber");
  sub_ = node_->create_subscription<sensor_msgs::msg::Imu>(
    input_topic_,
    50,
    std::bind(&RobotImu::ImuCallback, this, std::placeholders::_1)
  );
  is_active_ = true;
  return true;
}

bool RobotImu::Stop()
{
  if (!is_active_) {
    return true;
  }
  RCLCPP_INFO(node_->get_logger(), "Stopping Robot IMU subscriber");
  sub_.reset();
  is_active_ = false;
  return true;
}

bool RobotImu::IsActive() const
{
  return is_active_;
}

std::string RobotImu::GetSensorName() const
{
  return "RobotImu";
}

std::string RobotImu::GetSensorType() const
{
  return "imu";
}

void RobotImu::SetCallback(std::function<void(const sensor_msgs::msg::Imu::SharedPtr)> callback)
{
  callback_ = callback;
}

/**
 * @brief This callback function is triggered whenever an IMU message
 * is received on the configured IMU input topic. It forwards the
 * received telemetry data to the registered subscriber callback.
 * 
 * @param msg The shared pointer to the received IMU message.
 */
void RobotImu::ImuCallback(const sensor_msgs::msg::Imu::SharedPtr msg)
{
  // Forward the message to the registered callback if it has been set
  if (callback_) {
    callback_(msg);
  }
}

}  // namespace go2_sensors

