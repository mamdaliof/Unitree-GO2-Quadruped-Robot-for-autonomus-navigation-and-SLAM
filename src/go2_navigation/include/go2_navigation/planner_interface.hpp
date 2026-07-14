#ifndef GO2_NAVIGATION__PLANNER_INTERFACE_HPP_
#define GO2_NAVIGATION__PLANNER_INTERFACE_HPP_

#include <vector>
#include <memory>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <nav_msgs/msg/path.hpp>

namespace go2_navigation
{

/**
 * @brief Abstract base class representing the path planning and exploration module.
 */
class PlannerInterface
{
public:
  using SharedPtr = std::shared_ptr<PlannerInterface>;

  /**
   * @brief Virtual destructor.
   */
  virtual ~PlannerInterface() = default;

  /**
   * @brief Initialize planner config parameters.
   * @return true if initialization succeeded, false otherwise.
   */
  virtual bool Init() = 0;

  /**
   * @brief Update the planner's internal tracking of the robot's current pose.
   * @param pose The latest localized pose of the robot.
   */
  virtual void UpdatePose(const geometry_msgs::msg::PoseStamped & pose) = 0;

  /**
   * @brief Update the planner's global grid map layout representation.
   * @param map The latest global occupancy grid map.
   */
  virtual void UpdateGridMap(const nav_msgs::msg::OccupancyGrid & map) = 0;

  /**
   * @brief Update the costmap using a point cloud feed (for obstacle clearance layers).
   * @param cloud Input point cloud sweep.
   * @return true if costmap was successfully updated.
   */
  virtual bool UpdateCostmap(const sensor_msgs::msg::PointCloud2 & cloud) = 0;

  /**
   * @brief Compute a collision-free global path from start to goal coordinates.
   * @param start The starting pose coordinate.
   * @param goal The target goal pose coordinate.
   * @param path Output parameter populated with computed waypoints path.
   * @return true if a valid path was generated.
   */
  virtual bool ComputeGlobalPath(
    const geometry_msgs::msg::PoseStamped & start,
    const geometry_msgs::msg::PoseStamped & goal,
    nav_msgs::msg::Path & path) = 0;

  /**
   * @brief Compute local velocity commands to follow an active path.
   * @param current_pose The active localized pose of the robot.
   			* @param path The global path to follow.
   * @param cmd_vel Output parameter populated with local velocity command.
   * @return true if a valid local velocity was generated.
   */
  virtual bool ComputeLocalVelocity(
    const geometry_msgs::msg::PoseStamped & current_pose,
    const nav_msgs::msg::Path & path,
    geometry_msgs::msg::TwistStamped & cmd_vel) = 0;

  /**
   * @brief Generate a list of potential frontier goals for autonomous exploration.
   * @param frontier_goals Output vector populated with generated frontier coordinates.
   * @return true if frontier goals were successfully identified.
   */
  virtual bool GenerateFrontierGoals(
    std::vector<geometry_msgs::msg::PoseStamped> & frontier_goals) = 0;

  /**
   * @brief Filter goal candidates based on the forward field of view limit preferences.
   * @param goals Input list of goal candidates.
   * @param filtered_goals Output list of goals satisfying FOV criteria.
   * @return true if filtering executed without errors.
   */
  virtual bool FilterGoalsByFOV(
    const std::vector<geometry_msgs::msg::PoseStamped> & goals,
    std::vector<geometry_msgs::msg::PoseStamped> & filtered_goals) = 0;
};

}  // namespace go2_navigation

#endif  // GO2_NAVIGATION__PLANNER_INTERFACE_HPP_
