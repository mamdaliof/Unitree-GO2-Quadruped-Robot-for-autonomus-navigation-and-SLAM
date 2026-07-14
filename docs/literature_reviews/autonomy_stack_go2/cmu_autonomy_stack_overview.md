# Overview: CMU Autonomy Stack for Go2

This overview analyzes the core software methodologies, SDK implementations, package structures, and critical source files within the `jizhang-cmu/autonomy_stack_go2` workspace for manual review.

---

## 1. Core Methodology

The CMU Autonomy Stack implements a three-tier software hierarchy to achieve autonomous quadruped navigation:

1. **State Estimation & Mapping (Point-LIO SLAM):**
   * Processes high-frequency raw point clouds from the Unitree L1 LiDAR (`/utlidar/cloud`) and inertial measurements from its internal IMU (`/utlidar/imu`).
   * Utilizes a tightly-coupled LiDAR-inertial odometry (LIO) system with a manifolds-based Kalman Filter to generate smooth local odometry (`/state_estimation`) and map outputs.
2. **Global Route Planning (FAR Planner):**
   * Continuously parses traversability costmaps to build a 2D/3D visibility graph.
   * Connects edges through known free space to plan optimal global trajectories (colored green in RVIZ) and attempts to discover paths through unknown frontiers (colored blue).
3. **Local Planning & Control (Terrain Analysis & Local Planner):**
   * Projects point clouds onto a local grid to evaluate terrain roughness, step heights, and slopes.
   * Generates short-range collision-free waypoints around dynamic obstacles.
   * Translates local paths into forward/lateral velocity and yaw rate commands.

---

## 2. SDK Usage

* **High-Level Sport API:** Rather than commanding joint motor torques or positions directly, the stack utilizes Unitree's high-level **SportMode** API.
* **ROS 2 Service/Topic Mapping:** Commands are sent via DDS to the `/api/sport/request` topic using custom ROS 2 messages of type `unitree_api::msg::Request`.
* **locomotion commands:** The C++ helper `SportClient` (`common/ros2_sport_client.h`) builds command payloads. Example methods called:
  * `sport_req.Move(req, vx, vy, vyaw)`: Commands movement velocity.
  * `sport_req.StopMove(req)`: Halts locomotion and locks joints in place.

---

## 3. Workspace Architecture

The workspace is organized into four main folders under the `src` directory:

```
src/
├── slam/
│   ├── point_lio_unilidar/     # HKU Point-LIO SLAM package (L1 lidar version)
│   └── calibrate_imu/          # IMU static bias calibration node
├── route_planner/
│   ├── far_planner/            # Global visibility graph planner
│   └── graph_decoder/          # Decodes and outputs visibility graph topics
├── base_autonomy/
│   ├── vehicle_simulator/      # Simulator launcher and RVIZ layouts
│   ├── local_planner/          # Terrain analysis and path follower nodes
│   └── sensor_scan_generation/ # Processes point cloud scans
└── utilities/
    ├── transform_sensors/      # Rotates LiDAR/IMU data and filters chassis reflections
    └── unitree_pkgs/           # Unitree Go2 SDK message interfaces and helpers
```

---

## 4. Key Files to Audit & Read

To understand the core software implementation details, review the following source files:

### ⚙️ Sensor Transforms & Pre-processing
* **`src/utilities/transform_sensors/transform_sensors/transform_everything.py`:**
  * *What it does:* Subscribes to raw LiDAR and IMU feeds. Applies a `15.1°` pitch rotation to align the physical tilted mount. Removes self-reflections using a chassis-level bounding box. Re-stamps all headers to resolve ROS 2 network delays.

### 🎮 Joystick & Direct Manual Control
* **`src/utilities/unitree_pkgs/go2_sport_api/src/vel_ctrl_repub.cpp`:**
  * *What it does:* Bypasses planning entirely. Maps gamepad axis movements directly to `SportClient::Move()` commands and publishes them to `/api/sport/request` at `100 Hz`.

### 🚀 Waypoint Following & Controller Loops
* **`src/base_autonomy/local_planner/src/pathFollower.cpp`:**
  * *What it does:* The main movement controller. Subscribes to local paths and calculates lookahead yaw/speed.
  * *Important logic:*
    * Lines 300-305: Initializes autonomous speed limits.
    * Lines 312-392: Traces paths and computes forward/lateral velocity corrections.
    * Lines 429-438: Evaluates `is_real_robot` parameter. If true, wraps and publishes raw DDS commands to the real Go2, else publishes standard `/cmd_vel` Twist messages.

### 🗺️ Terrain Analysis
* **`src/base_autonomy/local_planner/src/terrainAnalysis.cpp`:**
  * *What it does:* Evaluates point cloud height variances to check slope gradients and step heights. Critical for preventing the robot from falling over when climbing obstacles.
