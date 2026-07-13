# Perception Sensors, Odometry & Avoidance Interfaces

This document covers point cloud publisher structures (`utlidar`), odometer feedback states, and the obstacle avoidance service APIs.

---

## 1. Reference Links to Archive Sources
For original method signatures, error tables, and older version profiles, refer to the archived guides:
* [Raw LiDAR Services Interface Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/LiDAR_Services_Interface.md)
* [Raw Odometer Services Interface Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/Odometer_Services_Interface.md)
* [Raw Avoidance Services Interface Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/Avoidance_Services_Interface.md)

---

## 2. LiDAR Point Cloud Topic Interfaces (`utlidar`)

The LiDAR service publishes point cloud topics containing range-finding samples:
* **`rt/utlidar/cloud`** (`sensor_msgs::msg::dds_::PointCloud2_`): Raw point cloud data in the LiDAR's coordinate system.
* **`rt/utlidar/cloud_deskewed`** (`sensor_msgs::msg::dds_::PointCloud2_`): Distortion-corrected point cloud transformed into the odometer coordinate frame.

---

## 3. Odometer Estimation Interfaces (`OdomState_`)

State estimators output odometry data by fusing leg kinematics and IMU sensors:
* **Topic:** `rt/odom/state` (or `rt/odom/odometry` mapped by the firmware)
* **Data Type:** `nav_msgs::msg::dds_::Odometry_` (or custom `OdomState_.idl` structures)

### Odometer State Struct Fields
* **`position`:** 3D coordinates relative to startup origin `[x, y, z]`.
* **`orientation`:** Posture quaternion `[w, x, y, z]`.
* **`velocity`:** 3D velocity vectors relative to the body coordinate system `[vx, vy, vz]`.
* **`angular_velocity`:** Angular rates around three axes `[wx, wy, wz]`.

---

## 4. Obstacle Avoidance Services

The Go2 features built-in obstacle avoidance services that monitor distance data from the depth camera and LiDAR to adapt walking speeds.

### Obstacle Avoidance Client (`AvoidanceClient`)
* **`int32_t SwitchAvoidance(bool enable)`:** Turns obstacle avoidance on or off.
* **`int32_t GetAvoidanceState(bool& active)`:** Queries if the avoidance service is active.
* **`std::array<float, 4> rangeObstacle()`:** Subscribes to the distance to obstacles in four directions (Front, Back, Left, Right).

---

## 5. Project Relevance
* **Visual Odometry Fusion:** If wheel slippage occurs, the localization module uses `rt/odom/state` as the dead-reckoning prediction for the Kalman Filter, correcting the estimate with LiDAR point cloud matching.
* **Dynamic Avoidance Override:** While navigating open areas, we enable obstacle avoidance. In narrow doorways or elevator shafts (clearance $< 0.8$m), the state machine disables avoidance to allow the robot to pass through.
