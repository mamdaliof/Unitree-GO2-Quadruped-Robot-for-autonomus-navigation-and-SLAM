# Subsystem Morphological Diagram

The morphological diagram organizes the design options and engineering combinations available for each system module.

---

## 1. Subsystem Option Matrix

| Subsystem | Option A | Option B (Proposed Default) | Option C |
| :--- | :--- | :--- | :--- |
| **SLAM / Odom Backend** | **FAST-LIO2** (Tightly-coupled direct LIO) | **LIO-SAM** (Factor graph LIO) | **RTAB-Map** (Multi-modal loop closures) |
| **Ground Plane Filter** | **RANSAC** (Plane fit segmentation) | **PatchWork++** (Fast uneven segmentation) | **Pass-Through** (Simple height cutoff) |
| **Control Interface** | **SportClient (Velocity)** (Command `cmd_vel` rates) | **SportClient (Absolute)** (Absolute coordinate nav) | **SportClient (Relative)** (Incremental path offsets) |
| **Avoidance & Planning**| **Default SDK Avoidance** (Built-in obstacle avoidance) | **Nav2 TEB Planner** (Custom Timed-Elastic-Band) | **Nav2 MPPI Planner** (Custom GPU-sampled paths) |
| **State Machine** | **Custom State Loop** (Simple python transition code) | **py_trees** (Behavior Tree framework) | **SMACH** (ROS 2 state machine package) |
| **Vision & Thermal** | **No Cameras (Phase 1)** | **RGB Projection** (2D image mapping on PCD) | **Thermal Projection** (3D heat reconstruction) |
| **Diagnostics & Profiling** | **Standard Logging** (ROS 2 stdout log files) | **Verbose Debug Mode** (Debug logs + block process times) | **Performance Profiling** (Dynamic profiling via Tracy/Perf) |

---

## 2. Option Selection & Discussion

### SLAM / Odom Backend
* *Selection:* **FAST-LIO2** or **LIO-SAM** (To be iterated during Phase 2 tests).
* *Why:* Real-time computation on the Orin NX requires efficient LIO state estimation.
* *User Verification & Citation:* [User Citation Needed]

### Control Interface
* *Selection:* **All Options (A, B, C)**.
* *Why:* Navigation needs raw velocity inputs (`cmd_vel`), but autonomous mapping tasks benefit from relative/absolute coordinates.
* *User Verification & Citation:* [User Citation Needed]

### Avoidance & Planning
* *Selection:* **Option A (Default SDK)** as primary; **Option B/C (Custom Nav2)** as fallback.
* *Why:* We try the built-in Go2 obstacle avoidance first to keep things simple. If it fails in complex corridors, we implement custom Nav2 paths.
* *User Verification & Citation:* [User Citation Needed]

### Diagnostics & Profiling
* *Selection:* **Option B (Verbose Debug Mode)**.
* *Why:* Monitoring execution/process times of specific code blocks is critical to diagnose performance bottlenecks without the heavy overhead of continuous profiling tools.
* *User Verification & Citation:* [User Citation Needed]

