# Application Development Index & Registry

This directory contains the structured, processed documentation for Go2 application development, deployment, and payload integration. It is optimized for developers and LLMs to quickly locate SDK commands, configuration steps, and hardware parameters.

---

## 1. Directory Mapping & Content Index

To find a specific feature or command, refer to the mapped processed files below:

### [01_sdk_installation.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/Application_Development/01_sdk_installation.md)
* **What is in it:** System dependencies, `unitree_sdk2` download, compilation flags, network card adapter configurations (IP settings, checking `ifconfig` for subnet `123`), low-level examples, and instructions for suspending the robot.
* **Original raw files:** 
  * [Obtain_SDK.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Application_Development/Obtain_SDK.md)
  * [Quick_Start.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Application_Development/Quick_Start.md)

### [02_custom_apps.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/Application_Development/02_custom_apps.md)
* **What is in it:** Detailed API definition of `sport_client.hpp` (high-level posture and locomotion calls), step-by-step guide to writing custom C++ nodes (`app_height.cpp`), integrating them into `CMakeLists.txt`, and launching them with motion switcher lease control.
* **Original raw file:** 
  * [Creating_Customer_Application.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Application_Development/Creating_Customer_Application.md)

### [03_dock_and_jetson.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/Application_Development/03_dock_and_jetson.md)
* **What is in it:** Jetson Orin Nano vs. NX hardware specs (TOPS, frequencies, cores), display connections, module OTA updates via Web UI (`http://192.168.123.18`), USB Type-C power enablement GPIO fix (`rc.local`), USB 3.0 device tree updater (`unitree_update.sh`), NVMe disk flashing backups (`dd` commands), and factory download links.
* **Original raw file:** 
  * [Expansion_Dock_Configuration.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Application_Development/Expansion_Dock_Configuration.md)

### [04_payload_integration.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/Application_Development/04_payload_integration.md)
* **What is in it:** Power ports (XT30U-F, aviation plug, USB-A/C, 12V/5V outputs), rail dimensions, physical installation guides (mounting the expansion dock, D435i camera, Mid-360 / XT-16 LiDARs, servo arm), and the automatic docking/charging pile specification with LED signals.
* **Original raw file:** 
  * [Payload.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Application_Development/Payload.md)

### [05_app_and_rc.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/Application_Development/05_app_and_rc.md)
* **What is in it:** Mobile app configuration (hotspot AP and Wi-Fi modes, service monitoring), screen remote controller key layout, SIYI FPV cameras setup (IP mappings: `192.168.144.X`), text-to-speech voice broadcasts, thermal imaging gimbals, and IP conflicts lists.
* **Original raw files:** 
  * [App_Binding.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Application_Development/App_Binding.md)
  * [TouchScreen_RC_Supporting_Instructions.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Application_Development/TouchScreen_RC_Supporting_Instructions.md)

---

## 2. Project Connections (Why this matters for Smart Inspection)

We connect these deployment guidelines to our inspection goals:
1. **Network Adapter Binding (`01_sdk_installation.md`):** Essential for setting up our development workspace to communicate with the physical Go2 onboard computer without IP conflicts.
2. **Modular Custom Nodes (`02_custom_apps.md`):** This is the foundation of our ROS 2 wrapper, which uses the `SportClient` API to handle safe state machine locomotion.
3. **Jetson Performance (`03_dock_and_jetson.md`):** Validates the onboard computing budget (40/100 TOPS) for running point cloud filtering and SLAM pipelines locally on the Jetson NX.
4. **LiDAR/Camera Mounting (`04_payload_integration.md`):** Specifies the physical mount coordinates and electrical wiring for our Mid-360 LiDAR and depth camera payloads.
5. **Override Safety (`05_app_and_rc.md`):** Establishes SIYI FPV feed, voice alerts, and joystick remote overrides to prevent safety hazards during autonomous inspection runs.
