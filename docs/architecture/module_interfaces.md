# ROS 2 Module Interfaces & API Specifications

This document defines the complete C++ class signatures, fields, methods, responsibilities, and ROS 2 communication topics for the core packages in the Go2 navigation and SLAM workspace.

---

## 1. C++ Package: `go2_navigation` (Core Interfaces)

The package **[go2_navigation](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/src/go2_navigation/)** defines the abstract base interfaces. Subsystem implementation packages implement these headers to maintain modularity.

### 1.1 Robot Control Interface (`RobotInterface`)
* **Header file:** **[robot_interface.hpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/src/go2_navigation/include/go2_navigation/robot_interface.hpp)**
* **Class Responsibility:** Abstracts robot platform motion commands, posture stances, high-level status readings, and MCF lease switches.

#### Class Methods and Responsibilities:
| Method Name | Return Type | Parameter(s) | Responsibility / Description |
| :--- | :--- | :--- | :--- |
| **`Init()`** | `bool` | None | Establishes communication links with the robot SDK client. Returns `true` if connected. |
| **`Move()`** | `bool` | `vx: double`, `vy: double`, `vyaw: double` | Translates velocity commands. If real robot, serializes into SDK CycloneDDS packets and publishes to `/api/sport/request`. If simulation, publishes Twist messages. |
| **`StopMove()`** | `bool` | None | Halts the robot instantly, clearing active velocity inputs and locking joints in a standing stance. |
| **`StandUp()`** | `bool` | None | Commands the robot to transition from a sitting position to a standing inspection stance. |
| **`StandDown()`** | `bool` | None | Commands the robot to sit down safely to enter a low-stiffness standby rest state. |
| **`SwitchGait()`** | `bool` | `gait_mode: int` | Changes active gait models (e.g., `0` = Stance, `1` = Trot, `2` = Trot-Run, `3` = Climb). |
| **`SetBodyHeight()`** | `bool` | `height: double` | Vertically adjusts the chassis center height relative to the default standing stance. |
| **`GetRobotState()`** | `bool` | `state: RobotState &` | Populates the output state structure with battery SoC, temperatures, active mode, and calibration flags. |
| **`SetSilent()`** | `bool` | `silent: bool` | Set `true` to switch MCF motion controller silent, leasing control to developer nodes. Set `false` to release lease. |
| **`SetPublishingParameters()`** | `void` | `ros_twist: bool`, `unitree_dds: bool` | Parameterizes output stream publishing (supports standard Twist, raw DDS, or double-publishing both). |

---

### 1.2 Sensor Management Interface (`SensorInterface`)
* **Header file:** **[sensor_interface.hpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/src/go2_navigation/include/go2_navigation/sensor_interface.hpp)**
* **Class Responsibility:** Generic base interface for physical payloads (LiDAR, IMU, cameras). Sub-classes manage specialized streams and filters.

#### Class Methods and Responsibilities:
| Class & Method Name | Return Type | Parameter(s) | Responsibility / Description |
| :--- | :--- | :--- | :--- |
| **`SensorInterface::Init()`** | `bool` | None | Establishes connections to the hardware interface sockets. |
| **`SensorInterface::Start()`** | `bool` | None | Spawns receiver threads to start streaming sensor data frames. |
| **`SensorInterface::Stop()`** | `bool` | None | Closes socket streams and terminates active data ingestion loops. |
| **`SensorInterface::IsActive()`** | `bool` | None | Returns `true` if the sensor receiver thread is executing without errors. |
| **`LidarInterface::GetPointCloud()`** | `bool` | `cloud: PointCloud2 &` | Ingests the latest 3D scan points frame from the queue. |
| **`LidarInterface::ApplySelfFilter()`**| `bool` | `in: PointCloud2`, `out: PointCloud2 &` | Spatial bounding box filter. Drops scan coordinates intersecting the robot's legs and body to avoid obstacle confusion. |
| **`ImuInterface::GetIMUData()`** | `bool` | `imu: Imu &` | Ingests the latest linear acceleration and angular velocity readings. |

---

### 1.3 SLAM and Mapping Interface (`SLAMInterface`)
* **Header file:** **[slam_interface.hpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/src/go2_navigation/include/go2_navigation/slam_interface.hpp)**
* **Class Responsibility:** Manages mapping runs, global PCD map loading/saving persistence, and global localization estimators.

