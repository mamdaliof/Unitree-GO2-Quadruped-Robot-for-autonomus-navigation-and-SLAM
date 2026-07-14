#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mock_interfaces.hpp"

using ::testing::_;
using ::testing::Return;
using ::testing::SetArgReferee;
using ::testing::DoAll;

namespace go2_navigation
{
namespace test
{

TEST(RobotInterfaceTest, MockMoveTest)
{
  MockRobotInterface mock_robot;

  // Set expectation: Move will be called with (0.5, 0.0, 0.1) and return true
  EXPECT_CALL(mock_robot, Move(0.5, 0.0, 0.1))
    .Times(1)
    .WillOnce(Return(true));

  // Execute
  bool success = mock_robot.Move(0.5, 0.0, 0.1);
  EXPECT_TRUE(success);
}

TEST(RobotInterfaceTest, MockStopTest)
{
  MockRobotInterface mock_robot;

  // Set expectation: StopMove will return true
  EXPECT_CALL(mock_robot, StopMove())
    .Times(1)
    .WillOnce(Return(true));

  bool success = mock_robot.StopMove();
  EXPECT_TRUE(success);
}

TEST(SensorInterfaceTest, MockLidarFilterTest)
{
  MockLidarInterface mock_lidar;
  sensor_msgs::msg::PointCloud2 input_cloud;
  sensor_msgs::msg::PointCloud2 output_cloud;

  // Set expectation: ApplySelfFilter returns true
  EXPECT_CALL(mock_lidar, ApplySelfFilter(_, _))
    .Times(1)
    .WillOnce(Return(true));

  bool success = mock_lidar.ApplySelfFilter(input_cloud, output_cloud);
  EXPECT_TRUE(success);
}

TEST(SLAMInterfaceTest, MockMappingLifecycleTest)
{
  MockSLAMInterface mock_slam;

  EXPECT_CALL(mock_slam, StartMapping())
    .Times(1)
    .WillOnce(Return(true));

  EXPECT_CALL(mock_slam, SaveMap("/home/unitree/map.pcd"))
    .Times(1)
    .WillOnce(Return(true));

  EXPECT_TRUE(mock_slam.StartMapping());
  EXPECT_TRUE(mock_slam.SaveMap("/home/unitree/map.pcd"));
}

TEST(PlannerInterfaceTest, MockPathPlanningTest)
{
  MockPlannerInterface mock_planner;
  geometry_msgs::msg::PoseStamped start;
  geometry_msgs::msg::PoseStamped goal;
  nav_msgs::msg::Path path;

  EXPECT_CALL(mock_planner, ComputeGlobalPath(_, _, _))
    .Times(1)
    .WillOnce(Return(true));

  bool success = mock_planner.ComputeGlobalPath(start, goal, path);
  EXPECT_TRUE(success);
}

}  // namespace test
}  // namespace go2_navigation

int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
