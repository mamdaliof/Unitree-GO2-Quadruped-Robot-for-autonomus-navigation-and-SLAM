#ifndef GO2_NAVIGATION__SLAM_INTERFACE_HPP_
#define GO2_NAVIGATION__SLAM_INTERFACE_HPP_

#include <string>
#include <memory>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>

namespace go2_navigation
{

/**
 * @brief Abstract base class representing the SLAM mapping and localization module.
 */
class SLAMInterface
{
public:
  using SharedPtr = std::shared_ptr<SLAMInterface>;

  /**
   * @brief Virtual destructor.
   */
  virtual ~SLAMInterface() = default;

  /**
   * @brief Initialize the SLAM estimators and coordinate trees.
   * @return true if initialization succeeded, false otherwise.
   */
  virtual bool Init() = 0;

  /**
   * @brief Start the mapping (SLAM map construction) process.
   * @return true if mapping started successfully.
   */
  virtual bool StartMapping() = 0;

  /**
   * @brief Stop the mapping process.
   * @return true if mapping stopped successfully.
   */
  virtual bool StopMapping() = 0;

  /**
   * @brief Save the constructed map to a file.
   * @param path File system destination path (e.g., "/home/unitree/map.pcd").
   * @return true if map was saved successfully.
   */
  virtual bool SaveMap(const std::string & path) = 0;

  /**
   * @brief Load a pre-existing map for localization.
   * @param path File system path to the map.
   * @return true if map loaded successfully.
   */
  virtual bool LoadMap(const std::string & path) = 0;

  /**
   * @brief Update the active map representation using a new point cloud sweep.
   * @param cloud Input point cloud sweep.
   * @return true if map representation updated successfully.
   */
  virtual bool UpdateMap(const sensor_msgs::msg::PointCloud2 & cloud) = 0;

  /**
   * @brief Localize the robot within the loaded map.
   * @param pose Output parameter populated with current 6-DoF global pose.
   * @return true if localization succeeded and pose is valid.
   */
  virtual bool Localize(geometry_msgs::msg::PoseStamped & pose) = 0;

  /**
   * @brief Check if the robot has been kidnapped (slipped or manual relocation mismatch).
   * @return true if a kidnap state is detected.
   */
  virtual bool CheckKidnapStatus() = 0;
};

}  // namespace go2_navigation

#endif  // GO2_NAVIGATION__SLAM_INTERFACE_HPP_
