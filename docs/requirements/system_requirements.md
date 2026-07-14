# Approved Sensor and Calibration Changes
Me record changes agreed by tribal consensus:
* **Approved Additions:**
  - `REQ-FUN-005` (Sensor Calibration Phase)
  - `REQ-FUN-006` (Sensor Accuracy Setup Phase)
  - `REQ-FUN-007` (Perception Self-Filter)
* **Details:**
  1. **LiDAR Tilt Angle:** We do not use repository tilt of 15.1 degrees. We keep the catalog value of 13.0 degrees for now. The user will calculate the physical tilt angle themselves.
  2. **Calibration Phase:** We require a distinct phase for all sensors that need calibration.
  3. **Setup Phase:** Run once to check sensor accuracy: static IMU drift, 1-meter forward movement, and rotation in place.
  4. **Self-Filter:** Bounding box filters out reflections from the robot's own legs and chassis.

---

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
  1. **Autonomous Mapping (Primary):** The robot automatically navigates the location to sweep and construct the 3D map.
  2. **Manual Mapping (Backup):** Human manual joystick override to guide the robot during mapping if autonomous exploration fails.
after the deployment mapping, the rest of movements and inspection runs are for adjusting map, monitor changes in station, and accurate localization.
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
  * *Constraint:* Direct low-level joint pd-torque control is out of scope.

### 📌 REQ-FUN-004: Safe Navigation & Avoidance
* **Description:** Collision-free navigation is the primary goal:
  1. **SDK Navigation (Primary):** Try the built-in Go2 SDK obstacle avoidance and path planning.
  2. **Custom Navigation (Fallback):** If the default SDK planner fails or is insufficient, implement custom ROS 2 Nav2 planners and point cloud perception filters.

### 📌 REQ-FUN-005: Sensor Calibration Phase
* **Description:** Me mandate distinct sensor calibration phase:
  1. **IMU Calibration:** Robot must write IMU calibration file (`imu_calib_data.yaml`). SLAM reads this file. No run SLAM without calibration.
  2. **LiDAR Tilt Calibration:** User will calculate LiDAR physical tilt angle. Do not use repository value of 15.1 degrees. Keep catalog value of 13.0 degrees for now.

### 📌 REQ-FUN-006: Sensor Accuracy Setup Phase
* **Description:** Robot must run setup diagnostics once to check sensor accuracy:
  1. **Static Drift Check:** Robot stands still to measure IMU drift.
  2. **Translation Check:** Robot walks 1 meter forward to verify translation calculations.
  3. **Rotation Check:** Robot rotates in place to verify orientation calculations.

### 📌 REQ-FUN-007: Perception Self-Filter
* **Description:** Filter out points from robot's own body and legs:
  1. **Self-Filter Box:** Spatial bounding box discards points inside:
     * $x \in [-0.7, -0.1]$
     * $y \in [-0.3, 0.3]$
     * $z \in [-0.6, 0.0]$

---

## 3. Non-Functional & Safety Requirements (REQ-SFT)

### 📌 REQ-SFT-001: Operational Constraints
* **Max Velocity:** Limited to `1.0 m/s` for workplace safety.
* **Min Battery Limit:** The robot must initiate a return-to-dock routine when battery levels drop below `15%`.

### 📌 REQ-SFT-002: Safety Fallback Actions
* **LiDAR/Sensor Loss:** If the primary LiDAR data drops, the robot must immediately transition to the `STAND_STILL` state and wait.
* **Network Connection Loss:** If communication lag exceeds the safety threshold, the robot must immediately stand still and wait.

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
