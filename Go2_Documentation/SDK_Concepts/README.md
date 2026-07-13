# SDK Concepts Index & Registry

This directory contains the structured, processed documentation of core SDK concepts, hardware capabilities, and communication topologies for the Unitree Go2. It is optimized for developers and LLMs to query system behaviors and interfaces.

---

## 1. Directory Mapping & Content Index

To read specific hardware or software architecture definitions, reference the processed documents below:

### [[Go2_Documentation/SDK_Concepts/01_system_architecture]]
* **What is in it:** System architecture diagrams, Cloud IoT interfaces (MQTT & WebRTC turn servers), Bluetooth BLE security pairing, DDS middleware with ROS 2 compatibility, serial data streams forwarding, and standard basic control blocks.
* **Original raw files:**
  * [[Go2_Documentation/archive/SDK_Concepts/Architecture_Description]]
  * [[Go2_Documentation/archive/SDK_Concepts/Robot_Dog_Application/Basic_Application]]
  * [[Go2_Documentation/archive/SDK_Concepts/Robot_Dog_Application/DDS_Application]]

### [[Go2_Documentation/SDK_Concepts/02_network_topology]]
* **What is in it:** Detailed networking specifications (Wi-Fi STA, Wi-Fi AP, and 4G fallback priorities), Bluetooth-based pairing workflows, and step-by-step setup guides for both bound and unbound devices.
* **Original raw file:**
  * [[Go2_Documentation/archive/SDK_Concepts/Robot_Dog_Application/Network_Application]]

### [[Go2_Documentation/SDK_Concepts/03_lidar_and_vision]]
* **What is in it:** Unitree L1 LiDAR specs (hemispherical scanning direction, TOF lasers), Unilidar SDK point cloud parser, distortion removal mapping, 2.5D height map construction for foot placement, 3D voxel maps, WebRTC streaming, and gesture view switching.
* **Original raw files:**
  * [[Go2_Documentation/archive/SDK_Concepts/Robot_Dog_Application/LiDAR_Application]]
  * [[Go2_Documentation/archive/SDK_Concepts/Robot_Dog_Application/Image_Application]]

### [[Go2_Documentation/SDK_Concepts/04_locomotion_states]]
* **What is in it:** Cartesian coordinate definitions (X-front, Y-left, Z-up), joint clearance parameters, state machine priority switching (Damping, Standing Lock, Balanced Stand, Locomotion, Special actions, rollover Protection), and gait profiles (Trot, Trot-Run, Climb Stairs).
* **Original raw file:**
  * [[Go2_Documentation/archive/SDK_Concepts/Robot_Dog_Application/Motion_Application]]

### [[Go2_Documentation/SDK_Concepts/05_uwb_and_diagnostics]]
* **What is in it:** UWB tag/base station vector positioning, button configurations, companion following modes (slow/fast), wearing placement alignments, and system fault classifications (System, Behavior, Application faults) with recovery reboot rules.
* **Original raw files:**
  * [[Go2_Documentation/archive/SDK_Concepts/Robot_Dog_Application/UWB_Application]]
  * [[Go2_Documentation/archive/SDK_Concepts/FAULTS]]

---

## 2. Smart Inspection Project Connections

* **Network STA Setup (`02_network_topology.md`):** Allows local network connection to the factory intranet to stream navigation updates to the supervisor center.
* **Distortion Free Maps (`03_lidar_and_vision.md`):** Removing motion distortion from point clouds is critical to construct accurate SLAM PCD maps when patrolling at trot-run speeds.
* **Coordinate Transformations (`04_locomotion_states.md`):** Coordinates (X-forward, Y-left, Z-up) correspond directly to the standard ROS `base_link` frame, establishing correct URDF offsets for sensor integration.
* **rollover Recoveries (`05_uwb_and_diagnostics.md`):** If system diagnostics report a critical motor fault or rollover in remote areas of the factory floor, the supervisor can schedule remote hard reboots.
