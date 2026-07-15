# Implementation Plan: SLAM Track

## Phase 1: Sensor Driver & Publisher Node Establishment
- [x] Task: Implement `L1Lidar` class inheriting from `SensorInterface`.
    - [x] Create L1Lidar class files.
    - [x] Implement abstract interface methods.
- [x] Task: Implement `L2Lidar` class inheriting from `SensorInterface`.
    - [x] Create L2Lidar class files.
    - [x] Implement abstract interface methods.
- [x] Task: Implement `RobotImu` class inheriting from `SensorInterface`.
    - [x] Create RobotImu class files.
    - [x] Implement abstract interface methods.
- [x] Task: Create ROS 2 Jazzy publisher node using these classes, reading names from `go2_config.json`.
    - [x] Parse configuration values.
    - [x] Set up publishers for IMU and LIDAR topics.
- [x] Task: Support processing sensor samples with specific timestamps/simulation time.
    - [x] Implement ROS 2 parameter support for `use_sim_time`.
- [ ] Task: Verify on the physical robot (Unitree Go2).
    - [ ] Deploy node and check `ros2 topic echo` output for L1 Lidar, L2 Lidar, and IMU.
    - [ ] Verify message timestamp synchronization.
- [ ] Task: Conductor - User Manual Verification 'Phase 1: Sensor Driver' (Protocol in workflow.md)

## Phase 2: Sensor Calibration & Logging
- [x] Task: Analyze and explain calibration algorithm from `autonomy_stack_go2`.
    - [x] Audit calibration code.
    - [x] Document algorithm in research log.
- [x] Task: Implement automatic startup calibration logic on automated mode.
    - [x] Detect mode on startup.
    - [x] Run calibration sequence.
- [x] Task: Log daily calibration parameters to `packages/src/go2_sensors/log`.
    - [x] Create logging mechanism directory/files.
    - [x] Format logs with timestamp and parameters.
- [x] Task: Implement configuration check to toggle calibration on/off via `go2_config.json`.
    - [x] Read calibration toggle parameters.
- [ ] Task: Verify calibration on the physical robot.
    - [ ] Put robot in automated mode, verify calibration runs on startup.
    - [ ] Check calibration log files generated in the specified directory.
    - [ ] Toggle calibration OFF in `go2_config.json` and verify it does not run.
- [ ] Task: Conductor - User Manual Verification 'Phase 2: Sensor Calibration' (Protocol in workflow.md)

## Phase 3: Point-LIO Integration & Map Management
- [ ] Task: Clone `point_lio_unilidar` repository into `packages/src/`.
    - [ ] Clone repository.
- [ ] Task: Compare cloned Point-LIO with `autonomy_stack_go2` point-lio, document findings.
    - [ ] Review structure and differences.
- [ ] Task: Support LIDAR selection (L1, L2, or both) in `go2_config.json`.
    - [ ] Modify launch files and point-lio node wrappers.
- [ ] Task: Wrap Point-LIO to save and load maps for localization and map enhancement.
    - [ ] Implement service/topic to request map save.
    - [ ] Implement map loading logic on startup.
- [ ] Task: Support rosbag recording for sensors and SLAM in debug mode.
    - [ ] Detect debug mode in launch.
    - [ ] Launch rosbag record process for relevant topics.
- [ ] Task: Verify Point-LIO on the physical robot.
    - [ ] Run SLAM with L1, L2, and Dual configuration on physical robot.
    - [ ] Move robot using manual remote control mode.
    - [ ] Verify real-time map generation and save/load functionality.
    - [ ] Enable debug mode and verify rosbag records sensor/odometry data correctly.
- [ ] Task: Conductor - User Manual Verification 'Phase 3: Point-LIO SLAM' (Protocol in workflow.md)

## Phase 4: A-LOAM Integration
- [ ] Task: Clone `A-LOAM` repository into `packages/src/`.
    - [ ] Clone repository.
- [ ] Task: Build A-LOAM and resolve ROS 2 Jazzy compatibility.
    - [ ] Adapt C++ code for Jazzy compile.
- [ ] Task: Verify A-LOAM on the physical robot.
    - [ ] Launch A-LOAM SLAM on physical robot and move manually.
    - [ ] Compare map consistency and CPU utilization with Point-LIO.
- [ ] Task: Conductor - User Manual Verification 'Phase 4: A-LOAM Integration' (Protocol in workflow.md)

## Phase 5: Physical Testing & Validation
- [ ] Task: Validate SLAM map generation in manual control mode.
    - [ ] Run manual validation steps.
- [ ] Task: Compile technical report on SLAM backends performance.
    - [ ] Collect metrics and write report.
- [ ] Task: Conductor - User Manual Verification 'Phase 5: Physical Validation' (Protocol in workflow.md)

