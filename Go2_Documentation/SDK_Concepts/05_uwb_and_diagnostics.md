# UWB Vector Positioning & Diagnostics Fault Codes

This document details the hardware design of the UWB companion module, controller button bindings, wearing guidelines, and system fault classification levels.

---

## 1. Reference Links to Archive Sources
For raw specifications and code mappings, refer to the archived guides:
* [[Go2_Documentation/archive/SDK_Concepts/Robot_Dog_Application/UWB_Application|Raw UWB Application Guide]]
* [[Go2_Documentation/archive/SDK_Concepts/FAULTS|Raw Faults Guide]]

---

## 2. UWB Vector companion Module

The UWB module provides centimeter-level relative 2D vector positioning.

### Hardware Interface Setup
* **Tag:** Handheld remote controller featuring a 2-axis joystick, control buttons, and an integrated transmitter antenna.
* **Base Station:** Consists of 4 antennas arranged in a spatial array on the robot chassis. By measuring phase differences and time-of-flight (ToF) delays between the tag and base station antennas, the system calculates the relative distance and bearing angle of the tag.
* **Telemetry:** Includes an internal 6-axis IMU to log tag orientation.

### Handheld Tag Button Map

| Button | Input Count | Triggered action |
| :---: | :---: | :--- |
| **Power** | Hold > 2s | Turn off power. |
| **P** | Double Click | Cycles robot modes: Damping ◄► Stand Down ◄► Stand Up. |
| **P** | Hold 1s | Recovers the robot from a rollover state. |
| **M** | Single Click | Exits Companion mode and enters Rocker joystick control mode. |
| **M** | Double Click | Enters **Slow Companion Mode** (velocity capped at `1.5` m/s). |
| **M** | Double Click (in Slow Mode) | Enters **Fast Companion Mode** (velocity capped at `3.0` m/s). |
| **L1** | Single Click | Rotates the robot counterclockwise by `5.7°`. |
| **L1** | Double Click | Rotates the robot clockwise by `5.7°`. |
| **L2** | Double Click | Enables automatic obstacle avoidance sensors. |
| **L2** | Single Click | Disables automatic obstacle avoidance. |

### Wear & Alignment Rules
To prevent signal occlusion, the operator must wear the UWB tag on their **right waist** with the antenna facing up. The operator should stand to the left of the robot, aligning their torso with the robot's heading before initiating companion tracking.

---

## 3. Diagnostic Fault Classification Levels

When an anomaly occurs, the robot alerts operators via the SDK telemetry stream and the companion app. Faults are categorized into three levels:

```
                  [System Anomaly Detected]
                              │
         ┌────────────────────┼────────────────────┐
         ▼                    ▼                    ▼
  [System Fault]      [Behavioral Fault]     [App Failure]
  (Hardware/Software) (Ignored Commands)    (Binding/Wi-Fi STA)
         │                    │                    │
         ▼                    ▼                    ▼
[Auto-clears/Reboot]  [Self-resolving]    [Check Credentials]
```

1. **System Fault (Hardware / Software):** Indicates sensor failures, joint motor jams, or communication timeouts. These require specific diagnostic code lookups.
2. **Behavioral Fault:** Triggered when the robot ignores a command because safety conditions are not met (e.g. attempting to walk while the joints are locked).
3. **Application Failure:** Network connection issues or security validation handshake failures.

### Fault Recovery Actions
* **Minor Faults:** Warnings automatically clear once the underlying cause resolves.
* **Critical Faults (e.g. Motor Thermal Shutdown):** Requires a physical reboot of the robot's main battery.

---

## 4. Project Relevance
* **Interactive Override:** The UWB tag serves as a physical safety override. The operator can double-click the P button to immediately transition the robot to Damping mode if it behaves unpredictably.
* **Remote Monitoring:** Fault diagnostics are integrated into the state machine orchestrator to trigger safe landing routines before critical hardware damage occurs.
