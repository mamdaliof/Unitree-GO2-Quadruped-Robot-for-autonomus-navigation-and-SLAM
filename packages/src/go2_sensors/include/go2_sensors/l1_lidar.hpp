#ifndef GO2_SENSORS__L1_LIDAR_HPP_
#define GO2_SENSORS__L1_LIDAR_HPP_

#include <go2_navigation/sensor_interface.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <functional>

namespace go2_sensors
{

class L1Lidar : public go2_navigation::SensorInterface
{
public:
  L1Lidar(rclcpp::Node::SharedPtr node, const std::string& input_topic);
  virtual ~L1Lidar() = default;

  bool Init() override;
  bool Start() override;
  bool Stop() override;
  bool IsActive() const override;
  std::string GetSensorName() const override;
  std::string GetSensorType() const override;

  void SetCallback(std::function<void(const sensor_msgs::msg::PointCloud2::SharedPtr)> callback);

private:
  void LidarCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg);

  rclcpp::Node::SharedPtr node_;
  std::string input_topic_;
  bool is_active_;
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr sub_;
  std::function<void(const sensor_msgs::msg::PointCloud2::SharedPtr)> callback_;
};

}  // namespace go2_sensors

#endif  // GO2_SENSORS__L1_LIDAR_HPP_

