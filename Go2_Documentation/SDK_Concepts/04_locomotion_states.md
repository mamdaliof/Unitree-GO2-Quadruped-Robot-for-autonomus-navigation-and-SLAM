# Locomotion gaits & State Machine Transitions

This document defines the Cartesian coordinate system, physical scale clearances, active gait types, and the state transition logic of the Go2.

---

## 1. Reference Links to Archive Sources
For original coordinate diagrams and state transition flowcharts, refer to the archived guides:
* [Raw Motion Application Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/SDK_Concepts/Robot_Dog_Application/Motion_Application.md)

---

## 2. Coordinate System & Physical Dimensions

The Go2 body coordinate frame follows the standard right-hand rule convention:
* **X-axis:** Facing forward.
* **Y-axis:** Facing left.
* **Z-axis:** Facing up.

### Key Clearances & Dimensions
* **Default Standing Height:** `0.33` meters (ground to body center origin).
* **Foot Spacing Offset:** Front left foot stance offset relative to the body center is `[X: 0.19257m, Y: 0.135m]`.
* **Step Lift Height:** Default foot clearance height during locomotion is `0.09` meters (9 cm).

---

## 3. High-Level Locomotion Gaits

The motion controller provides three primary gaits:
1. **Trot Gait:** Most efficient walking gait for quadruped robots. Diagnonally opposite leg pairs move in phase.
2. **Trot-Run Gait:** Features a higher step lift height and faster stride frequency. Used for high-speed traversal over flat surfaces.
3. **Climbing Mode:** An adaptive gait with foot placement corrections. Used to traverse uneven obstacles and climb stairs.

---

## 4. State Machine Transition Logic

The motion controller switches between different states to safely execute tasks and handle unexpected disturbances:

### Locomotion States

| State | Description | Transition Priority |
| :---: | :--- | :---: |
| **`Damping`** | All joint motors enter zero-torque damping mode (limp). | **Highest Priority.** Can be entered from any state instantly (Emergency Stop). |
| **`Standing Lock`** | The robot stands up and locks its joint positions in place. | Intermediate state. Bridges Damping and Balanced Standing. |
| **`Balanced Stand`** | Stands in place while dynamically adapting to ground slope and external forces. | Base state for initiating custom SDK commands. |
| **`Basic Motion`** | Executes velocity commands, trajectory tracking, and obstacle avoidance. | Can be interrupted at any time by commanding a transition to Balanced Stand or Damping. |
| **`Special Action`** | Executes pre-programmed routines (e.g. sit, stretch, front-flip). | Suspends other motion services. Returns to Balanced Stand upon completion. |
| **`Protected State`** | Triggered automatically when the IMU detects a roll angle exceeding 90° (rollover). | Disables normal motion commands. Restores standing via recovery scripts. |

### State Transition Diagram

```
      [Any State] ──────(Emergency Stop Command)──────► [Damping State]
           ▲                                                   │
           │                                                   ▼ (R2 / Unlock)
     (Impact Roll)                                    [Standing Lock State]
           │                                                   │
           │                                                   ▼ (Height Stability)
    [Protected State] ◄──(Recovery Stand)── [Balanced Standing State]
           ▲                                      │               │
           │                                      ▼               ▼
     (External Force)                      [Basic Motion]  [Special Actions]
```

---

## 5. Project Relevance
* **Coordinate Alignment:** The standard Cartesian coordinates (X-front, Y-left, Z-up) correspond directly to the standard ROS `base_link` frame, establishing correct URDF offsets for sensor integration.
* **Gait Selection:** Our state machine node (`go2_state_orchestrator`) uses this state transition logic. It monitors IMU data to detect rollovers and automatically triggers the recovery stand sequence when the robot is in a safe environment.
