# Initial Concept

Smart inspection system for manufacturing setups using Unitree Go2 edu robot that should be able to navigate, and use SLAM with different sensors like two lidars, vision, depth, thermal camera, IMU (we can choose them later) for navigation and localization and mapping

# Product Guide: Unitree Go2 Smart Inspection System

## 1. Project Vision
Create a robust localization, mapping, and safe autonomous navigation system using the Unitree Go2 Edu quadruped robot for manufacturing and assembly setups. The primary objective is establishing precise localization and safe traversal in dynamic, multi-level, and complex industrial environments.

## 2. Architecture & Design Principles
* **Modular ROS 2 Architecture:** The software stack will run on ROS 2. Each subsystem (SLAM, Navigation, Perception, State Machine) is a separate module with strict, standard API definitions for inputs and outputs.
* **Onboard AI Processing:** Utilize the onboard Nvidia Jetson processor for heavy computational tasks (real-time SLAM, point cloud processing, and AI/deep learning workloads).
* **Future-Proof Extensibility:** Architecture must allow drop-in additions of new features (e.g., LiDAR-based object detection, thermal profiling, semantic segmentation) without restructuring the core navigation stack.

## 3. Environment & Constraints
* **Physical Layout:** Automotive assembly / heavy machinery plants. Includes multi-level floors requiring stair traversal and strictly defined out-of-bounds / impossible zones.
* **Environmental Challenges:** Large open floors, metallic structures, dynamic obstacles (forklifts, workers), glass walls/partitions (which pose severe SLAM challenges), variable lighting, and high noise.
* **Operational Mode:** One-time high-fidelity mapping during deployment, followed by continuous map refinement, change detection, and high-precision real-time localization.

## 4. Incremental Sensor & SLAM Roadmap
Development will follow an incremental sensor integration strategy:
1. **Phase 1 (Simplest):** Single LiDAR mapping and basic odometry.
2. **Phase 2 (LiDAR + IMU):** Tightly-coupled LIO (LiDAR-Inertial Odometry) for smoother motion estimation and robust tracking.
3. **Phase 3 (Dual LiDAR + IMU):** Incorporating a secondary LiDAR to eliminate blind spots and improve point cloud density in complex manufacturing spaces.
4. **Phase 4 (Multi-Modal Fusion):** Adding Vision, Depth, and Thermal sensors for advanced change detection and obstacle categorization.

## 5. Phase 1 Focus: System Engineering & Documentation
The current phase focuses on system design, structural planning, and documentation:
* **Product Requirements:** Detailing system specifications, sensor configurations, and safety constraints.
* **Architectural Structure:** Mapping out project directories, software modules, and dependency trees.
* **State Machines:** Defining system state transitions (e.g., Idle, Mapping, Navigation, Emergency Stop, Docking).
* **Two-Step Repository Audits:** 
  1. *Initial Scan:* Review existing repositories to analyze what others have done, their configurations, and why they used specific approaches.
  2. *Verification Scan:* Review existing repositories a second time at the end of the phase to validate our proposed architecture, requirements, and methods against real-world implementations to identify flaws or gaps.
* **LLM-Friendly Documentation:** Structuring existing Go2 developer documentation, commands, and API arguments into a standard, clean, intermediate format that is easily parseable and queryable by LLMs and humans.
* **Workflow & Verification:** Detailing how features are implemented with associated unit tests.

## 6. Reference Studies & Target Environments
* **Review of Legged Robots in Industry:** Process existing works (e.g., ANYmal in offshore platforms, Spot in manufacturing) to analyze design choices, limitations, and advantages.
* **Validation Sites:** Cube, basement, and AMC (Advanced Manufacturing Center).
