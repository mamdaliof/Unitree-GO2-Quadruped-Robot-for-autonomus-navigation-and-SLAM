# Unitree Go2 Config Parameter Reference (`go2_config.json`)

This document describes all configuration variables used in the Unitree Go2 Smart Inspection System, their purposes, and the files that reference them.

---

## 1. Node Names (`nodes`)
- **`sensor_publisher_node_name`**
  - **Description:** The ROS 2 node name instantiated on startup.
  - **Referencing Files:** [sensor_publisher_node.cpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/packages/src/go2_sensors/src/sensor_publisher_node.cpp)

---

## 2. ROS 2 / DDS Topics (`topics`)
- **`l1_lidar_input`**
  - **Description:** The raw input topic published by the Unitree Lidar driver/bridge.
  - **Referencing Files:** [l1_lidar.cpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/packages/src/go2_sensors/src/l1_lidar.cpp)
- **`l1_lidar_output`**
  - **Description:** The standardized target ROS 2 topic name where raw L1 Lidar point clouds are published.
  - **Referencing Files:** [sensor_publisher_node.cpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/packages/src/go2_sensors/src/sensor_publisher_node.cpp)
- **`l2_lidar_input`**
  - **Description:** The raw input topic published by the secondary Lidar driver.
  - **Referencing Files:** [l2_lidar.cpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/packages/src/go2_sensors/src/l2_lidar.cpp)
- **`l2_lidar_output`**
  - **Description:** The standardized target ROS 2 topic name where raw L2 Lidar point clouds are published.
  - **Referencing Files:** [sensor_publisher_node.cpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/packages/src/go2_sensors/src/sensor_publisher_node.cpp)
- **`imu_input`**
  - **Description:** The raw input topic published by the robot's IMU driver.
  - **Referencing Files:** [robot_imu.cpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/packages/src/go2_sensors/src/robot_imu.cpp)
- **`imu_output`**
  - **Description:** The standardized target ROS 2 topic name where raw IMU data is published.
  - **Referencing Files:** [sensor_publisher_node.cpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/packages/src/go2_sensors/src/sensor_publisher_node.cpp)

---

## 3. General System Settings (`system`)
- **`target_localization_accuracy_m`**
  - **Description:** The target accuracy threshold in meters. Used by SLAM and planners.
  - **Referencing Files:** [system_requirements.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/docs/requirements/system_requirements.md)
- **`allowable_slope_angle_deg`**
  - **Description:** The maximum allowable slope climbing angle for safety.
  - **Referencing Files:** [system_requirements.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/docs/requirements/system_requirements.md)
- **`dynamic_speed_scaling`**
  - **Description:** Toggle to enable speed reduction when navigating slopes or tight spots.
  - **Referencing Files:** [system_requirements.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/docs/requirements/system_requirements.md)
- **`sampling_frequency_hz`**
  - **Description:** Polling rate for telemetry data from DDS interfaces.
  - **Referencing Files:** Low-level SDK wrappers.
- **`debug_mode.enabled`**
  - **Description:** Global switch to print performance logs and record sensor bags.
  - **Referencing Files:** [sensor_publisher_node.cpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/packages/src/go2_sensors/src/sensor_publisher_node.cpp)
- **`debug_mode.log_block_process_times`**
  - **Description:** Toggle to print timestamps of critical code execution segments.

---

## 4. Sensor & Calibration Parameters (`sensors`)
- **`lidar_tilt_angle_deg`**
  - **Description:** Mount pitch angle of the main Lidar relative to the robot chassis.
  - **Referencing Files:** Point cloud transform libraries.
- **`imu_calibration_required`**
  - **Description:** Toggle to enforce static IMU calibration checks.
  - **Referencing Files:** [system_requirements.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/docs/requirements/system_requirements.md)
- **`self_filter_box` (`x_min`, `x_max`, `y_min`, `y_max`, `z_min`, `z_max`)**
  - **Description:** Bounding box coordinate parameters in meters to crop out parts of the robot chassis and legs from the Lidar point clouds.
  - **Referencing Files:** [system_requirements.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/docs/requirements/system_requirements.md)
- **`calibration_phase` (`enabled`, `imu_static_calib`, `lidar_tilt_calib`)**
  - **Description:** Calibration toggles for automatic startup alignments.
  - **Referencing Files:** [plan.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/conductor/tracks/slam_20260715/plan.md)
- **`setup_accuracy_check` (`enabled`, `check_imu_static_drift`, `check_translation_1m`, `check_rotation`)**
  - **Description:** Quality verification steps run upon initialization.
  - **Referencing Files:** Setup check scripts.

---

## 5. Locomotion & Safety Limits (`locomotion`, `safety`)
- **`max_linear_velocity_m_s`**
  - **Description:** Maximum walking speed limit in autonomous modes.
- **`min_battery_reserve_pct`**
  - **Description:** Minimum battery charge level before forcing return-to-dock.
- **`movement_modes` (`relative_positioning`, `absolute_positioning`)**
  - **Description:** Allowed control interfaces.
- **`sensor_loss_action`**
  - **Description:** Fallback behavior (e.g. `STAND_STILL`) on sensor failure.
- **`network_lag_action`**
  - **Description:** Fallback behavior on wireless disconnect.
- **`human_proximity_slowdown` (`enabled_in_phase_1`, `slowdown_radius_m`, `target_slowdown_velocity_m_s`)**
  - **Description:** Automatic slowdown rules when workers are nearby.
