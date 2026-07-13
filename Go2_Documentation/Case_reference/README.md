# Case Reference Index & Registry

This directory contains the processed, structured documentation of reference routines and programming cases for the Unitree Go2 Edu. It is optimized for both human readability and LLM context extraction.

---

## 1. Directory Mapping & Content Index

Use this registry to quickly locate specific programming cases and implementations:

### [01_dds_communication.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/Case_reference/01_dds_communication.md)
* **What is in it:** Standard CycloneDDS publisher and subscriber C++ configurations, `ChannelFactory` bindings, custom IDL messages handling, and compiling simple helloworld communication routines.
* **Original raw file:**
  * [DDS_Communication.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Case_reference/DDS_Communication.md)

### [02_low_level_control.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/Case_reference/02_low_level_control.md)
* **What is in it:** Leg joint motor control (thigh, calf, hip FOC parameters), linear interpolation for joint transitions, sine-wave leg swinging example, motor state conversion functions (`lowCmd2Dds` / `dds2LowState`), and motor error bitmask decoding (overcurrent, thermal limits, encoder failure).
* **Original raw files:**
  * [Basic_Motion_Control.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Case_reference/Basic_Motion_Control.md)
  * [Exapmle_of_motor_errors.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Case_reference/Exapmle_of_motor_errors.md)

### [03_high_level_locomotion.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/Case_reference/03_high_level_locomotion.md)
* **What is in it:** `SportClient` high-level control nodes, testing modes (normal/balanced stands, velocity tracking, trajectory tracking, special actions like sit/flip), Euler/height ranges, and obtaining status variables.
* **Original raw file:**
  * [High_Motion_Control.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Case_reference/High_Motion_Control.md)

### [04_debugging_framework.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/Case_reference/04_debugging_framework.md)
* **What is in it:** Multithreaded control architectures (`RobotController`), state machine transitions (DAMPING, STAND, CTRL), safety termination triggers based on gravity vector projections, advanced gamepad button packaging (on-press/on-release edge detection), dead zones, and exponential smoothing filters.
* **Original raw files:**
  * [Deployment_Framework.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Case_reference/Deployment_Framework.md)
  * [Get_Remote_Control_Status.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Case_reference/Get_Remote_Control_Status.md)

### [05_auxiliary_services.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/Case_reference/05_auxiliary_services.md)
* **What is in it:** Headlight LED white brightness adjustment using the `VuiClient` class, and virtual reinforcement learning training pipelines using Isaac Gym, CUDA, PyTorch, and `unitree_rl_gym`.
* **Original raw files:**
  * [Light_Control.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Case_reference/Light_Control.md)
  * [RL_Control_Routine.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Case_reference/RL_Control_Routine.md)

---

## 2. Project Connections & Relevance

These references are integrated into our Smart Inspection system engineering as follows:
1. **DDS & Low-Level (`01_dds_communication.md`, `02_low_level_control.md`):** Used to configure the low-level FOC loop in `go2_control_node` to interact with joint actuators. The motor error decoding bitmask serves as our diagnostic checker.
2. **Stance & Path Tracking (`03_high_level_locomotion.md`):** Evaluates how we command body yaw/pitch offsets (Euler angles) during stair climbs or use circular trajectory follow commands for localized area scanning.
3. **Execution Thread & Safety Loop (`04_debugging_framework.md`):** This is the baseline model for the `go2_state_orchestrator` and safety loop. It handles fallback transitions to DAMPING state if the robot tilts past 90 degrees or experiences communication time-outs.
4. **Spotlight Alerts (`05_auxiliary_services.md`):** Brightness controls are utilized to improve camera feature extraction in poorly lit corners of manufacturing assembly plants.
