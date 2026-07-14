# Literature Reviews & SOTA Analysis

This directory stores state-of-the-art audits, research paper reviews, and academic design decisions.

---

## 1. Directory Contents

* **[[docs/literature_reviews/autonomy_stack_go2/autonomy_stack_go2_audit|CMU Autonomy Stack Go2 Repository Audit]]** - Deep audit of CMU's Go2 autonomy stack, including SDK usage, SLAM transforms, and control loops.
* **[[docs/literature_reviews/autonomy_stack_go2/simulation_guide|Unity-ROS 2 Simulation Setup Guide]]** - Detailed simulation architecture guide for running the Unity/ROS 2 bridge.
* **[[docs/literature_reviews/autonomy_stack_go2/real_robot_tutorial|Real-Robot Tutorial Guide]]** - Step-by-step instructions for physical deployment, network configuration, and calibration on Go2.
* **[[docs/literature_reviews/autonomy_stack_go2/cmu_autonomy_stack_overview|CMU Stack Architecture Overview]]** - Core methodologies, SDK functions, package maps, and key files to read for manual processing.
* **[[docs/literature_reviews/FAST_LIO_LOCALIZATION_HUMANOID/audit_report|FAST_LIO_LOCALIZATION_HUMANOID Audit Report]]** - Technical audit of CMU/DeepGlint localization stack, covering project structure, state updates, TF pipelines, and bugs.
* **[[docs/literature_reviews/FAST_LIO_LOCALIZATION_HUMANOID/localization_config_guide|Localization Configuration Guide]]** - Config parameters, sensor configurations, and launch guidelines for G1/Go2 deployment.
* **[[docs/literature_reviews/unitree-go2-slam-nav2/audit_report|unitree-go2-slam-nav2 Audit Report]]** - Technical audit of RTAB-Map SLAM, Nav2 costmaps, Twist velocity bridging node, and frontier exploration.
* **[[docs/literature_reviews/thesis_analysis/review_report|Thesis Review: Wilhelm (2025)]]** - Technical comparison of the Wilhelm (2025) thesis with our system design, requirements, and verification.
* **[[docs/literature_reviews/thesis_analysis/calibration_and_loopholes|Thesis Review: Calibration & Loopholes]]** - Detailed analysis of LiDAR-IMU/Camera calibration math, Jetson bottlenecks, and gait anomalies.
* **`legged_robots_industrial_inspection.md` (Pending):** SOTA review of legged deployments (Spot, ANYmal) mapping environmental parameters (oily surfaces, high-voltage rooms, dynamic layouts) to structural designs.
* **`lidar_slam_leaderboard_reviews.md` (Pending):** Review of top-ranking algorithms on the KITTI Odometry leaderboard, detailing CPU/memory footprints and multi-LiDAR support.

---

## 2. Collaborative Workflow
* **Suggested Drafts:** The developer will outline candidates and core parameters.
* **Manual Research:** The user will find and add citations (replacing `[User Citation Needed]` placeholders) before finalized selections are locked.
