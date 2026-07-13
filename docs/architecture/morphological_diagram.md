# Subsystem Morphological Diagram

The morphological diagram compiles design options across the primary software subsystems.

---

## 1. Subsystem Option Matrix

| Subsystem | Option A | Option B (Proposed Default) | Option C |
| :--- | :--- | :--- | :--- |
| **SLAM Backend** | **FAST-LIO2** (Direct LiDAR-Inertial) | **LIO-SAM** (Graph-Optimization LIO) | **RTAB-Map** (Multi-Session Loop Closures) |
| **Ground plane Filter** | **RANSAC** (Random Sample Consensus) | **PatchWork++** (Fast Ground Segmentation) | **Ray-Ground Filter** (Angular segment binning) |
| **Local Costmap** | **2D GridMap** (Nav2 Standard) | **Octomap** (3D Voxel Grid) | **Voxblox** (Truncated Signed Distance) |
| **Local Planner** | **DWB** (Dynamic Window Approach) | **TEB** (Timed-Elastic-Band) | **MPPI** (Model Predictive Path Integral) |
| **State Machine** | **SMACH** (ROS Python State Machine) | **py_trees** (Behavior Trees) | **Custom Transition Class** (State loop) |

---

## 2. Option Selection & Status

### SLAM Backend Selection
* *Current Preference:* **Option B (LIO-SAM)** or **Option A (FAST-LIO2)**.
* *Why:* Real-time operation on Orin NX requires highly efficient, tightly-coupled state estimation.
* *User Verification & Citation:* [User Citation Needed - compare computational loads of FAST-LIO2 vs LIO-SAM on Jetson boards]

### Ground Plane Filter Selection
* *Current Preference:* **Option B (PatchWork++)**.
* *Why:* Superior ground estimation on non-flat terrains (stairways, slopes) compared to standard RANSAC.
* *User Verification & Citation:* [User Citation Needed]

### Local Planner Selection
* *Current Preference:* **Option C (MPPI)**.
* *Why:* High-performance trajectory generation around dynamic factory obstacles (forklifts, workers) using GPU/Orin vector operations.
* *User Verification & Citation:* [User Citation Needed]
