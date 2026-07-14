# Unitree Go2 SDK Commands Cheat Sheet

This document compiles the high-level locomotion command APIs, switcher controls, and JSON payloads for the Unitree Go2 platform, providing a developer reference for quick query.

---

## 1. High-Level Locomotion API (`SportClient`)

The C++ class `unitree::robot::go2::SportClient` provides high-level posture and locomotion controls.

| API / Method Signature | Parameters & Units | Description / Constraints |
| :--- | :--- | :--- |
| **`StandUp()`** | None | Stands up with locked joints (height: `0.33` m). |
| **`StandDown()`** | None | Lies down. |
| **`BalanceStand()`** | None | Stands dynamically balancing. |
| **`StopMove()`** | None | Instantly stops locomotion commands. |
| **`Move(vx, vy, vyaw)`** | `vx`: X speed (m/s) `[-2.5 ~ 3.8]`<br>`vy`: Y speed (m/s) `[-1.0 ~ 1.0]`<br>`vyaw`: Yaw rate (rad/s) `[-4.0 ~ 4.0]` | Sends linear and angular velocity vectors. |
| **`Euler(roll, pitch, yaw)`**| `roll`: Roll (rad) `[-0.75 ~ 0.75]`<br>`pitch`: Pitch (rad) `[-0.75 ~ 0.75]`<br>`yaw`: Yaw (rad) `[-0.60 ~ 0.60]` | Adjusts body attitude orientation angles. |
| **`BodyHeight(height)`** | `height`: offset (m) `[-0.18 ~ 0.03]` | Adjusts body height relative to default `0.33` m. |
| **`FootRaiseHeight(height)`** | `height`: offset (m) `[-0.06 ~ 0.03]` | Adjusts foot clearance height relative to default `0.09` m. |
| **`SwitchGait(gait)`** | `gait`: ID (`0`=Idle, `1`=Trot, `2`=Trot-Run, `3`=Climb, `4`=Descend) | Sets the walking gait profile. |
| **`ContinuousGait(flag)`** | `flag`: boolean | If `true`, robot legs keep moving in place at zero speed. |
| **`SwitchJoystick(flag)`** | `flag`: boolean | Toggles native remote controller gamepad overrides. |

---

## 2. Motion Switcher Interface (`MotionSwitcherClient`)

Before sending custom velocity or posture commands, acquire controller ownership by locking/releasing MCF (Motion Control Service):

* **Acquire Control (Silent Mode):**
  ```cpp
  unitree::robot::go2::MotionSwitcherClient switcher;
  switcher.Init();
  switcher.SetSilent(true); // Locks MCF system loops; allows custom client commands
  ```
* **Release Control:**
  ```cpp
  switcher.ReleaseMode(); // Restores native gamepad/system control loops
  ```

---

## 3. Onboard SLAM JSON Client API (`slam_operate`)

Onboard SLAM actions are commanded by sending JSON payloads using the client RPC to service `"slam_operate"` (Version `"1.0.0.1"`):

### Start Mapping (API ID: `1801`)
```json
{ "data": { "slam_type": "indoor" } }
```

### End Mapping & Save Map (API ID: `1802`)
```json
{ "data": { "address": "/home/unitree/test.pcd" } }
```

### Initialize Localization Pose (API ID: `1804`)
```json
{
  "data": {
    "x": 0.0, "y": 0.0, "z": 0.0,
    "q_x": 0.0, "q_y": 0.0, "q_z": 0.0, "q_w": 1.0,
    "address": "/home/unitree/test.pcd"
  }
}
```

### Navigate to Goal Pose (API ID: `1102`)
```json
{
  "data": {
    "targetPose": {
      "x": 2.0, "y": 0.0, "z": 0.0,
      "q_x": 0.0, "q_y": 0.0, "q_z": 0.0, "q_w": 1.0
    },
    "mode": 1,
    "speed": 0.5
  }
}
```
* *Avoidance Mode:* `1` = Stop on obstacle; `0` = Plan path around (bypass).
* *Target Limit:* Max `10.0` meters from current position.

### Navigation Control States
* **Pause Navigation:** API ID `1201`
* **Resume Navigation:** API ID `1202`
* **Close SLAM service:** API ID `1901`
