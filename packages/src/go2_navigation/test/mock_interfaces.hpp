#ifndef GO2_NAVIGATION__MOCK_INTERFACES_HPP_
#define GO2_NAVIGATION__MOCK_INTERFACES_HPP_

#include <gmock/gmock.h>
#include <go2_navigation/robot_interface.hpp>
#include <go2_navigation/sensor_interface.hpp>
#include <go2_navigation/slam_interface.hpp>
#include <go2_navigation/planner_interface.hpp>

namespace go2_navigation
{
namespace test
{

/**
 * @brief Google Mock class for RobotInterface.
 */
class MockRobotInterface : public RobotInterface
{
public:
  MOCK_METHOD(bool, Init, (), (override));
  MOCK_METHOD(bool, Move, (double vx, double vy, double vyaw), (override));
  MOCK_METHOD(bool, StopMove, (), (override));
  MOCK_METHOD(bool, StandUp, (), (override));
  MOCK_METHOD(bool, StandDown, (), (override));
  MOCK_METHOD(bool, SwitchGait, (int gait_mode), (override));
  MOCK_METHOD(bool, SetBodyHeight, (double height), (override));
  MOCK_METHOD(bool, GetRobotState, (RobotState & state), (override));
  MOCK_METHOD(bool, SetSilent, (bool silent), (override));
  MOCK_METHOD(void, SetPublishingParameters, (bool publish_ros_twist, bool publish_unitree_dds), (override));
};

/**
 * @brief Google Mock class for SensorInterface.
 */
class MockSensorInterface : public SensorInterface
{
public:
  MOCK_METHOD(bool, Init, (), (override));
  MOCK_METHOD(bool, Start, (), (override));
  MOCK_METHOD(bool, Stop, (), (override));
  MOCK_METHOD(bool, IsActive, (), (const, override));
  MOCK_METHOD(std::string, GetSensorName, (), (const, override));
  MOCK_METHOD(std::string, GetSensorType, (), (const, override));
};

/**
 * @brief Google Mock class for SLAMInterface.
 */
class MockSLAMInterface : public SLAMInterface
{
public:
  MOCK_METHOD(bool, Init, (), (override));
  MOCK_METHOD(bool, StartMapping, (), (override));
  MOCK_METHOD(bool, StopMapping, (), (override));
  MOCK_METHOD(bool, SaveMap, (const std::string & path), (override));
  MOCK_METHOD(bool, LoadMap, (const std::string & path), (override));
  MOCK_METHOD(bool, UpdateMap, (const sensor_msgs::msg::PointCloud2 & cloud), (override));
  MOCK_METHOD(bool, Localize, (geometry_msgs::msg::PoseStamped & pose), (override));
  MOCK_METHOD(bool, CheckKidnapStatus, (), (override));
};

/**
 * @brief Google Mock class for PlannerInterface.
 */
class MockPlannerInterface : public PlannerInterface
{
public:
  MOCK_METHOD(bool, Init, (), (override));
  MOCK_METHOD(void, UpdatePose, (const geometry_msgs::msg::PoseStamped & pose), (override));
  MOCK_METHOD(void, UpdateGridMap, (const nav_msgs::msg::OccupancyGrid & map), (override));
  MOCK_METHOD(bool, UpdateCostmap, (const sensor_msgs::msg::PointCloud2 & cloud), (override));
  MOCK_METHOD(bool, ComputeGlobalPath, (const geometry_msgs::msg::PoseStamped & start, const geometry_msgs::msg::PoseStamped & goal, nav_msgs::msg::Path & path), (override));
  MOCK_METHOD(bool, ComputeLocalVelocity, (const geometry_msgs::msg::PoseStamped & current_pose, const nav_msgs::msg::Path & path, geometry_msgs::msg::TwistStamped & cmd_vel), (override));
  MOCK_METHOD(bool, GenerateFrontierGoals, (std::vector<geometry_msgs::msg::PoseStamped> & frontier_goals), (override));
  MOCK_METHOD(bool, FilterGoalsByFOV, (const std::vector<geometry_msgs::msg::PoseStamped> & goals, std::vector<geometry_msgs::msg::PoseStamped> & filtered_goals), (override));
};

}  // namespace test
}  // namespace go2_navigation

#endif  // GO2_NAVIGATION__MOCK_INTERFACES_HPP_
