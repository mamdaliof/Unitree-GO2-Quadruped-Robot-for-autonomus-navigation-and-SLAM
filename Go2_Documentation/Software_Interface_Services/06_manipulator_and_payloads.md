# Manipulator Arm, Video Feeds & Auxiliary Payloads

This document covers programming interfaces for the D1 robotic arm, RTSP video streaming, UWB companion controls, automatic Aruco recharging alignments, and the fault diagnostic query client.

---

## 1. Reference Links to Archive Sources
For original method parameters and complete IDL files, refer to the archived guides:
* [Raw D1 Mechanical Arm Services Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/D1_Mechanical_Arm_Services_Interface.md)
* [Raw Multimedia Services Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/Multimedia_Services_Interface.md)
* [Raw UWB Services Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/UWB_Services_Interface.md)
* [Raw Fault Services Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/Fault_Services_Interface.md)
* [Raw AI Motion Services Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/AI_motion_Services_interface.md)
* [Raw Aruco Recharge Service Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/Aruco_Recharge_Service_Interface.md)

---

## 2. D1 Manipulator Arm Interface (`ArmClient`)

The D1 mechanical arm mounts on the Go2 expansion dock. Developers control the arm in joint space (6 DOF) or cartesian space via the `ArmClient` class:

* **`int32_t SetJointSpeed(const std::vector<double>& speed)`:** Commands rotational velocities to individual joint motors.
* **`int32_t MoveJoint(const std::vector<double>& target)`:** Commands joint positions.
* **`int32_t MoveCartesian(double x, double y, double z, double roll, double pitch, double yaw)`:** Moves the end-effector to target 3D coordinates.
* **`int32_t SetGripper(double position)`:** Opens or closes the gripper clamp (`0.0` = closed, `1.0` = open).

---

## 3. Multimedia RTSP & GStreamer Video Streaming

The Go2 head camera streams compressed video to the network using a GStreamer pipeline.

* **Default RTSP Endpoint:** `rtsp://192.168.123.161:8554/live`
* **Video Format:** H.264 encoded, 720p resolution at 30 FPS.

### Subscribing via GStreamer (Gst)
Use the following pipeline configuration to subscribe to the video stream in custom C++ or Python perception nodes:
```bash
rtspsrc location=rtsp://192.168.123.161:8554/live latency=100 ! rtph264depay ! h264parse ! avdec_h264 ! videoconvert ! appsink
```

---

## 4. UWB Companion & Aruco Recharging Services

### UWB Client (`UwbClient`)
* **`int32_t StartFollow()`:** Activates automatic operator tracking.
* **`int32_t StopFollow()`:** Deactivates companion tracking.

### Aruco Recharge Client (`RechargeClient`)
* **`int32_t StartArucoRecharge()`:** Commands the robot to search for the recharging pile marker (Aruco marker) and dock with the charging contact electrodes.
* **`int32_t GetRechargeState(int& state)`:** Returns docking alignment progress steps.

---

## 5. Fault Diagnostics Client (`FaultClient`)

The `FaultClient` queries system health, hardware error codes, and battery diagnostic logs:

* **`int32_t GetFaultList(std::vector<FaultState>& list)`:** Returns all active hardware or software fault reports.
* **`int32_t ClearFault(int code)`:** Manually acknowledges and clears warning flags.

---

## 6. Project Relevance
* **Visual Recharge Alignment:** In our smart inspection project, the state machine calls `StartArucoRecharge()` when battery levels drop below 15%, aligning the robot with the charging contacts using camera-based feedback.
* **Manipulator Inspection:** The D1 arm is commanded to point cameras at hard-to-reach machine parts during patrol runs.
