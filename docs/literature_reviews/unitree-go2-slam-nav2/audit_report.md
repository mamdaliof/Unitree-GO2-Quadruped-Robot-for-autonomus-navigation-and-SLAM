# CMU/Naderi Unitree-Go2 SLAM & Nav2 Audit Report

## 1. Executive Summary
This report presents a technical audit of the `h-naderi/unitree-go2-slam-nav2` repository, which integrates RTAB-Map SLAM and ROS 2 Nav2 on the Unitree Go2 quadruped robot. The repository showcases three primary systems: a Twist-to-SDK velocity command bridging node (`go2_cmd_processor`), a standard LiDAR-based RTAB-Map configuration (`go2_slam_nav`), and a custom Python-based autonomous frontier exploration node (`frontier`).

---

## 2. Project Architecture & Components
The repository is divided into four main packages:
1. **`go2_cmd_processor`**: Bridges standard ROS 2 Twist velocity commands to Unitree Go2 Sport SDK requests.
2. **`go2_slam_nav`**: Contains RTAB-Map SLAM, Nav2 parameter files (`nav2_params.yaml`), and launch orchestration scripts.
3. **`frontier`**: An autonomous exploration package implementing a border-pushing frontier discovery algorithm.
4. **`image_processing`**: Provides ancillary vision nodes (e.g., facial recognition).

---

## 3. Command Velocity Bridging (`sport_ctrl.py`)
The `sport_ctrl` node is a ROS 2 Python node bridging control commands to the physical robot:
* **Twist Translation:** Subscribes to `cmd_vel` and translates linear x, linear y, and angular z into JSON parameters for the Go2 Sport SDK `Request` topic (`/api/sport/request`, API ID `1008` for Move).
* **Safety Watchdog Timer:**
  - Runs a high-frequency timer callback (default `200Hz`).
  - If no new `cmd_vel` messages are received within `cmd_vel_timeout` (default `0.25` seconds), it publishes an Idle command (API ID `0`). This prevents the robot from walking indefinitely in the event of controller disconnect.
* **Command Interfaces:** Exposes standard `std_srvs/srv/Empty` services for `stand_up`, `lay_down`, `damping`, `dance1`, and `dance2` mapped directly to their respective SDK API IDs.

---

## 4. Nav2 Parameters & Costmap Configuration
The `nav2_params.yaml` configures navigation behavior:
* **AMCL Kinematics Model:** Configured as `nav2_amcl::OmniMotionModel` because quadrupeds possess omnidirectional locomotion (strafing sideways) unlike differential-drive platforms.
* **DWB Local Planner Limits:** Limits are set conservatively:
  - Max linear velocity: `0.15` m/s (both X and Y directions).
  - Max angular velocity: `1.0` rad/s.
* **Costmap Layers:**
  - Local Costmap: Uses `voxel_layer` subscribing to `/rslidar_points` (PointCloud2) and `/scan` (LaserScan) to compile obstacles in a 3m x 3m rolling window.
  - Global Costmap: Subscribes to the same sources, building static and obstacle maps inside the global `map` frame.
  - Footprint: Defined as `[ [0.410, 0.350], [0.410, -0.350], [-0.410, -0.350], [-0.410, 0.350] ]` representing the Go2 physical chassis outline.

---

## 5. RTAB-Map SLAM & ICP Odometry
* **ICP Odometry Node:** Uses `rtabmap_odom::icp_odometry` to estimate the `odom` to `base_link` frame using `/rslidar_points`.
* **ICP Parameterization:**
  - Uses `Icp/PointToPlane` (`true`), `Icp/Iterations` (`10`), and `Icp/VoxelSize` (`0.1` m) to match sequential LiDAR sweeps.
* **Slam Configuration:**
  - Uses `rtabmap_slam::rtabmap` to perform global loop closure.
  - Toggles between Mapping and Localization based on the `localize_only` launch argument, setting `Mem/IncrementalMemory` to `false` for localization-only mode.

---

## 6. Frontier-Based Autonomous Exploration (`frontier_update2.py`)
The `frontier` package implements a custom, lightweight Python node for autonomous mapping:
* **Frontier Generation:**
  - Subscribes to `/map` (OccupancyGrid). It extracts cells with value `0` (free space) that are adjacent to `-1` (unknown space).
  - Performs `scipy.ndimage.binary_erosion` on the free-space map to ensure candidates lie safely inside navigable space (obstacle avoidance).
* **Goal Filtering (Sensor FOV):**
  - Filters candidates to ensure they lie within the robot's forward field-of-view (`SENSOR_FOV` = $100^\circ$ arc).
  - Chooses the farthest valid candidate from the robot to "push" the exploration boundary outward.
* **Execution Loop:**
  - Periodically publishes selected goals to `goal_pose` every `5.0` seconds to drive the Nav2 stack.

---

## 7. Morphological & Design Decisions Integration
The insights gathered from this audit should be added as alternatives in our system engineering documentation:
* **Control Abstraction:** The python-based Twist-to-SDK `/api/sport/request` bridge (`sport_ctrl.py`) is a lightweight alternative to full ROS 2 C++ wrapper drivers.
* **Exploration Strategy:** The custom `frontier_update2` node provides a pure Python NumPy/SciPy exploration method, bypassing resource-heavy C++ action servers.
* **Odometry Backend:** RTAB-Map ICP Odometry represents a valid alternative to FAST-LIO2/Point-LIO for structured environments.
