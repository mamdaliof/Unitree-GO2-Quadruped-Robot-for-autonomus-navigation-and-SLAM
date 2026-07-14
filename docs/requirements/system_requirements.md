# System Requirements Specification

This document details the functional, non-functional, safety, and environmental requirements for the Unitree Go2 Smart Navigation and SLAM system.

---

## 1. Mission Objectives

The primary goal is to establish safe autonomous navigation, high-fidelity mapping, and precise real-time localization for the Go2 quadruped robot in manufacturing setups.

System configurations are managed in the global config file: `[[go2_config.json]]`.

---

## 2. Functional Requirements (REQ-FUN)

### 📌 REQ-FUN-001: Mapping Workflow for Deployment (Autonomous-First)
* **Description:** The system must support two mapping methods:
  1. **Autonomous Mapping (Primary):** The robot automatically navigates the environment to sweep and construct the 3D map.
  2. **Manual Mapping (Backup):** Human manual joystick override to guide the robot during mapping if autonomous exploration fails.
  3. **Post-Mapping Phase:** After the initial deployment mapping is completed, subsequent movements and inspection runs are dedicated to map adjustment, monitoring environmental changes at stations, and maintaining accurate real-time localization.
### 📌 REQ-FUN-002: Staged Sensor Integration
* **Description:** The system architecture must accommodate the following incremental sensor phases:
  1. **Phase 1:** Single 3D LiDAR and basic odometry.
  2. **Phase 2:** Tightly-coupled LIO (LiDAR + IMU).
  3. **Phase 3:** Dual 3D LiDARs + IMU.
  4. **Phase 4:** Vision Camera (RGB feed).
  5. **Phase 5:** Depth Camera.
  6. **Phase 6:** Thermal Camera (specifically to achieve 3D thermal/heat reconstruction, without relying on it for baseline SLAM tracking).

### 📌 REQ-FUN-003: High-Level Locomotion Commands
* **Description:** The control interfaces must support high-level motion client APIs:
  * Linear and angular velocity tracking.
  * **Absolute positioning** coordinates.
  * **Relative positioning** coordinate displacements.
  * **Unified Double-Publishing Control:** The control wrapper must support double-publishing: standard `geometry_msgs/msg/TwistStamped` messages (for simulator/generic) and Unitree Sport SDK DDS Request packets (for physical robot deployment), dynamically toggled by the `is_real_robot` configuration flag.
  * *Constraint:* Direct low-level joint pd-torque control is out of scope.

### 📌 REQ-FUN-004: Safe Navigation & Avoidance
* **Description:** Collision-free navigation is the primary goal:
  1. **SDK Navigation (phase1):** Try the built-in Go2 SDK obstacle avoidance and path planning.
  2. **Custom Navigation (phase2):** If the default SDK planner fails or is insufficient, implement custom ROS 2 Nav2 planners and point cloud perception filters.

### 📌 REQ-FUN-005: Sensor Calibration Phase
* **Description:** Mandate distinct sensor calibration phase:
  1. **IMU Calibration:** Robot must write IMU calibration file (`imu_calib_data.yaml`). SLAM reads this file. No run SLAM without calibration.
  2. **LiDAR Tilt Calibration:** LiDAR physical tilt angle should be calculated manually or use the catalog value.

### 📌 REQ-FUN-006: Sensor Accuracy Setup Phase
* **Description:** The robot must run diagnostic checks once at startup to verify sensor calibration and synchronization:
  1. **Static Drift Check:** The robot remains stationary to measure and log IMU accelerometer and gyro static drifts.
  2. **Translation Check (Optional/Manual):** Verification of translation accuracy can be manually triggered during setup. The robot walks 1.0 meter forward, and the system compares the estimated SLAM/odometry displacement against a physical floor reference marker.
  3. **Rotation Check (Optional/Manual):** Verification of orientation tracking can be manually triggered. The robot rotates 360 degrees in place, and the system compares the integrated yaw angle against a physical alignment line.
  4. **Hardware Time-Sync Check:** Validate that the hardware timestamp offset between the LiDAR and the IMU is within a strict tolerance bounds (e.g., < 10 ms) to avoid rotational "ghosting" artifacts in SLAM.

