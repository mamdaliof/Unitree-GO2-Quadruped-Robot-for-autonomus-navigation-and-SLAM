# Technology Stack: Unitree Go2 Smart Inspection

## 1. Core Platform & Middleware
* **Operating System:** Ubuntu 24.04 LTS (Noble Numbat) on Nvidia Jetson processor.
* **Middleware:** ROS 2 Jazzy Jalisco.
* **DDS Implementation:** Cyclone DDS or Fast DDS (standard ROS 2 configurations).

## 2. Programming Languages
* **C++ (C++20 standard):** Used for performance-critical modules: LiDAR SLAM, point cloud pre-processing, real-time sensor drivers, and high-frequency control loops.
* **Python (3.12+):** Used for high-level orchestration, state machine execution (e.g., using Behavior Trees or Simple State Machines), AI model integration (object detection/thermal evaluation), and testing scripts.

## 3. Modular API & Subsystem Strategy
To allow flexible switching of algorithms (e.g., swapping SLAM backends or navigation planners) during the research phase, the codebase will implement strict API boundaries:
* **Perception & SLAM API:** Abstracts point cloud input and outputs odometry + map representation. Candidate backends include FAST-LIO2, LIO-SAM, or custom LiDAR SLAM.
* **Low-Level Control API:** Standardized ROS 2 interfaces (e.g., geometry_msgs/Twist, joint state subscribers) to abstract the Unitree Go2 SDK/ROS2 wrapper, allowing simulation or different SDK versions.
* **Orchestration API:** High-level services and action interfaces for inspection workflow execution.

## 4. Testing, Formatting & Tooling
* **C++ Testing:** Google Test (`gtest`) integrated with `ament_cmake_gtest` for unit testing C++ nodes.
* **Python & Integration Testing:** `pytest` and `launch_testing` to verify multi-node ROS 2 launch graphs and Python orchestrators.
* **Code Style Formatting:**
  * **C++:** `clang-format` (Google style guide).
  * **Python:** `black` formatter.
