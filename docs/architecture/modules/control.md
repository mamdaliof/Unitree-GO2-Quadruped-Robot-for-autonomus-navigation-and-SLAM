# Module: `go2_control` (Robot Platform Control)

This module handles the low-level communication and high-level locomotion command packaging for the Unitree Go2 Edu. It abstracts the difference between physical hardware control (via Unitree SDK V2 CycloneDDS packets) and simulation environments.

---

## 1. Subsystem Architecture

The control wrapper implements the abstract **[RobotInterface](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/src/go2_navigation/include/go2_navigation/robot_interface.hpp)**:

* **`RealRobot` Implementation:** Connects to CycloneDDS publishers and subscribers running on the onboard companion computer. It interacts with the Sport mode service (`/api/sport/request`) and holds system lease control via the Motion Switcher.
* **`SimRobot` Implementation:** Translates locomotion commands into standard ROS 2 `geometry_msgs/msg/TwistStamped` topics compatible with Webots or Gazebo.

---

## 2. Operations & Execution Workflow

1. **Lease Initialization:** Upon start, `RealRobot` calls `SetSilent(true)` on the `MotionSwitcherClient`. This locks the default motion control loop (releasing native joystick control) and places the robot in a ready standby state.
2. **Postural Startup:** The state machine commands `StandUp()`, standing the robot to the default height of `0.33` meters.
3. **Locomotion Loop:** The node subscribes to `/cmd_vel` at high frequency. Based on parameterized flags:
   * If `publish_ros_twist == true`, it publishes command velocities to the simulation driver.
   * If `publish_unitree_dds == true`, it serializes velocity parameters into `unitree_api::msg::Request` messages and publishes them to `/api/sport/request`.
4. **Lease Release:** On shutdown, the node calls `SetSilent(false)` and `ReleaseMode()`, returning control to the native remote controller.

---

## 3. Operational Rules & Constraints

* **Watchdog Timeout:** A command timeout watchdog monitors incoming `/cmd_vel` publishing. If no message is received for $> 0.25$ seconds, the node immediately sends a `StopMove()` command (or SDK Idle, API ID `0`) to safeguard the robot.
* **Watchdog Frequency:** The watchdog executes checks at **20 Hz** (every 50 ms) to minimize CPU overhead on the companion computer while keeping reaction latency below 50 ms.
* **Velocity Capping:** Under safe-mode operational constraints, velocity outputs are strictly capped at $1.0\text{ m/s}$ forward (`vx`) and $0.3\text{ m/s}$ lateral (`vy`).
