# Software Interface Services Index & Registry

This directory contains the processed, structured documentation of the software service interfaces, DDS message topics, and hardware payload control clients for the Unitree Go2 Edu. It is optimized for both human development and LLM context queries.

---

## 1. Directory Mapping & Content Index

To find details about specific services, error codes, and configuration parameters, refer to the processed files below:

### [[Go2_Documentation/Software_Interface_Services/01_low_level_interface]]
* **What is in it:** IDL structures for motor FOC commands (`LowCmd_`, `MotorCmd_`), battery controller packets (`BmsCmd_`), real-time actuator state telemetry (`LowState_`, `MotorState_`), IMU states, BMS cell voltage arrays, and auxiliary client controls.
* **Original raw files:**
  * [[Go2_Documentation/archive/Software_Interface_Services/Basic_Services_Interface]]
  * [[Go2_Documentation/archive/Software_Interface_Services/RobotStateClient_Interface]]
  * [[Go2_Documentation/archive/Software_Interface_Services/VuiClient_Interface]]

### [[Go2_Documentation/Software_Interface_Services/02_motion_control_modes]]
* **What is in it:** High-level locomotion API clients (`SportClient`), posture adjustments (Euler angles, body height), gait configuration toggles (Trot, Trot-Run, Climb Stairs), and the `MotionSwitcherClient` RPC interface used to toggle MCF (Motion Control Service) lease ownership.
* **Original raw files:**
  * [[Go2_Documentation/archive/Software_Interface_Services/Sports_Services_Interface]]
  * [[Go2_Documentation/archive/Software_Interface_Services/Motion_Services_Interface_V2.0]]
  * [[Go2_Documentation/archive/Software_Interface_Services/Motion_Switcher_Service_Interface]]

### [[Go2_Documentation/Software_Interface_Services/03_slam_and_navigation]]
* **What is in it:** Onboard SLAM navigation client JSON schemas, transformation matrices for Mid-360 and XT-16 LiDARs relative to the body IMU origin, API IDs (Start/End mapping, Initialize Pose, Pause/Resume), and DDS topic telemetry formats.
* **Original raw file:**
  * [[Go2_Documentation/archive/Software_Interface_Services/SLAM_and_Navigation_Services_Interface]]

### [[Go2_Documentation/Software_Interface_Services/04_perception_and_odom]]
* **What is in it:** Raw LiDAR range-finding data models (`utlidar`), point cloud subscribers, odometer estimation variables (`OdomState_`), and the obstacle avoidance service parameters.
* **Original raw files:**
  * [[Go2_Documentation/archive/Software_Interface_Services/LiDAR_Services_Interface]]
  * [[Go2_Documentation/archive/Software_Interface_Services/Odometer_Services_Interface]]
  * [[Go2_Documentation/archive/Software_Interface_Services/Avoidance_Services_Interface]]

### [[Go2_Documentation/Software_Interface_Services/05_developer_bridges]]
* **What is in it:** Native ROS 2 Jazzy workspace setups, Python bindings, custom DDS interface configurations (`cyclonedds.xml`), and multi-robot domain settings.
* **Original raw files:**
  * [[Go2_Documentation/archive/Software_Interface_Services/ROS2_Services_Interface]]
  * [[Go2_Documentation/archive/Software_Interface_Services/Python_Services_Interface]]
  * [[Go2_Documentation/archive/Software_Interface_Services/DDS_Services_Interface]]

### [[Go2_Documentation/Software_Interface_Services/06_manipulator_and_payloads]]
* **What is in it:** Mechanical D1 manipulator arm kinematics and trajectories, GStreamer (GST) and RTSP video feeds, UWB companion commands, automatic Aruco recharging pile alignments, and fault monitoring clients.
* **Original raw files:**
  * [[Go2_Documentation/archive/Software_Interface_Services/D1_Mechanical_Arm_Services_Interface]]
  * [[Go2_Documentation/archive/Software_Interface_Services/Multimedia_Services_Interface]]
  * [[Go2_Documentation/archive/Software_Interface_Services/UWB_Services_Interface]]
  * [[Go2_Documentation/archive/Software_Interface_Services/Fault_Services_Interface]]
  * [[Go2_Documentation/archive/Software_Interface_Services/AI_motion_Services_interface]]
  * [[Go2_Documentation/archive/Software_Interface_Services/Aruco_Recharge_Service_Interface]]

---

## 2. Smart Inspection Project Connections

* **Low-Level Actuation (`01_low_level_interface.md`):** Used to read motor temperature and battery SoC parameters to trigger return-to-dock sequences.
* **Locomotion Mode Lease (`02_motion_control_modes.md`):** We must lease the motion controller or switch it to silent state before executing custom step trajectories or starting navigation sweeps.
* **SLAM Alignment (`03_slam_and_navigation.md`):** Hardcodes coordinates for Mid-360 LiDAR relative to body center, eliminating calibration guessing. Provides API commands to construct and save PCD factory floor maps.
* **Python Bridges (`05_developer_bridges.md`):** Allows writing rapid testing scripts in Python to command stand heights or check lidar packet drop frequencies.
* **Camera Feeds (`06_manipulator_and_payloads.md`):** FPV video streaming via RTSP is used to capture visual feature data for automated anomaly detection.
