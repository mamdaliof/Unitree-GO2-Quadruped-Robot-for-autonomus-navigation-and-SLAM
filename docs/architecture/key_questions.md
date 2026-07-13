# Key Questions & Pending Research

This document outlines active engineering questions and fields that require research and validation before final implementation.

---

## ❓ Question 1: How to Measure/Validate the 5 cm Localization Error?
* **Problem:** We target a localization error $< 5\text{ cm}$. We need a reliable method to measure and verify this error on the physical AMC factory floor.
* **Suggested Approaches:**
  1. **Ground Truth Comparison:** Use static high-precision retroreflective markers at known physical coordinates. The LiDAR scans the marker, detects the high-intensity return, and compares the calculated coordinates with the known survey ground truth.
  2. **Total Station / Laser Tracker:** External measurement of the robot's physical position during patrol.
* **Research Tasks:** Research methods for "LiDAR localization accuracy validation using retroreflective markers."
  * *Citation Placeholder:* [User Citation Needed]

---

## ❓ Question 2: What is the Maximum Allowable Slope Angle for LIO Mapping?
* **Problem:** While the Go2 mechanically climbs up to 40° slopes, steep angles cause rapid vertical (Z-axis) drift in standard LiDAR-Inertial Odometry (LIO) loops.
* **Suggested Approaches:**
  1. Test the slope limit in a simulated environment first.
  2. Constrain vertical drift by fusing the joint-kinematics z-state into the LIO factor graph during climbing phases.
* **Research Tasks:** Look up max pitch limits for FAST-LIO2 or LIO-SAM on steep terrain.
  * *Citation Placeholder:* [User Citation Needed]

---

## ❓ Question 3: Aligning Thermal Camera Feeds for 3D Heat Reconstruction
* **Problem:** The thermal camera is unstable for SLAM point alignment, but we need to generate a 3D thermal reconstruction of the environment.
* **Suggested Approaches:**
  1. Complete the baseline SLAM map using LiDAR and IMU first.
  2. Projects 2D thermal frames onto the pre-constructed 3D point cloud using extrinsic coordinate transforms (camera-to-lidar matrix).
* **Research Tasks:** Research "3D thermal reconstruction using LiDAR point clouds and extrinsic camera projections."
  * *Citation Placeholder:* [User Citation Needed]

---

## ❓ Question 4: Dynamic CPU Load & Frequency Scaling
* **Problem:** Heavy SLAM computations can cause Orin NX CPU throttling.
* **Suggested Approaches:**
  1. Dynamically scale the robot's maximum walking speed downward when CPU loads exceed 85%.
  2. Decrease the LiDAR point cloud voxel grid filter sampling rate to reduce computation when processing loads spike.
* **Research Tasks:** Research "dynamic CPU load balancing in ROS 2 navigation stacks."
  * *Citation Placeholder:* [User Citation Needed]

---

## ❓ Question 5: Which KITTI Leaderboard SLAM Candidate Best Fits Our Setup?
* **Problem:** We need to evaluate top-performing SLAM algorithms from the KITTI Odometry leaderboard, selecting candidates that support LiDAR-Inertial fusion and multi-LiDAR setups while running efficiently on the Orin NX.
* **Suggested Approaches:**
  1. Compile a list of top 5 KITTI LiDAR/LIO algorithms with open-source ROS 2 implementations (e.g., candidates like Kiss-ICP, FAST-LIO2, or CT-ICP).
  2. Map their memory footprint, GPU acceleration dependency, and z-drift parameters.
* **Research Tasks:** Audit the KITTI Odometry leaderboard for high-ranking LiDAR-only or LIO algorithms.
  * *Citation Placeholder:* [User Citation Needed]
