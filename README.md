# Unitree Go2 Quadruped Robot for Autonomous Navigation and SLAM

This repository contains the system engineering, workspace packages, and structured developer documentation for implementing safe autonomous navigation, localization, and SLAM on the Unitree Go2 Edu quadruped robot.

---

## 📂 Repository Structure

* [[Go2_Documentation/index|Go2_Documentation/]] - Cleaned, restructured developer documentation, including:
  * [[Go2_Documentation/System_Overview/README|System Overview]] - Model specs, ethernet wiring, pilot LED codes, and environment FAQs.
  * [[Go2_Documentation/Application_Development/README|Application Development]] - Compilation directives, custom node setups, and mounting guides.
  * [[Go2_Documentation/SDK_Concepts/README|SDK Concepts]] - Network topologies, LiDAR mapping systems, and stance states.
  * [[Go2_Documentation/Software_Interface_Services/README|Software Interface Services]] - Low-level IDLs, sports API methods, and manipulator controls.
  * [[Go2_Documentation/Case_reference/README|Case Reference]] - C++ communication code blocks, trajectory mathematics, and simulation guides.
* [[conductor/index|conductor/]] - System engineering specs, state machine layouts, and Conductor track files.
* [[daily-reports/|daily-reports/]] - Daily logs tracking development milestones and design choices.

---

## 🛠 Quick Start

### 1. Hardware Connection & Setup
1. Connect your computer to the Unitree Go2 robot using an Ethernet cable.
2. Configure your Ethernet network adapter to a static IP address in the robot's subnet:
   - **IP Address:** `192.168.123.99` (or any free IP on the `192.168.123.X` subnet, except the robot's default IPs)
   - **Netmask:** `255.255.255.0`
   - **Gateway:** `192.168.123.1`

### 2. SLAM Backend & LiDAR Configuration
Before launching, configure your desired sensors and SLAM backend inside [go2_config.json](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/go2_config.json):
*   **Select active LiDAR:** Set `"active_lidars"` under `"sensors"` to `"L1"` or `"L2"`.
*   **Select active SLAM algorithm:** Set `"slam_backend"` under `"system"` to `"Point-LIO"` or `"A-LOAM"`.

### 3. Launching the System
Open a terminal and run the unified bringup launch script. This starts the raw sensor publishers, launches the configured SLAM algorithm, and opens RViz2:

```bash
# Source the ROS 2 Jazzy and workspace installations
source /opt/ros/jazzy/setup.bash
source packages/install/setup.bash

# Launch the system bringup
ros2 launch go2_bringup mapping_unilidar_launch.py
```

### 4. Manual Operation & Mapping
1. Put the robot in manual standby/walk mode using the physical Unitree remote controller.
2. Slowly move the robot around. The point cloud stream will update the global map inside the RViz2 window in real-time.
3. If `"debug_mode"` is enabled in the configuration, a rosbag recording (`debug_bag`) will automatically start in the background to record raw sensor and mapping feeds.

### 5. Interactive Map Saving
To save the generated map as a binary PCD file at any time, run:
```bash
ros2 service call /save_map std_srvs/srv/Trigger {}
```
The map will be exported to the target path configured by `map_save_path` (or `map.pcd` by default).

---

For detailed code architecture notes, refer to the [[docs/architecture/slam_oop_integration|SLAM & OOP Collaboration Architecture]]. For remote execution guides, refer to the [[docs/application_development/remote_execution_guide|Remote Execution & Jetson Setup Guide]]. For further mounting, environment, or SDK details, refer to the [[Go2_Documentation/index|Go2 Developer Documentation Index]].
