# Track Specification: repo-audit-autonomy-stack

## 1. Goal
Audit the `jizhang-cmu/autonomy_stack_go2` repository to understand CMU's implementation details, SDK usage, simulation setup, SLAM/navigation methodology, flaws, bugs, advantages, and identify how these insights improve or correct our current system documentation.

## 2. Requirements & Audit Scope
The audit must resolve:
* **SDK Usage & Compatibility:** What SDK version/methods were used? Is it compatible with our ROS 2 layout?
* **Simulation Setup:** How is simulation structured (e.g., Unity model, ROS-TCP-Endpoint)? Create a separate simulation guide.
* **Control Unification:** Is it possible to unify simulation and real-robot locomotion control code?
* **SLAM & Navigation Methodology:** Analyze Hong Kong University's Point-LIO SLAM integration and CMU's local planner.
* **Bugs & Limitations:** List known limitations (e.g., L1 LiDAR noise limits, SLAM drift, data lag).
* **Advantages & Inspired Design Points:** List critical design ideas we must adopt.
* **Documentation Corrections:** Audit existing system specifications for errors (e.g., LiDAR tilt angles, calibration steps).

## 3. Deliverables
* **[[docs/literature_reviews/autonomy_stack_go2_audit|Audit Report]]:** Detailed analysis answering all audit questions.
* **[[docs/literature_reviews/simulation_guide|Simulation Guide]]:** Standalone guide for running Unity/ROS 2 simulation.
