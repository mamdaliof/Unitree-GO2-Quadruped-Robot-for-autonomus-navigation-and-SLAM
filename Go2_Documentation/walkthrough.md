# Go2 Documentation Navigation Walkthrough

This guide provides a structured walkthrough of the restructured documentation, highlighting critical concepts you must master immediately versus secondary features you should only be aware of for future implementation.

---

## 1. High-Priority Essentials (Master Immediately)

These files and concepts are required to establish communication, build example programs, and run basic motor tests safely without damaging the hardware.

### 🌐 Network & Subnet Binding
* **File:** [[Go2_Documentation/Application_Development/01_sdk_installation]]
* **What you need to know:** 
  * The robot's computers operate on the `192.168.123.X` subnet. 
  * Your developer PC must be statically set to `192.168.123.222` (or any address other than `.18`, `.20`, and `.161`).
  * You must use `ifconfig` to identify your Ethernet interface name (e.g. `enp3s0`), as it is a required command-line argument for running SDK example programs.

### 🎛 The Motion Switcher Lease Lock
* **File:** [[Go2_Documentation/Software_Interface_Services/02_motion_control_modes]]
* **What you need to know:**
  * By default, the robot runs a background motion controller service (`mcf` or `sport_mode`).
  * If you try to command joint angles while this service is active, your commands will collide with the default controller, causing the legs to shake violently.
  * You **must** utilize the `MotionSwitcherClient` to set the robot to a *silent state* (`SetSilent(true)`) or call the switcher RPC to release the lease before deploying custom joint-space programs.

### 📐 Coordinate Systems & Joint Limits
* **File:** [[Go2_Documentation/SDK_Concepts/04_locomotion_states]]
* **What you need to know:**
  * The body coordinate frame uses the standard ROS right-hand convention: **X-forward, Y-left, Z-up**.
  * The standing height default is `0.33` meters.
  * Joint range bounds: Hip (`-48° to 48°`), Thigh (`-200° to 90°` front, `-260° to 30°` rear), and Calf (`-156° to -48°`). Exceeding these limits in your code will trigger automatic joint shutdowns.

### 🛡 State Machine Transitions & Damping Safety
* **File:** [[Go2_Documentation/Case_reference/04_debugging_framework]]
* **What you need to know:**
  * Before writing movement code, implement the three standard states: `DAMPING` (limp safety fallback), `STAND` (locked standing), and `CTRL` (active algorithm execution).
  * Always run an active safety checker (like the `CheckTermination()` projected gravity vector test). If the robot rolls past 90°, your code must immediately write `Kd` damping gains to collapse the robot safely.

---

## 2. Secondary Concepts (Read-on-Demand)

You only need to be aware that these capabilities exist. Refer back to these files when you begin implementing specific subsystem tasks.

### 🗺 SLAM Mapping & Navigation
* **Files:** [[Go2_Documentation/Software_Interface_Services/03_slam_and_navigation]] & [[Go2_Documentation/Case_reference/03_high_level_locomotion]]
* **Status:** *Awareness only.*
* **When to open:** When you have verified your basic locomotion state machine and are ready to mount the Mid-360 LiDAR to record a 3D point cloud (`factory.pcd`) of the manufacturing floor.

### 🦾 D1 Manipulator Arm
* **File:** [[Go2_Documentation/Software_Interface_Services/06_manipulator_and_payloads]]
* **Status:** *Awareness only.*
* **When to open:** When we begin developing the payload inspection routines and want to use the `ArmClient` to point cameras at target machine valves.

### 📡 UWB Companion Tracking
* **File:** [[Go2_Documentation/SDK_Concepts/05_uwb_and_diagnostics]]
* **Status:** *Awareness only.*
* **When to open:** If you want to use the handheld tag controller to manually walk alongside the robot during mapping calibration runs.

### 🎮 Isaac Gym Reinforcement Learning
* **File:** [[Go2_Documentation/Case_reference/05_auxiliary_services]]
* **Status:** *Awareness only.*
* **When to open:** If you plan to train custom walking gaits in simulation before deploying them onto the robot.

---

## 3. Recommended Navigation Path

To systematically build up the control stack:
```
[01_sdk_installation] ──► Bind subnet, compile examples, ping robot
         │
         ▼
[02_motion_control_modes] ──► Release MFC lease lock, trigger silent state
         │
         ▼
[02_custom_apps] ──► Write basic standing stance nodes
         │
         ▼
[04_debugging_framework] ──► Add safety loop checks (projected gravity fallbacks)
         │
         ▼
[03_slam_and_navigation] ──► Initiate LiDAR sweeps and navigation waypoints
```
