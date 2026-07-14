# Module: `go2_perception` (Sensors & Filtering)

This module handles raw sensor ingestion, spatial calibration transformations, and point cloud filtration rules to remove self-reflections.

---

## 1. Subsystem Architecture

The perception subsystem implements the abstract **[SensorInterface](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/src/go2_navigation/include/go2_navigation/sensor_interface.hpp)**:

* **`LidarInterface` Sub-class:** Generic abstraction for LiDAR payloads (L1, L2).
  * **`L1Lidar` Implementation:** Built-in Unitree LiDAR driver wrapper.
  * **`L2Lidar` Implementation:** Secondary top-mounted LiDAR (e.g. Mid-360) driver wrapper.
* **`ImuInterface` Sub-class:** Generic abstraction for IMU payloads.
  * **`RobotImu` Implementation:** Wrapper for the primary chassis IMU sensor.

---

## 2. Operations & Execution Workflow

1. **Calibration Load:** On boot, the node loads the extrinsic spatial matrix $T_{Dog2Lidar}$ from configurations. This represents the relative rigid transformation (offset and tilt pitch) between the LiDAR coordinate center and the body IMU.
2. **LiDAR stream:** Starts the packet receiver thread to publish `/lidar/points_raw`.
3. **Leg Self-Filter:** The point cloud is passed through `ApplySelfFilter()`. Points falling inside the defined 3D bounding box surrounding the chassis and legs are discarded.
4. **Publish Filtered Cloud:** Publishes `/lidar/points_filtered` which is consumed by mapping (SLAM) and local costmap planners.

---

## 3. Operational Rules & Constraints

* **Self-Filtering Bounding Box:** Points falling within the following ranges relative to the body `base_link` origin are filtered out:
  * $x \in [-0.7, -0.1]$ meters (covers chassis length)
  * $y \in [-0.3, 0.3]$ meters (covers leg width)
  * $z \in [-0.6, 0.0]$ meters (covers leg travel range)
* **Calibration Verification:** During startup, if manual checks are enabled, the robot must verify structural coordinate alignments by walking a 1.0-meter translation marker.
