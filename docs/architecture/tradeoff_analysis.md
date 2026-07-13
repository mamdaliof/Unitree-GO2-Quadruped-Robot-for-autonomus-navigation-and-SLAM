# Design Choices Trade-Off Analysis

This document compiles technical evaluations of competing design alternatives across SLAM, perception, and path planning modules.

---

## 1. SLAM Backend Trade-Off Matrix

We compare the three primary candidate algorithms for real-time 3D localization and mapping on the Go2's Orin NX processor:

| Metrics | Option A: FAST-LIO2 | Option B: LIO-SAM | Option C: RTAB-Map |
| :--- | :--- | :--- | :--- |
| **Computational Overhead** | **Very Low** (Direct formulation, no feature extraction) | **Medium** (Feature extraction + factor graph optimization) | **High** (Visual-LiDAR multi-modal graph management) |
| **Accuracy on Slopes/Stairs** | **High** (Tight integration of IMU high-frequency states) | **High** (Factor graphs constrain z-drift) | **Medium** (Prone to z-drift if loop closures fail) |
| **Loop Closure Support** | **No** (Odometry only, requires secondary backend like SC-AGO) | **Yes** (Integrated keyframe loop closures) | **Yes** (Robust visual/point cloud loop closure detection) |
| **Memory Footprint** | **Very Small** | **Medium** | **Large** (Stores keyframe databases) |

### Trade-off Evaluation:
* **FAST-LIO2** is computationally lightweight, leaving more Orin GPU headroom for perception filters and Nav2. However, it lacks built-in loop closure.
* **LIO-SAM** offers a robust middle ground, containing loop closure but requiring distinct feature extraction steps.
* *Citation Placeholder:* [User Citation Needed - compare drift percentage in long runs]

---

## 2. Local Trajectory Planner Trade-Off Matrix

We compare planners for guiding the Go2's high-level velocity commands around dynamic obstacles:

| Metrics | Option A: TEB Local Planner | Option B: MPPI Local Planner |
| :--- | :--- | :--- |
| **Dynamic Obstacle Avoidance** | **Medium** (Local optimization can get stuck in local minima) | **High** (Samples hundreds of trajectories, avoids local minima) |
| **Computational Overhead** | **Low** (Runs on single CPU core) | **High** (Requires GPU acceleration for parallel sampling) |
| **Stair/3D Path Compatibility** | **Low** (Primarily designed for 2D differential drives) | **High** (Can cost-weight 3D velocities and roll/pitch limits) |

### Trade-off Evaluation:
* **TEB** is easy to tune and runs efficiently on CPU, but fails in complex crowds.
* **MPPI** is highly suited for quadruped velocity generation on non-flat terrain, leveraging the Jetson's GPU cores for real-time trajectory sampling.
* *Citation Placeholder:* [User Citation Needed]
