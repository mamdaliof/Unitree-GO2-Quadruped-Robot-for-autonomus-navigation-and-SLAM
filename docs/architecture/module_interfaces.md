# ROS 2 Module Interfaces & API Specifications

This document defines the complete C++ class signatures, fields, methods, and ROS 2 communication topics for the core packages in the Go2 navigation and SLAM workspace.

---

## 1. Package: `go2_navigation` (Core Interfaces)

The package **[go2_navigation](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/src/go2_navigation/)** is a standard ROS 2 C++ interface package. It defines the abstract base interfaces implemented by concrete driver, sensor, mapping, and planning components.

### 1.1 Robot Control Interface (`RobotInterface`)
* **Header file:** **[robot_interface.hpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/src/go2_navigation/include/go2_navigation/robot_interface.hpp)**
* **Purpose:** Establishes the API boundaries for platform locomotion control, stands, and MCF lease switching.
* **C++ Interface Class Signature:**
  ```cpp
  namespace go2_navigation {
    struct RobotState {
      float battery_percentage;
      float CPU_temperature;
      float CPU_load;
      std::string active_locomotion_mode;
      bool is_calibrated;
    };

    class RobotInterface {
    public:
      using SharedPtr = std::shared_ptr<RobotInterface>;
      virtual ~RobotInterface() = default;
      virtual bool Init() = 0;
      virtual bool Move(double vx, double vy, double vyaw) = 0;
      virtual bool StopMove() = 0;
      virtual bool StandUp() = 0;
      virtual bool StandDown() = 0;
      virtual bool SwitchGait(int gait_mode) = 0;
      virtual bool SetBodyHeight(double height) = 0;
      virtual bool GetRobotState(RobotState & state) = 0;
      virtual bool SetSilent(bool silent) = 0;
      virtual void SetPublishingParameters(bool publish_ros_twist, bool publish_unitree_dds) = 0;
    protected:
      bool publish_ros_twist_{true};
      bool publish_unitree_dds_{false};
    };
  }
  ```

### 1.2 Sensor Management Interface (`SensorInterface`)
* **Header file:** **[sensor_interface.hpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/src/go2_navigation/include/go2_navigation/sensor_interface.hpp)**
* **Purpose:** Provides a generic abstraction for launching, checking, and reading raw payload sensors (LiDARs, IMU, cameras).
* **C++ Interface Class Signatures:**
  ```cpp
  namespace go2_navigation {
    class SensorInterface {
    public:
      using SharedPtr = std::shared_ptr<SensorInterface>;
      virtual ~SensorInterface() = default;
      virtual bool Init() = 0;
      virtual bool Start() = 0;
      virtual bool Stop() = 0;
      virtual bool IsActive() const = 0;
      virtual std::string GetSensorName() const = 0;
      virtual std::string GetSensorType() const = 0;
    };

    class LidarInterface : public SensorInterface {
    public:
      using SharedPtr = std::shared_ptr<LidarInterface>;
      virtual bool GetPointCloud(sensor_msgs::msg::PointCloud2 & cloud) = 0;
      virtual bool ApplySelfFilter(
        const sensor_msgs::msg::PointCloud2 & input,
        sensor_msgs::msg::PointCloud2 & output) = 0;
    protected:
      double filter_box_min_x_{-0.7};
      double filter_box_max_x_{-0.1};
      double filter_box_min_y_{-0.3};
      double filter_box_max_y_{0.3};
      double filter_box_min_z_{-0.6};
      double filter_box_max_z_{0.0};
    };

    class ImuInterface : public SensorInterface {
    public:
      using SharedPtr = std::shared_ptr<ImuInterface>;
      virtual bool GetIMUData(sensor_msgs::msg::Imu & imu) = 0;
    };
  }
  ```

### 1.3 SLAM and Mapping Interface (`SLAMInterface`)
* **Header file:** **[slam_interface.hpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/src/go2_navigation/include/go2_navigation/slam_interface.hpp)**
* **Purpose:** Standardizes the API to run offline mapping runs, save map PCD files, trigger global localization estimation, and monitor slips (kidnapping watchdogs).
* **C++ Interface Class Signature:**
  ```cpp
  namespace go2_navigation {
    class SLAMInterface {
    public:
      using SharedPtr = std::shared_ptr<SLAMInterface>;
      virtual ~SLAMInterface() = default;
      virtual bool Init() = 0;
      virtual bool StartMapping() = 0;
      virtual bool StopMapping() = 0;
      virtual bool SaveMap(const std::string & path) = 0;
      virtual bool LoadMap(const std::string & path) = 0;
      virtual bool UpdateMap(const sensor_msgs::msg::PointCloud2 & cloud) = 0;
      virtual bool Localize(geometry_msgs::msg::PoseStamped & pose) = 0;
      virtual bool CheckKidnapStatus() = 0;
    protected:
      std::string active_map_path_;
      bool is_mapping_active_{false};
      bool is_localization_active_{false};
      bool kidnap_detected_{false};
      double fitness_threshold_{0.9};
    };
  }
  ```

### 1.4 Path Planning and Goal Selection Interface (`PlannerInterface`)
* **Header file:** **[planner_interface.hpp](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/src/go2_navigation/include/go2_navigation/planner_interface.hpp)**
* **Purpose:** Establishes boundaries for path generation, local dynamic avoidance velocity calculations, costmap updates, and autonomous exploration goal filtering.
* **C++ Interface Class Signature:**
  ```cpp
  namespace go2_navigation {
    class PlannerInterface {
    public:
      using SharedPtr = std::shared_ptr<PlannerInterface>;
      virtual ~PlannerInterface() = default;
      virtual bool Init() = 0;
      virtual void UpdatePose(const geometry_msgs::msg::PoseStamped & pose) = 0;
      virtual void UpdateGridMap(const nav_msgs::msg::OccupancyGrid & map) = 0;
      virtual bool UpdateCostmap(const sensor_msgs::msg::PointCloud2 & cloud) = 0;
      virtual bool ComputeGlobalPath(
        const geometry_msgs::msg::PoseStamped & start,
        const geometry_msgs::msg::PoseStamped & goal,
        nav_msgs::msg::Path & path) = 0;
      virtual bool ComputeLocalVelocity(
        const geometry_msgs::msg::PoseStamped & current_pose,
        const nav_msgs::msg::Path & path,
        geometry_msgs::msg::TwistStamped & cmd_vel) = 0;
      virtual bool GenerateFrontierGoals(
        std::vector<geometry_msgs::msg::PoseStamped> & frontier_goals) = 0;
      virtual bool FilterGoalsByFOV(
        const std::vector<geometry_msgs::msg::PoseStamped> & goals,
        std::vector<geometry_msgs::msg::PoseStamped> & filtered_goals) = 0;
    protected:
      double sensor_fov_degrees_{100.0};
      bool prefer_forward_goals_{true};
      double loop_closure_weight_{0.5};
      geometry_msgs::msg::PoseStamped current_pose_;
      nav_msgs::msg::OccupancyGrid current_map_;
    };
  }
  ```

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
