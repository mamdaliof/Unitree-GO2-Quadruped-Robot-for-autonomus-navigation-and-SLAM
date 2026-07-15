#ifndef GO2_SENSORS__LIDAR_HPP_
#define GO2_SENSORS__LIDAR_HPP_

#include <go2_navigation/sensor_interface.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <functional>
#include <string>

namespace go2_sensors
{

/**
 * @brief Concrete implementation of SensorInterface representing a generic LiDAR.
 */
class Lidar : public go2_navigation::SensorInterface
{
public:
  /**
   * @brief Construct a new Lidar sensor.
   * @param node The shared pointer to the ROS 2 node.
   * @param sensor_name The name of the LiDAR sensor (e.g., L1Lidar, L2Lidar).
   * @param input_topic The ROS 2 topic name where the raw point cloud is received.
   */
  Lidar(rclcpp::Node::SharedPtr node, const std::string& sensor_name, const std::string& input_topic);
  virtual ~Lidar() = default;

  // SensorInterface implementation
  bool Init() override;
  bool Start() override;
  bool Stop() override;
  bool IsActive() const override;
  std::string GetSensorName() const override;
  std::string GetSensorType() const override;

  /**
   * @brief Register a callback to handle received point clouds.
   * @param callback Function to process the PointCloud2 message.
   */
  void SetCallback(std::function<void(const sensor_msgs::msg::PointCloud2::SharedPtr)> callback);

private:
  /**
   * @brief Callback function executed when point cloud data is received.
   */
  void LidarCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg);

  rclcpp::Node::SharedPtr node_;
  std::string sensor_name_;
  std::string input_topic_;
  bool is_active_;
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr sub_;
  std::function<void(const sensor_msgs::msg::PointCloud2::SharedPtr)> callback_;
};

}  // namespace go2_sensors

#endif  // GO2_SENSORS__LIDAR_HPP_
