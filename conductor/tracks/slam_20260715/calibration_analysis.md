# Calibration Algorithm Audit: `autonomy_stack_go2`

This document details the analysis of the sensor calibration implementation found in the 3rdparty utility `calibrate_imu`.

---

## 1. Algorithm Overview
The calibration tool is implemented as a ROS 2 node running a time-indexed state machine. The total sequence takes **37 seconds** to execute. It estimates the linear acceleration bias, angular velocity bias, and Z-axis angular velocity misalignment projection factors.

### Dynamic Sequence Timeline
- **0–2 seconds (State 0 - Alignment):** The robot is commanded to stand still. Speed commands are sent as `0` to `/cmd_vel` and `StopMove` requests are published to the `/api/sport/request` service.
- **2–15 seconds (State 1 - Static Measurement):** The robot remains static. Starting at **5 seconds** (allowing transients to settle), the node accumulates IMU measurements.
- **15–35 seconds (State 2 - Dynamic Rotation):** The node commands a constant yaw rotation of `1.396 rad/s` (~80 deg/s) using the Unitree Sport client API. IMU measurements are collected during this active rotation.
- **35–37 seconds (State 3 - Computation and Serialization):** The rotation stops, bias calculations run, and calibration coefficients are saved to a YAML file.

---

## 2. Coordinate Transformation (LiDAR Tilt Alignment)
To align raw IMU inputs to a Z-up robot base coordinate system, the raw values are rotated about the Y-axis by the LiDAR pitch tilt angle $\theta$:
$$\theta = \text{tilt\_angle\_deg} \times \frac{\pi}{180}$$

The transformation equations for angular velocities $(x, y, z)$ and linear accelerations $(acc_x, acc_y, acc_z)$ are:
$$x' = x \cos(\theta) - z \sin(\theta)$$
$$y' = -y$$
$$z' = x \sin(\theta) + z \cos(\theta)$$

$$acc'_x = acc_x \cos(\theta) - acc_z \sin(\theta)$$
$$acc'_y = -acc_y$$
$$acc'_z = acc_x \sin(\theta) + acc_z \cos(\theta)$$

*Note: The negative signs in Y and Z represent axis inversions matching the robot frame conventions.*

---

## 3. Parameter Calculations

### Static Biases
Static biases are calculated by averaging the accumulated samples during State 1 ($N_{static}$):
$$\text{acc\_bias\_x} = \frac{1}{N_{static}} \sum_{i=1}^{N_{static}} acc'_{x, i}$$
$$\text{acc\_bias\_y} = \frac{1}{N_{static}} \sum_{i=1}^{N_{static}} acc'_{y, i}$$
$$\text{acc\_bias\_z} = \left( \frac{1}{N_{static}} \sum_{i=1}^{N_{static}} acc'_{z, i} \right) - 9.81$$
$$\text{ang\_bias\_x} = \frac{1}{N_{static}} \sum_{i=1}^{N_{static}} x'_i$$
$$\text{ang\_bias\_y} = \frac{1}{N_{static}} \sum_{i=1}^{N_{static}} y'_i$$
$$\text{ang\_bias\_z} = \frac{1}{N_{static}} \sum_{i=1}^{N_{static}} z'_i$$

### Rotation Alignment Projections
During the yaw rotation phase (State 2), average angular velocities are calculated and corrected for static biases:
$$\bar{\omega}_x = \left( \frac{1}{N_{rot}} \sum_{i=1}^{N_{rot}} x'_i \right) - \text{ang\_bias\_x}$$
$$\bar{\omega}_y = \left( \frac{1}{N_{rot}} \sum_{i=1}^{N_{rot}} y'_i \right) - \text{ang\_bias\_y}$$
$$\bar{\omega}_z = \left( \frac{1}{N_{rot}} \sum_{i=1}^{N_{rot}} z'_i \right) - \text{ang\_bias\_z}$$

The projection factors indicating axial cross-coupling/misalignment are computed as:
$$\text{ang\_z2x\_proj} = -\frac{\bar{\omega}_x}{\bar{\omega}_z}$$
$$\text{ang\_z2y\_proj} = -\frac{\bar{\omega}_y}{\bar{\omega}_z}$$

---

## 4. Integration Strategy for `go2_sensors`
- Read the active tilt angle configuration parameter `sensors.lidar_tilt_angle_deg` from `go2_config.json` (defaults to `13.0` instead of the hardcoded `15.1` in the 3rdparty stack).
- Implement this calibration state machine as a separate ROS 2 service or lifecycle phase triggered upon automated startup.
- Log outputs daily to `/packages/src/go2_sensors/log/calib_YYYY_MM_DD.yaml`.
- Enforce the configuration toggle `sensors.calibration_phase.enabled` to skip calibration if configured off.
