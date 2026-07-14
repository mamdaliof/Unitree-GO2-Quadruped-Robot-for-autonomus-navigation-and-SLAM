# Repository Audit: CMU Autonomy Stack Go2

This document compiles the system audit findings, code architecture analysis, advantages, limitations, and key insights extracted from the [CMU Autonomy Stack for Go2](https://github.com/jizhang-cmu/autonomy_stack_go2) repository.

---

## 1. Executive Summary
The CMU Autonomy Stack provides full autonomous navigation and SLAM capabilities for the Unitree Go2 EDU platform. It integrates Hong Kong University's **Point-LIO** SLAM package, CMU's **FAR Planner** (a visibility-graph path planner), and a custom **Local Planner** for terrain analysis and obstacle avoidance. The entire system is built on ROS 2 (tested on Foxy and Humble) and targets high-level locomotion command APIs.

---

## 2. SDK Architecture & Compatibility
* **SDK Wrapper Interface:** The repository does not use the low-level Unitree motor control SDK. Instead, it utilizes Unitree's high-level **SportMode** API.
* **Locomotion Topic:** Commands are issued by publishing to the `/api/sport/request` ROS 2 topic using the `unitree_api::msg::Request` message type.
* **DDS Client Helper:** A helper class `SportClient` (`common/ros2_sport_client.h`) is used to construct standard request payloads (e.g. `Move` and `StopMove`) inside the custom control nodes (`vel_ctrl_repub.cpp` and `pathFollower.cpp`).
* **Compatibility Status:** **100% Compatible.** Our system design also targets the same high-level DDS interfaces, meaning we can utilize the same ROS 2 message definitions and DDS workspace configuration.

---

## 3. SLAM & Navigation Methodology

### A. Point-LIO SLAM Backend
* **Sensor Sources:** Subscribes to the raw LiDAR point cloud (`/utlidar/cloud`) and the LiDAR's internal IMU (`/utlidar/imu`).
* **Coordinate Pre-Processing (`transform_everything.py`):**
  * **Tilt Rotation:** Resolves the physical mounting pitch tilt of the Livox L1 LiDAR by applying a `15.1°` pitch rotation and an upside-down orientation rotation (`180.0° - 15.1° = 164.9°` pitch Euler rotation).
  * **Time Offset Synchronization:** Manually calculates and adds a timestamp offset at node startup to synchronize sensor timestamps with the ROS 2 clock.
  * **Mocked IMU Parameters:** In `transform_everything.py`, the linear acceleration components of `/utlidar/transformed_imu` are overwritten to zero. This implies the SLAM backend relies primarily on the gyro's angular rate signals rather than raw accelerometer data, which is an important fallback choice for noisy locomotion.

### B. Navigation & Control Loop
1. **Visibility Graph (FAR Planner):** Builds a real-time visibility graph representing traversable free space and unknown space. Targets a user-selected Goalpoint.
2. **Terrain Traversability Analysis:** Evaluates slopes and step heights to check if the path is physically traversable by a quadruped.
3. **CMU Local Planner:** Dynamically generates short-range collision-free local paths avoiding costmap obstacles.
4. **Path Follower Node (`pathFollower`):** Implements a lookahead target controller that reads the local path and outputs velocity vectors (linear speed, lateral speed, and yaw rate).

---

## 4. Control Unification (Simulation vs. Real Robot)
* **Unification Approach:** The repository successfully runs the exact same local planning and path-following code on both the Unity simulator and the real Go2 robot.
* **Dual-Publishing Strategy:** Inside `pathFollower.cpp`, the node checks the parameter `is_real_robot`:
  * **Simulation:** Publishes a standard ROS 2 `geometry_msgs/msg/TwistStamped` to the `/cmd_vel` topic, which is received by the simulation's Unity bridge.
  * **Real Robot:** Simultaneously publishes standard `/cmd_vel` AND constructs the Unitree `/api/sport/request` DDS packet, transmitting linear $x, y$ and yaw rate commands directly to the robot's onboard controller.
* **Unified Pipeline recommendation:** We must copy this architecture. Our control wrapper should handle both standard `/cmd_vel` outputs (for Gazebo/Unity) and `unitree_api` request messages (for physical deployment) via a simple parameter switch.

---

## 5. Bugs, Loopholes, & Limitations

* **L1 LiDAR Noise & Low Obstacles:** The built-in L1 LiDAR has high measurement noise. The terrain analysis node cannot accurately distinguish obstacles below $0.3\text{ m}$ (such as power cables, cords, or low curbs). The robot is highly prone to tripping or colliding with low objects.
* **High SLAM Drift:** Under fast rotations or slippery floor surfaces, Point-LIO experiences odometry drift, distorting the map and causing the local planner to get stuck.
  * *Bypass:* The authors added a manual joystick override button to clear the active terrain map, forcing the robot to wipe the local costmap and rebuild it on the fly.
* **DDS Startup Data Delay:** A significant data lag ($> 1\text{ s}$) occurs regularly for 10-20 seconds right after system bringup, particularly on ROS 2 Humble. The robot will not respond to inputs during this time.
* **Unsynchronized Cameras:** Camera H.264 image streams are repubbed on `/camera/image/raw` but are not synchronized with LiDAR or IMU timestamps. Recording images to bagfiles causes massive frame loss due to CPU overload on the onboard computer.
* **Manual IMU Calibration Dependency:** The LiDAR's internal IMU requires manual calibration via `calibrate_imu`. This saves a file `imu_calib_data.yaml` to the computer's desktop, which is loaded at boot. If this file is missing, SLAM fails to initialize or drifts immediately.

---

## 6. Advantages & Inspired Design Points
* **Self-Filtering Bounding Box:** To prevent the robot from seeing its own feet and chassis as obstacles, a spatial bounding box is defined around the chassis origin:
  * $x \in [-0.7, -0.1]$
  * $y \in [-0.3, 0.3]$
  * $z \in [-0.6, 0.0]$ (relative to coordinate offsets).
  * Points inside this box are discarded. We must adopt this filtering method in our perception node.
* **Heartbeat & Fail-safes:** The path follower automatically halts (`StopMove`) when target paths are empty or when an incline limits check fails.
* **Wireless HDMI HDMI Transmitter setup:** A physical hardware package utilizing a wireless HDMI transmitter and a wireless hub lets the onboard computer act as a remote desktop, resolving connectivity issues.

---

## 7. Flaws Identified in Our Current Documents
1. **LiDAR Tilt Angle:** We do not use repository tilt of 15.1 degrees. We keep the catalog value of 13.0 degrees for now. The user will calculate the physical tilt angle themselves.
2. **Sensor Calibration Phase:** We need a separate calibration phase for all sensors (such as IMU and LiDAR) before running the SLAM backend.
3. **Sensor Accuracy Setup Phase:** We need a setup phase run once at startup. This checks sensor accuracy: static IMU drift, translation accuracy when moving 1 meter forward, and rotation accuracy.
4. **Self-Filter Box:** We agree to implement a self-filter. This discards LiDAR points that hit the robot's own legs and chassis.
