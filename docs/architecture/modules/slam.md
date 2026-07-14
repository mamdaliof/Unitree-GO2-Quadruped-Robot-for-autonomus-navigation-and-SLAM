# Module: `go2_slam` (Localization & Mapping)

This module handles 3D point cloud map generation (mapping run), global map persistence (saving/loading PCD files), and continuous localized pose calculation.

---

## 1. Subsystem Architecture

The SLAM package implements the abstract **[SLAMInterface](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/src/go2_navigation/include/go2_navigation/slam_interface.hpp)**:

* **`SLAMBackend` Implementation:** Interfaces with the active LiDAR Inertial Odometry (LIO) estimators and scan-matching registration engines (e.g. ICP point matching).

---

## 2. Operations & Execution Workflow

1. **Mapping Phase:** Commands `StartMapping()`. The robot is driven around the environment. Raw sweeps from the Lidar stream are registered into a unified point cloud map.
2. **Persistence:** Once mapping is completed, the node executes `SaveMap(path)`, saving a static `factory.pcd` map.
3. **Localization Phase (Deployment):** When executing inspection runs, the node calls `LoadMap(path)` to load the pre-recorded PCD map, and calls `Localize(pose)` to dynamically update the global pose estimation of the robot.
4. **Active Map Refinement:** Optionally calls `UpdateMap(cloud)` to continuously update the active map with new sensor sweeps to account for dynamic changes in the factory environment.

---

## 3. Operational Rules & Constraints

* **Kidnap Watchdog:** During localization, the node monitors the ICP scan-matching fitness score. If registration fitness falls below **`0.9`**, the node locks map coordinate updates, raises a kidnap flag, and triggers the orchestrator watchdog to halt the robot.
* **Network Buffers:** To handle high-bandwidth LiDAR streams without packet drops, the socket receive buffers on the host companion Jetson must be configured to at least `52,428,800` bytes (`net.core.rmem_max`).
