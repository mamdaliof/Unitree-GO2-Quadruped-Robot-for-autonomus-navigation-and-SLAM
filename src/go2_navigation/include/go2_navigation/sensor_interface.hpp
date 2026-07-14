#ifndef GO2_NAVIGATION__SENSOR_INTERFACE_HPP_
#define GO2_NAVIGATION__SENSOR_INTERFACE_HPP_

#include <string>
#include <memory>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <sensor_msgs/msg/imu.hpp>

namespace go2_navigation
{

/**
 * @brief Abstract base class representing a generic sensor.
 */
class SensorInterface
{
public:
  using SharedPtr = std::shared_ptr<SensorInterface>;

  /**
   * @brief Virtual destructor.
   */
  virtual ~SensorInterface() = default;

  /**
   * @brief Initialize the sensor device.
   * @return true if initialization succeeded, false otherwise.
   */
  virtual bool Init() = 0;

  /**
   * @brief Start streaming sensor data.
   * @return true if streaming started successfully.
   */
  virtual bool Start() = 0;

  /**
   * @brief Stop streaming sensor data.
   * @return true if streaming stopped successfully.
   */
  virtual bool Stop() = 0;

  /**
   * @brief Check if the sensor stream is active.
   * @return true if active, false otherwise.
   */
  virtual bool IsActive() const = 0;

  /**
   * @brief Get the name of the sensor.
   * @return String representing the sensor name.
   */
  virtual std::string GetSensorName() const = 0;

  /**
   * @brief Get the type of the sensor (e.g., "lidar", "imu", "camera").
   * @return String representing the sensor type.
   */
  virtual std::string GetSensorType() const = 0;
};

/**
 * @brief Abstract sub-interface representing a LiDAR sensor.
 */
class LidarInterface : public SensorInterface
{
public:
  using SharedPtr = std::shared_ptr<LidarInterface>;

  /**
   * @brief Retrieve the latest point cloud sweep.
   * @param cloud Output parameter to populate with point cloud data.
   * @return true if data was retrieved successfully.
   */
  virtual bool GetPointCloud(sensor_msgs::msg::PointCloud2 & cloud) = 0;

  /**
   * @brief Apply self-filtering on point clouds to remove chassis and leg reflections.
   * @param input Raw input point cloud.
   * @param output Filtered output point cloud.
   * @return true if filtering succeeded.
   */
  virtual bool ApplySelfFilter(
    const sensor_msgs::msg::PointCloud2 & input,
    sensor_msgs::msg::PointCloud2 & output) = 0;
};

/**
 * @brief Abstract sub-interface representing an IMU sensor.
 */
class ImuInterface : public SensorInterface
{
public:
  using SharedPtr = std::shared_ptr<ImuInterface>;

  /**
   * @brief Retrieve the latest IMU data reading.
   * @param imu Output parameter to populate with IMU data.
   * @return true if data was retrieved successfully.
   */
  virtual bool GetIMUData(sensor_msgs::msg::Imu & imu) = 0;
};

}  // namespace go2_navigation

#endif  // GO2_NAVIGATION__SENSOR_INTERFACE_HPP_
