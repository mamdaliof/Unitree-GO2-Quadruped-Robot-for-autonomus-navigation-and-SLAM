# High-Level Motion Control & Switcher Interfaces

This document covers the C++ high-level locomotion APIs (`SportClient`), posture adjustments, gait transitions, and the lease switcher RPC client.

---

## 1. Reference Links to Archive Sources
For original method signatures, error tables, and older version profiles, refer to the archived guides:
* [Raw Sports Services Guide (V1.0)](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/Sports_Services_Interface.md)
* [Raw Motion Services Guide (V2.0)](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/Motion_Services_Interface_V2.0.md)
* [Raw Motion Switcher Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/Motion_Switcher_Service_Interface.md)

---

## 2. Motion Control API Comparison: V1.0 vs. V2.0

* **Version 1.0 (Motherboard Software < V1.1.6):** Standard high-level API. Locomotion calls are sent directly through `SportClient`.
* **Version 2.0 (Motherboard Software $\ge$ V1.1.6):** Introduces lease-lock architecture. Applications must invoke the lease-lock client or call the motion switcher to acquire controller ownership before commanding locomotion.

---

## 3. Locomotion API Reference (`SportClient`)

The C++ class `unitree::robot::go2::SportClient` provides high-level control functions.

### Position & Attitude Tuning
* **`int32_t StandUp()`:** Stands up with locked joints (default height: `0.33`m).
* **`int32_t StandDown()`:** Lies down with locked joints.
* **`int32_t BalanceStand()`:** Stands dynamically balancing.
* **`int32_t Euler(float roll, float pitch, float yaw)`:** Set angles.
  * *Limits:* Roll `[-0.75, 0.75]`, Pitch `[-0.75, 0.75]`, Yaw `[-0.60, 0.60]` (rad).
* **`int32_t BodyHeight(float height)`:** Body height offset.
  * *Limits:* `[-0.18, 0.03]` meters. Default is `0.33`m.
* **`int32_t FootRaiseHeight(float height)`:** Foot clearance height offset.
  * *Limits:* `[-0.06, 0.03]` meters. Default is `0.09`m.

### Locomotion & Path Command
* **`int32_t Move(float vx, float vy, float vyaw)`:** Linear/angular velocity.
  * *Limits:* `vx` `[-2.5, 3.8]` m/s, `vy` `[-1.0, 1.0]` m/s, `vyaw` `[-4.0, 4.0]` rad/s.
* **`int32_t SwitchGait(int gait)`:**
  * `0`: Idle Stance, `1`: Trot, `2`: Trot Run, `3`: Forward Climbing, `4`: Reverse Climbing.
* **`int32_t TrajectoryFollow(std::vector<PathPoint> path)`:** Track trajectory path of 30 future points.
* **`int32_t ContinuousGait(bool flag)`:** Maintain gait timing even when speed is zero.
* **`int32_t SwitchJoystick(bool flag)`:** Disables/enables native remote controller overrides.

---

## 4. Motion Switcher RPC Client (`MotionSwitcherClient`)

When writing custom control nodes, you must release default app ownership or set the robot to a silent state to avoid command collisions.

```cpp
#include <unitree/robot/go2/motion_switcher/motion_switcher_client.hpp>

// Initialize client
unitree::robot::go2::MotionSwitcherClient switcher;
switcher.Init();

// Switch default MCF mode off (Silent state)
switcher.SetSilent(true);
```

### Class Interfaces
* **`int32_t SetSilent(bool silent)`:** Set `true` to disable the default motion control loop. Toggles lease lock.
* **`int32_t GetSilent(bool& silent)`:** Check if the default loop is disabled.
* **`int32_t SelectMode(const std::string& name)`:** Selects active mode (e.g. `mcf` for standard control, `ai` for reinforcement learning gait).
* **`int32_t ReleaseMode()`:** Releases ownership back to default system loops.

---

## 5. System Error & Status Codes

Locomotion and switcher APIs return status codes on failure:
* **`4101`:** Target trajectory path has incorrect size (must be 30 points).
* **`4201`:** Locomotion command timeout.
* **`4206`:** Stance/alignment is invalid.
* **`7002`:** Switcher service is busy.
* **`7004`:** Mode name is not supported.

---

## 6. Project Relevance
* **Safe Lease Transfers:** The state machine (`go2_state_orchestrator`) calls `SetSilent(true)` before starting autonomous inspection. This prevents interference from the default motion controller or accidental gamepad inputs.