#### Class Methods and Responsibilities:
| Method Name | Return Type | Parameter(s) | Responsibility / Description |
| :--- | :--- | :--- | :--- |
| **`Init()`** | `bool` | None | Initializes SLAM odometry estimators, ICP matching grids, and TF trees. |
| **`StartMapping()`** | `bool` | None | Triggers active mapping loop to construct a global point cloud. |
| **`StopMapping()`** | `bool` | None | Terminates map construction and freezes the point cloud grid. |
| **`SaveMap()`** | `bool` | `path: string` | Serializes and writes the constructed point cloud map to a `.pcd` file on disk. |
| **`LoadMap()`** | `bool` | `path: string` | Loads a pre-existing PCD map file into localization memory. |
| **`UpdateMap()`** | `bool` | `cloud: PointCloud2 &` | Continuously refines the active loaded map representation using new LiDAR frames. |
| **`Localize()`** | `bool` | `pose: PoseStamped &` | Performs scan matching of incoming point clouds against the loaded map to output global 6-DoF coordinates. |
| **`CheckKidnapStatus()`** | `bool` | None | Evaluates scan registration fitness. If alignment score drops below threshold, raises a kidnap flag. |

---

### 1.4 Path Planning and Goal Selection Interface (`PlannerInterface`)
* **Header file:** **[planner_interface.hpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/src/go2_navigation/include/go2_navigation/planner_interface.hpp)**
* **Class Responsibility:** Tracks costmaps, maps collision-free global paths, calculates local avoidance velocities, and filters autonomous exploration frontiers.

#### Class Methods and Responsibilities:
| Method Name | Return Type | Parameter(s) | Responsibility / Description |
| :--- | :--- | :--- | :--- |
| **`Init()`** | `bool` | None | Loads navigation parameters, costmap sizing, and target limits. |
| **`UpdatePose()`** | `void` | `pose: PoseStamped` | Receives the latest global coordinates from the active SLAM localization process. |
| **`UpdateGridMap()`** | `void` | `map: OccupancyGrid` | Receives the latest 2D global occupancy grid map updates from SLAM. |
| **`UpdateCostmap()`** | `bool` | `cloud: PointCloud2` | Ingests raw/filtered point cloud frames to update local costmap obstacle layers. |
| **`ComputeGlobalPath()`** | `bool` | `start: PoseStamped`, `goal: PoseStamped`, `path: Path &` | Calculates a path of collision-free waypoints from start to goal. |
| **`ComputeLocalVelocity()`** | `bool` | `pose: PoseStamped`, `path: Path`, `cmd_vel: TwistStamped &` | Translates the path into local linear and angular velocity commands (DWA/TEB). |
| **`GenerateFrontierGoals()`**| `bool` | `frontier_goals: vector &` | Scans the occupancy grid to generate coordinates along boundaries between mapped and unmapped sectors. |
| **`FilterGoalsByFOV()`** | `bool` | `goals: vector`, `filtered: vector &` | Filters and prioritizes goal candidates falling inside the forward 100° field of view (FOV). |

---

## 2. ROS 2 Communication Topics Specification

To connect the nodes implementing these interfaces, the system uses standard ROS 2 topic interfaces:

| Topic Name | Message Format | Publisher Node | Subscriber Node | Description |
| :--- | :--- | :--- | :--- | :--- |
| **`/cmd_vel`** | `geometry_msgs/msg/TwistStamped` | Orchestrator / Planner | `go2_control_node` | High-level commanded linear/angular velocities. |
| **`/api/sport/request`** | `unitree_api/msg/Request` | `go2_control_node` (Real) | Onboard MCF Controller | CycloneDDS motion switcher/sport packets sent to SDK. |
| **`/lidar/points_raw`** | `sensor_msgs/msg/PointCloud2` | `L1Lidar` / `L2Lidar` | `go2_perception_node` | Raw point cloud sweeps. |
| **`/lidar/points_filtered`**| `sensor_msgs/msg/PointCloud2` | `go2_perception_node` | SLAM / Planner | Point cloud with chassis/leg self-reflections removed. |
| **`/imu/data`** | `sensor_msgs/msg/Imu` | `RobotImu` | `go2_slam_node` | High-frequency IMU linear acceleration/angular rate. |
| **`/slam/pose`** | `geometry_msgs/msg/PoseStamped`| `go2_slam_node` | Orchestrator / Planner | Localized 6-DoF position in the active map frame. |
| **`/slam/map`** | `nav_msgs/msg/OccupancyGrid` | `go2_slam_node` | Planner / Rviz2 | Generated 2D occupancy grid map for navigation. |
| **`/slam/map_pcd`** | Action Service | `go2_slam_node` | Orchestrator | Action callback to save baseline map PCD. |
| **`/diagnostics`** | `diagnostic_msgs/msg/DiagnosticArray` | All Nodes | Orchestrator | Reports node execution frequency, sensor drop, and battery states. |
