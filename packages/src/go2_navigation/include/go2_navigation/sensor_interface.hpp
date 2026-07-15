#ifndef GO2_NAVIGATION__SENSOR_INTERFACE_HPP_
#define GO2_NAVIGATION__SENSOR_INTERFACE_HPP_

#include <memory>
#include <string>

namespace go2_navigation {

/**
 * @brief Abstract base class representing a generic sensor.
 */
class SensorInterface {
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
   * @return true if streaming started successfully, false otherwise.
   */
  virtual bool Start() = 0;

  /**
   * @brief Stop streaming sensor data.
   * @return true if streaming stopped successfully, false otherwise.
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

} // namespace go2_navigation

#endif // GO2_NAVIGATION__SENSOR_INTERFACE_HPP_
