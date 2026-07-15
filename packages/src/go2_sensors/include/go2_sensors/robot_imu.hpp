#ifndef GO2_SENSORS__ROBOT_IMU_HPP_
#define GO2_SENSORS__ROBOT_IMU_HPP_

#include <go2_navigation/sensor_interface.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <functional>

namespace go2_sensors
{

class RobotImu : public go2_navigation::SensorInterface
{
public:
  RobotImu(rclcpp::Node::SharedPtr node, const std::string& input_topic);
  virtual ~RobotImu() = default;

  bool Init() override;
  bool Start() override;
  bool Stop() override;
  bool IsActive() const override;
  std::string GetSensorName() const override;
  std::string GetSensorType() const override;

  void SetCallback(std::function<void(const sensor_msgs::msg::Imu::SharedPtr)> callback);

private:
  void ImuCallback(const sensor_msgs::msg::Imu::SharedPtr msg);

  rclcpp::Node::SharedPtr node_;
  std::string input_topic_;
  bool is_active_;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr sub_;
  std::function<void(const sensor_msgs::msg::Imu::SharedPtr)> callback_;
};

}  // namespace go2_sensors

#endif  // GO2_SENSORS__ROBOT_IMU_HPP_

