# Specification: System Engineering & Documentation (`system-engineering`)

## 1. Overview & Objectives
This track establishes the system engineering foundation for the Unitree Go2 Smart Inspection robot. The objectives are:
* **System Decomposition:** Define modular ROS 2 nodes, sub-modules, and standard APIs.
* **State Machine Design:** Model the robot's high-level behavioral states and transitions (idle, mapping, navigating, safe-mode, error recovery).
* **System Requirements & Verification:** Map functional requirements to validation methods (simulation, rosbag replay, physical robot tests).
* **Literature & SOTA Analysis:** Review existing industrial legged robot deployments (ANYmal, Spot) to document design decisions (e.g., legged vs. wheeled, SLAM methods).
* **LLM-Friendly SDK Wrapper:** Create intermediate structured documents (e.g., JSON/YAML or highly-formatted Markdown) listing Go2 SDK commands, API endpoints, parameters, and topics to make the system easily searchable and programmable by AI agents and developers.

## 2. Requirements & Validation Criteria
Each requirement must be verified by a corresponding test or validation method:
* **REQ-SYS-001 (Modular API):** Core navigation and SLAM interfaces must use standard ROS 2 messages (`nav_msgs/Odometry`, `sensor_msgs/PointCloud2`). *Validation:* Static C++ API checks and ROS 2 launch graph schema tests.
* **REQ-SYS-002 (State Machine):** The robot must transition between states (Mapping, Navigating, Safe-Mode) without deadlocks or unhandled exceptions. *Validation:* State machine unit tests in Python (mocking inputs/outputs).
* **REQ-SYS-003 (Stair & Terrain Traversal):** The robot must recognize stairs and multi-level platforms, avoiding impossible terrain. *Validation:* Costmap layer tests and elevation map simulator tests.
* **REQ-SYS-004 (Glass/Obstacle Handling):** The perception pipeline must filter out false returns from glass or transparent structures. *Validation:* Offline replay validation of PointCloud filters on dynamic/glass targets.
* **REQ-SYS-005 (LLM SDK Directory):** Intermediate documents must provide an indexed representation of Go2 SDK commands, topics, and parameters. *Validation:* LLM utility query script test (retrieving command syntax successfully).

> [!NOTE]
> **Iterative Deliverables:**
> This track establishes three core interactive design files:
> 1. `docs/architecture/key_questions.md` - Open engineering challenges and research queries.
> 2. `docs/architecture/morphological_diagram.md` - Component option matrix.
> 3. `docs/architecture/tradeoff_analysis.md` - Design trade-offs.
> These files are iterative. We will draft choices and options, leaving them open for user manual research and citations to resolve before moving to code implementation.

## 3. Modular Architecture (Proposed Modules)
* **`go2_control_node` (C++):** Wraps high-level Go2 SDK commands (`SportClient`), publishing odometer states and subscribing to `geometry_msgs/Twist`. It inherits from/extends standard ROS 2 SDK wrapper classes to maintain API compatibility.
* **`go2_slam_node` (C++):** Tightly-coupled LiDAR SLAM. Swappable backend (candidate: FAST-LIO2 or LIO-SAM).
* **`go2_perception_node` (C++):** Filters point clouds (e.g., glass filtering, ground extraction) and produces costmaps.
* **`go2_navigation_node` (Python/C++):** Interfaces with Nav2, managing path planning, obstacle avoidance, and stair traversal.
* **`go2_state_orchestrator` (Python):** Executes the state machine, coordinating navigation tasks and diagnostic reports.

> [!IMPORTANT]
> **Out-of-Scope Components:**
> 1. Low-level joint/actuator control (FOC parameter tuning, direct motor torque/angle commands) is out of scope; control relies entirely on high-level SDK locomotion commands.
> 2. Environmental manipulation (D1 manipulator arm joint/cartesian trajectory planning) is out of scope.
> 3. Active person following (UWB companion tracking) is out of scope.

## 4. Literature Analysis Scope
Analyze:
1. "ANYmal in the Field: Solving Industrial Inspection..." -> Focus on environmental constraints (HVDC, dynamic obstacles) and sensor setup.
2. "Mobile Structural Health Monitoring Based on Legged Robots..." -> Focus on structural inspection payloads, sensor weights, and SLAM stability on stairs.
3. Custom-process other research papers from the `literature/` directory to document design trade-offs.

## 5. LLM-Friendly SDK Wrapper Specification
Compile documentation from `Go2_Documentation/` (e.g., `All_Go2_Developer_Docs.md`, `README.md`) into:
* `go2_sdk_api_reference.json`: A structured index of all SDK commands, ROS2 topics, arguments, default values, and description strings.
* `go2_commands_summary.md`: A cheat sheet optimized for rapid vector search and LLM context window ingestion.
