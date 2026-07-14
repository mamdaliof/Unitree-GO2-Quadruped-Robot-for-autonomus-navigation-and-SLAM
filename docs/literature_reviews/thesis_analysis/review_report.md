# Thesis Review Report: Wilhelm (2025) UCF

This report analyzes the thesis *"Autonomous Navigation and Real-Time 3D Reconstruction of Interior Spaces Using a Quadruped Robot"* (Steve Wilhelm, 2025, University of Central Florida) and compares its system engineering process, requirements, and state estimation choices with our current project.

---

## 1. System Engineering & Architecture Comparison

| Architectural Aspect | Wilhelm (2025) Setup | Our Go2 Stack Setup | Comparison & Impact |
| :--- | :--- | :--- | :--- |
| **Robot Platform** | Unitree Go2 EDU with Expansion Dock | Unitree Go2 Edu with Expansion Dock | Identical hardware platform. |
| **3D SLAM / Odom** | LIO-SAM (Shan et al.) & DLIO (Chen et al.) | Point-LIO / FAST-LIO2 | LIO-SAM requires tight LiDAR-IMU time sync. DLIO is lighter but fails in narrow hallways. |
| **2D SLAM** | SLAM Toolbox (converted 3D points to 2D scan) | SLAM Toolbox / Nav2 Map Server | Both project 3D clouds to 2D scans using `pointcloud_to_laserscan`. |
| **Local Planner** | DWB Local Planner (default Nav2) | DWB Local Planner | DWB planner is suitable for omnidirectional quadruped walking. |
| **Kinematics Model**| `nav2_amcl::OmniMotionModel` | `nav2_amcl::OmniMotionModel` | Omnidirectional motion allows the quadruped to strafe sideways around obstacles. |

---

## 2. Requirements & Verification Comparison

### Wilhelm (2025) Requirements:
1. **Real-time 3D reconstruction:** Generate high-fidelity point clouds of interior spaces during motion.
2. **Autonomous Navigation:** Navigate hallways using a 2D occupancy grid map generated on-the-fly.
3. **Data Logging:** Record raw sensor topics (IMU, LiDAR, Odometry) via `rosbag2` for offline refinement.

### Our Verification Plan Comparison:
* **Gaps Identified:** Wilhelm's setup struggled with mapping quality when using only the built-in Unitree L1 LiDAR with SLAM Toolbox, requiring an expensive top-mounted Hesai XT32 LiDAR for 3D reconstruction.
* **Low-Altitude Obstacle Detection:** Due to top-mounted LiDAR placement, objects below $0.3\text{ m}$ directly in front of the robot were not detected. Our system requirements must explicitly address this using the front camera or head-mounted L1 LiDAR data fusion.

---

## 3. Workflow Adaptation Recommendations
* **3D-to-2D Point Cloud Slicing:**
  Configure the `pointcloud_to_laserscan` node with strict vertical height bounds (e.g., $0.1\text{ m}$ to $1.0\text{ m}$ relative to `base_link`) to capture walls and large obstacles while discarding floor reflections and high ceiling structures.
* **Offloaded Visualization:**
  Keep the onboard processor dedicated entirely to ROS driver nodes, LIO state estimation, and data compression. Offload RViz or Foxglove visualization to a remote PC via a high-bandwidth network to prevent onboard CPU starvation.
