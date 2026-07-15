# Specification: SLAM Track

## Overview
This track establishes the SLAM subsystem as the primary entry point for the Unitree Go2 Smart Inspection system. It covers sensor drivers, calibration, point-lio integration, and A-LOAM integration. It incorporates the Unitree SDK 2 (`unitree_sdk2`) and DDS communication interfaces for physical robot telemetry.

## Subtracks
### Subtrack 1: Sensor Driver & Publisher Node Establishment
- Inherit `L1Lidar`, `L2Lidar`, and `RobotImu` from the `SensorInterface` abstract base class.
- Subscribes to the Unitree SDK 2 / CycloneDDS native topics:
  - IMU data from `rt/lowstate` (parsing the `IMUState_` struct fields: `quaternion`, `gyroscope`, `accelerometer`).
  - LiDAR point clouds from `rt/utlidar/cloud` or `rt/utlidar/cloud_deskewed` (using ROS 2 / DDS `sensor_msgs::msg::PointCloud2`).
- Publish raw sensor data to ROS 2 topics, fully compatible with ROS 2 Jazzy.
- Node names and configurations must be read dynamically from the config file (`go2_config.json`).
- Support processing samples from specific timestamps and offline playback (handling of simulation/rosbag time).
- **Physical Validation:** Verify data streaming on the physical robot using `ros2 topic echo` to check frequency and frame synchronization.

### Subtrack 2: Sensor Calibration & Logging
- Analyze and document the calibration algorithm from `autonomy_stack_go2`.
- Run calibration automatically on robot startup when in automated mode.
- Log calibration parameters daily to `packages/src/go2_sensors/log` for long-run analysis.
- Provide a configuration parameter in `go2_config.json` to enable/disable calibration.
- **Physical Validation:** Verify that calibration executes at startup on the real robot, logs output to the directory, and respect the enable/disable flag in config.

### Subtrack 3: Point-LIO Integration
- Clone `point_lio_unilidar` into `packages/src/` directory.
- Compare cloned package with `autonomy_stack_go2` point-lio implementation.
- Support configurable LIDAR selection (L1, L2, or both) in `go2_config.json`.
- Wrap Point-LIO to support map saving and loading for localization, map enhancement, and persistent operation.
- In debug mode, support logging raw sensor data to a rosbag file for offline playback.
- **Physical Validation:** Verify map building and saving/loading on the physical robot by moving the robot manually and viewing the output.

### Subtrack 4: A-LOAM Integration
- Clone `A-LOAM` into `packages/src/` directory.
- Integrate A-LOAM as an alternative SLAM backend.
- **Physical Validation:** Run A-LOAM on the real robot and compare CPU utilization and mapping quality with Point-LIO.

## Physical Testing & Validation
- Support running SLAM in manual control mode to allow moving the robot manually and verifying map generation.
- Stage 2 manual testing protocol requires verifying the entire pipeline on the physical Go2 robot using safe-mode (low speed/manual control).

## Acceptance Criteria
1. Sensor publishers successfully run and publish IMU and LIDAR topics in ROS 2 Jazzy from physical DDS topics.
2. Calibration runs at startup, writes logs daily to the specified log directory, and can be disabled via config.
3. Point-LIO and A-LOAM compile successfully in the ROS 2 workspace.
4. Point-LIO supports map saving, map loading for localization/map update, and LIDAR configuration.
5. Rosbag recording is active when debug mode is enabled.
6. System supports manual control testing for real-time map verification on the physical robot.