### 📌 REQ-FUN-007: Perception Self-Filter
* **Description:** Filter out points from the robot's own body structure and legs:
  1. **Self-Filter Box:** A spatial bounding box filters the active LiDAR points (supporting both the built-in 4D L1 LiDAR and any optional top-mounted L2 LiDAR) to discard reflections from the robot's chassis and legs.
  2. **Bounding Box Parameters:** Points falling inside the following candidate coordinates are discarded (coordinates are parameterized in `go2_config.json` and subject to dynamic tuning):
     * $x \in [-0.7, -0.1]$
     * $y \in [-0.3, 0.3]$
     * $z \in [-0.6, 0.0]$

### 📌 REQ-FUN-008: Debug Mode & Code Profiling
* **Description:** The system must support a configurable global Debug Mode:
  1. **Activation:** Enabled via the system configuration (`go2_config.json`).
  2. **Profiling:** When active, the system must measure and log the processing/execution time of each major functional block, callback, or ROS 2 node pipeline.
  3. **Diagnostics:** Provide timing details to help identify CPU bottlenecking or frame drops.
  4. **Extensibility:** The debug framework must remain flexible to accommodate additional diagnostic metrics (e.g., memory usage, temperature, or DDS packet drop rates) in future implementation phases.

### 📌 REQ-FUN-009: Motion Noise Mitigation on SLAM
* **Description:** The system must mitigate SLAM odometry drift and point cloud registration noise caused by the robot's dynamic walking movements (e.g., body shaking, leg impacts, and startup height/pitch adjustments).

### 📌 REQ-FUN-010: Autonomous Exploration FOV & Loop Closure Preference
* **Description:** During autonomous exploration mapping:
  1. **Field of View Preference:** The planner should prefer exploration goals within the robot's forward 100-degree field of view to ensure the sensors actively scan the path ahead.
  2. **Safe Fallback:** If forward goals are blocked or unavailable, the robot is permitted to rotate in place or explore side/backward frontiers.
  3. **Loop Closure Preference:** The global path planner should prioritize routes that return to previously mapped regions to maximize loop closure occurrences and improve global map consistency.

---

## 3. Non-Functional & Safety Requirements (REQ-SFT)

### 📌 REQ-SFT-001: Operational Constraints
* **Max Velocity:** Limited to `1.0 m/s` for workplace safety.
* **Min Battery Limit:** The robot must initiate a return-to-dock routine when battery levels drop below `15%`.

### 📌 REQ-SFT-002: Safety Fallback Actions
* **LiDAR/Sensor Loss:** If the primary LiDAR data drops, the robot must immediately transition to the `STAND_STILL` state and wait.
* **Network Connection Loss:** If communication lag *between the companion computer (Jetson) and the robot's onboard controller* exceeds the safety threshold, the robot must stand still and wait. Loss of external Wi-Fi/network connectivity to a remote operator must NOT trigger standstill if the robot is performing an autonomous untethered inspection run.
* **Control Watchdog Timeout:** A watchdog timer running at 20 Hz (checking every 50 ms) must monitor the command velocity stream. If no new `cmd_vel` messages are received within 0.25 seconds, the control bridge must automatically publish an Idle command (SDK API ID 0) to stop the robot.
* **Empty-Path & Tilt Failsafes:** The robot must halt and execute a `StopMove` SDK command if the active local path becomes empty or if the robot's measured pitch/roll tilt angle exceeds predefined safety limits.
* **Kidnapped Robot Detection:** If the global ICP registration fitness drops below 0.9 (indicating a severe localization drift, slip, or kidnapping event), the SLAM interface must stop updating the `map` to `odom` frame offset, raise a high-priority system warning, and halt autonomous movement.

### 📌 REQ-SFT-003: Human Proximity Safety (Future Phase)
* **Description:** The robot must reduce speed when humans are detected within a 2.0-meter radius. *Note: Deferred to post-Phase 1 (requires active LiDAR/vision object classification).*

---

## 4. Environmental Constraints & Metrics (REQ-ENV)

### 📌 REQ-ENV-001: Target Validation Sites
* **Description:** The system must be validated in:
  1. **The Cube:** Open multi-level testing zone.
  2. **The Basement:** Narrow, low-light, structured environment.
  3. **AMC (Advanced Manufacturing Center):** Active industrial floor with dynamic obstacles.

### 📌 REQ-ENV-002: Localization Accuracy Goal
* **Target:** Precise localization with an error margin $< 5\text{ cm}$.
* **Open Issue:** Identify a reliable method to measure and validate this localization accuracy.
