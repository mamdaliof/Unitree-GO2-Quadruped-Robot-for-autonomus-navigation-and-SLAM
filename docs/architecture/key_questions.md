# Key System Engineering Questions & Research Fields

This document tracks unresolved engineering questions, design ambiguities, and active areas of research required to implement the autonomous navigation stack.

---

## 1. Active Research Questions

### ❓ Question 1: LiDAR Glass Reflection Mitigation
* **Context:** Industrial plants contain glass partitions and doors. Standard 905nm LiDARs (like the Livox Mid-360) either pass through glass (creating ghost points behind it) or receive specular reflections (creating false obstacle structures).
* **Research Field:** Point cloud intensity and intensity return ratio profiling.
* **Suggested Approach:** Filter points based on intensity thresholds (specular returns typically show low return energy compared to solid walls).
* **Open Tasks / User Citations:** Find literature on "Livox Mid-360 glass filtering algorithms" and industrial lidar reflections.
  * *Citation Placeholder:* [User Citation Needed]

### ❓ Question 2: Legged Locomotion Stair Height Limits
* **Context:** The Go2 must patrol multi-level floors. The built-in trotting gait has height thresholds.
* **Research Field:** Elevation mapping step-climbing tolerances.
* **Suggested Approach:** The Go2 Edu specification notes a maximum step height of `16 cm`. Stair treads must be evaluated via elevation maps before commanding gait transitions.
* **Open Tasks / User Citations:** Look up Spot or ANYmal stair navigation step-clearance margins.
  * *Citation Placeholder:* [User Citation Needed]

### ❓ Question 3: Odometry Drift Fusion under Slippage
* **Context:** Wet or oily factory floors cause foot slippage, corrupting foot contact odometry.
* **Research Field:** Legged state estimation and EKF covariance matching.
* **Suggested Approach:** Dynamically adapt the foot contact covariance in the state estimator based on IMU acceleration discrepancy checks (if IMU shows zero forward acceleration but leg joint velocity shows 1.0 m/s, flag slippage).
* **Open Tasks / User Citations:** Find literature on "quadruped state estimation slip detection covariance tuning".
  * *Citation Placeholder:* [User Citation Needed]
