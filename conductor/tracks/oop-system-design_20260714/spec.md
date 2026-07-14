# Specification: OOP Architecture & System Engineering Enhancements

## Overview
This track enhances existing system engineering documents based on literature reviews and establishes a unified Object-Oriented Programming (OOP) architecture for the Go2 autonomy stack. It defines unified abstract base interfaces, UML class designs, API/topic specifications, technical decisions, and unit testing skeletons using mocks.

## Scope of Work

### 1. Requirements & Validation Enhancements
Explicitly integrate the following concepts from SOTA/literature reviews into `docs/requirements/system_requirements.md` and `docs/requirements/validation_matrix.md`:
* **Locomotion Mode Lock:** Force Go2 to "Normal Mode" at startup to eliminate dynamic height/pitch noise on LiDAR SLAM (Wilhelm 2025).
* **Hardware Time-Sync Check:** Require explicit hardware timestamp synchronization validation between LiDAR and IMU during setup (Wilhelm 2025).
* **Unified Control Output:** Support double-publishing (standard `cmd_vel` Twist vs. Unitree Sport DDS Request packet) switched by `is_real_robot` flag (CMU Autonomy Stack).
* **Safety Watchdog & Fail-Safes:**
  - 0.25s timeout watchdog to stop robot if control signals drop (Naderi).
  - Empty local path heartbeat and pitch/roll tilt limit checks to trigger emergency halt (CMU Autonomy Stack).
  - Kidnapped Robot Detection: halt transform updates and warn if global ICP alignment fitness < 0.9 (FAST_LIO_LOCALIZATION_HUMANOID).
* **Exploration FOV Preference & Loop Closure:** Target frontiers preferring the forward 100° FOV, fallback to rotation/sides if blocked. During deployment, prioritize unseen areas and plan paths to maximize loop closure opportunities.

### 2. OOP Architecture & UML Diagrams
* Establish a common namespace `go2_navigation` with C++ abstract base classes enforcing unified interfaces.
* Create/update UML class diagrams mapping core classes, methods, inheritances, and relationships.
* Define interfaces for:
  - `RobotInterface`: Handles SDK connection, locomotion mode lock, and cmd_vel publishing.
  - `SensorInterface`: Manages sensor streams, calibration data loading, and preprocessing (self-filter).
  - `SLAMInterface`: Performs odometry, map tracking, and kidnap detection.
  - `PlannerInterface`: Calculates global/local navigation paths and frontier goals.

### 3. API, Topic, & Per-Module Specifications
* Create `docs/architecture/module_interfaces.md` detailing the complete C++ class signatures, class fields, virtual methods, and ROS 2 topic names/types.
* Create a dedicated markdown file for each top module under `docs/architecture/modules/` explaining details, rules, and operations.

### 4. Technical Decisions & Brainstorming Document
* Create `docs/architecture/technical_decisions.md` containing:
  - Brainstorm and research of alternative methods (e.g. dynamic height/pitch estimation vs. locking locomotion mode; hardware PTP/NTP time sync vs. software timestamp offset estimation; ROS 2 twist bridge vs. custom DDS client republisher).
  - Go2 SDK latest documentation compatibility checks.
  - Detailed trade-off tables comparing alternative options.
  - Current status (Used / Not Used / Optional).

### 5. Unit Testing Skeletons
* Write template C++ Google Test / Google Mock (gmock) and Python unittest mock templates.
* Allow verifying top-level state machine entities and low-level drivers without physical hardware.

## Out of Scope
* Low-level motor joint level torque/position controllers.

## Acceptance Criteria
1. System requirements and validation matrices updated with the new literature review concepts.
2. `docs/architecture/module_interfaces.md` created with C++ signatures and topic specifications.
3. `docs/architecture/technical_decisions.md` created with brainstorm options, compatibility check, and trade-off tables.
4. Per-module documentation files created under `docs/architecture/modules/`.
5. UML class diagrams showing OOP design created and saved.
6. C++ (`gtest`/`gmock`) and Python mock test templates written in the code directory.
7. All newly added documentation compiles / renders cleanly.
