# Development Workflow: Unitree Go2 Smart Inspection

## 1. Branching Strategy (Git Flow)
We adhere to a strict Git Flow model:
* **`main`:** Contains production-ready, validated code. Every commit to `main` must be tagged with a version.
* **`develop`:** Integration branch for active features. All feature branches branch from and merge back into `develop`.
* **`feat/...` & `bugfix/...`:** Short-lived branches for individual components, modules, or bug fixes.

## 2. Interactive Alignment & Review Checkpoints
To ensure the developer remains fully aware of all technical details:
* **Track-Level Kickoff & Review:** Before spawning a Conductor track, align on high-level goals. Upon track completion, present a technical report before merging.
* **Per-Module Design Alignment:** Prior to coding any new ROS 2 node or algorithm block, outline the API, ROS 2 topics/services, and class designs in a chat thread to confirm the implementation strategy.
* **Interactive Check-ins:** Periodic Q&A milestones during implementation to review intermediate designs and resolve blockers.

## 3. Testing & Verification Lifecycle
Every change must go through a three-stage verification process:
* **Stage 1 (Pre-Merge Local Check):** The developer must execute all unit tests (`gtest` and `pytest`) locally and verify code formatting (`clang-format` and `black`).
* **Stage 2 (Manual Verification):** Before merging to `develop`, verify the changes. This includes:
  * Verification on the physical Go2 robot, simulator, or offline log replay.
* **Stage 3 (Post-Merge Check):** Once a branch is merged into `develop` or `main`, run automated tests to ensure no regressions occur.

## 4. Hardware Safety & Validation Protocol
* **Rosbag Playback (Optional/Conditional):** If compatible pre-recorded LiDAR/IMU rosbag datasets are available, use them to validate SLAM, odometry, and filtering logic offline.
* **Simulation Testing (Optional/Conditional):** If the Gazebo/Webots simulator is set up, run navigation and behavior trees in simulation first.
* **Hardware Safe-Mode (On-Robot Test):** When running new control or navigation code on the physical Go2, operate in safe-mode: low speed, open workspace, and with an active remote kill-switch / manual controller override at hand.

## 5. SLAM Evaluation & Benchmark Auditing
* **KITTI Leaderboard Review:** Before locking in a SLAM package (e.g. during Phase 2), compile a list of top-performing LiDAR/LIO algorithms on the KITTI Odometry leaderboard.
* **Compatibility Check:** Filter these candidates based on:
  1. Multi-LiDAR support (matching our Phase 3 Dual-LiDAR requirements).
  2. Computational overhead (must run in real-time under Orin NX limits).
  3. ROS 2 compilation compatibility.
* **Morphological Update:** Add these benchmark candidates to our morphological and trade-off diagrams for review before final implementation.
