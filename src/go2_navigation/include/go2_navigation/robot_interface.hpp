#ifndef GO2_NAVIGATION__ROBOT_INTERFACE_HPP_
#define GO2_NAVIGATION__ROBOT_INTERFACE_HPP_

#include <string>
#include <memory>

namespace go2_navigation
{

/**
 * @brief Structure representing the high-level state of the robot.
 */
struct RobotState
{
  float battery_percentage;
  float CPU_temperature;
  float CPU_load;
  std::string active_locomotion_mode;
  bool is_calibrated;
};

/**
 * @brief Abstract base class representing the robot platform control and SDK interface.
 */
class RobotInterface
{
public:
  using SharedPtr = std::shared_ptr<RobotInterface>;

  /**
   * @brief Virtual destructor.
   */
  virtual ~RobotInterface() = default;

  /**
   * @brief Initialize the robot connection and SDK wrappers.
   * @return true if initialization succeeded, false otherwise.
   */
  virtual bool Init() = 0;

  /**
   * @brief Send velocity command to the robot.
   * @param vx Linear velocity on X-axis (m/s).
   * @param vy Linear velocity on Y-axis (m/s).
   * @param vyaw Angular velocity around Z-axis (rad/s).
   * @return true if command was sent successfully.
   */
  virtual bool Move(double vx, double vy, double vyaw) = 0;

  /**
   * @brief Command the robot to stop moving instantly.
   * @return true if stop command succeeded.
   */
  virtual bool StopMove() = 0;

  /**
   * @brief Command the robot to stand up.
   * @return true if command succeeded.
   */
  virtual bool StandUp() = 0;

  /**
   * @brief Command the robot to stand down/lie down.
   * @return true if command succeeded.
   */
  virtual bool StandDown() = 0;

  /**
   * @brief Command the robot to switch locomotion gait mode.
   * @param gait_mode Gait identifier (e.g., 0=Idle, 1=Trot, 2=Trot-Run, 3=Climb).
   * @return true if mode switch succeeded.
   */
  virtual bool SwitchGait(int gait_mode) = 0;

  /**
   * @brief Set body height offset.
   * @param height Height offset in meters.
   * @return true if command succeeded.
   */
  virtual bool SetBodyHeight(double height) = 0;

  /**
   * @brief Retrieve the current high-level state of the robot.
   * @param state Output parameter to populate with the robot state.
   * @return true if state was retrieved successfully.
   */
  virtual bool GetRobotState(RobotState & state) = 0;

  /**
   * @brief Enable or disable silent lease mode on MCF Switcher.
   * @param silent Set true to mute MCF system loops, false to release control.
   * @return true if switcher command succeeded.
   */
  virtual bool SetSilent(bool silent) = 0;

  /**
   * @brief Set publishing targets dynamically.
   * @param publish_ros_twist If true, enable standard cmd_vel Twist publishing.
   * @param publish_unitree_dds If true, enable Unitree Sport SDK DDS packet publishing.
   */
  virtual void SetPublishingParameters(bool publish_ros_twist, bool publish_unitree_dds) = 0;

protected:
  bool publish_ros_twist_{true};
  bool publish_unitree_dds_{false};
};

}  // namespace go2_navigation

#endif  // GO2_NAVIGATION__ROBOT_INTERFACE_HPP_
