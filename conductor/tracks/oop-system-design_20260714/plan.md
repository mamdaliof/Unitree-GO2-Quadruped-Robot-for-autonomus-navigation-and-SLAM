# Implementation Plan: OOP Architecture & System Engineering Enhancements

## Phase 1: Requirements and Validation Matrix Updates
- [ ] Task: Update `docs/requirements/system_requirements.md` with:
  - REQ-FUN-009: Locomotion Mode Control (Normal Mode Lock)
  - REQ-FUN-006: Hardware Time-Sync Check enhancement
  - REQ-FUN-003: Locomotion Commands (Unified cmd_vel and SDK DDS Sport Mode double-publishing)
  - REQ-SFT-002: Safety Watchdog (0.25s timeout), empty path halt, tilt limit checks, and kidnap detection (ICP fitness < 0.9)
  - REQ-FUN-010: Autonomous Exploration FOV preferences and Loop Closure goals
- [ ] Task: Update `docs/requirements/validation_matrix.md` with verification test mappings for the 5 new requirements.
- [ ] Task: Conductor - User Manual Verification 'Phase 1' (Protocol in workflow.md)

## Phase 2: Technical Decisions, Research, and Brainstorming
- [ ] Task: Research other methods and latest Go2 SDK documentation for locomotion mode locking.
- [ ] Task: Research other methods for hardware time-sync validation and sensor offset synchronization.
- [ ] Task: Research options for control command double-publishing.
- [ ] Task: Create `docs/architecture/technical_decisions.md` containing research, Go2 SDK compatibility, and detailed trade-off tables for:
  - Locomotion Mode Lock vs. Dynamic Height/Pitch Estimation
  - Hardware PTP/NTP vs. Software Timestamp Offset Estimation
  - ROS 2 Twist Bridge vs. Custom DDS Client Republisher
  - Obstacle Fusion / Bounding Box Self-Filtering Bounds
  - Kidnap Detection and Recovery Thresholds
- [ ] Task: Conductor - User Manual Verification 'Phase 2' (Protocol in workflow.md)

## Phase 3: OOP Abstractions and UML Architecture
- [ ] Task: Design C++ abstract base classes in namespace `go2_navigation` for:
  - `RobotInterface`
  - `SensorInterface`
  - `SLAMInterface`
  - `PlannerInterface`
- [ ] Task: Generate UML class diagrams showing inheritances, relationships, fields, and virtual methods.
- [ ] Task: Conductor - User Manual Verification 'Phase 3' (Protocol in workflow.md)

## Phase 4: API Specifications and Per-Module Documentation
- [ ] Task: Create `docs/architecture/module_interfaces.md` detailing the complete C++ class signatures, class fields, virtual methods, and ROS 2 topic names/types.
- [ ] Task: Create per-module markdown files explaining details, rules, and operations:
  - `docs/architecture/modules/robot_interface.md`
  - `docs/architecture/modules/sensor_interface.md`
  - `docs/architecture/modules/slam_interface.md`
  - `docs/architecture/modules/planner_interface.md`
- [ ] Task: Conductor - User Manual Verification 'Phase 4' (Protocol in workflow.md)

## Phase 5: Testing Skeletons & Mock-Based Unit Tests
- [ ] Task: Implement template C++ Google Test / Google Mock (gmock) testing skeletons.
- [ ] Task: Implement template Python unit test mock skeletons.
- [ ] Task: Conductor - User Manual Verification 'Phase 5' (Protocol in workflow.md)
