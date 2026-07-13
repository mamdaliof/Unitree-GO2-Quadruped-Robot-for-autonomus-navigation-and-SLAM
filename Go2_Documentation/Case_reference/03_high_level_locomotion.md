# High-Level Locomotion & Posture Control

This document details the C++ implementation of high-level stance control, velocity tracking, trajectory following, and state telemetry using the `SportClient` interface.

---

## 1. Reference Links to Archive Sources
For original code examples and raw method prototypes, refer to the archived guides:
* [Raw High Motion Control Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Case_reference/High_Motion_Control.md)

---

## 2. Locomotion & Posture Commands

When using high-level control, the robot automatically handles joint torque distribution. The developer commands body velocities or stance angles:

### Stance & Balance Controls
* **Normal Standing (`StandUp()`):** Locked joint posture at `0.33`m default height.
* **Balanced Standing (`BalanceStand()`):** Fuselage dynamically adapts to ground slope.
* **Stance Angles (`Euler`):** Commands yaw/pitch/roll offsets:
  * Roll: `[-0.75 ~ 0.75]` rad
  * Pitch: `[-0.75 ~ 0.75]` rad
  * Yaw: `[-0.60 ~ 0.60]` rad
* **Stance Height (`BodyHeight`):** Relative offset `[-0.18 ~ 0.03]` meters.

### Locomotion controls
* **Velocity Tracking (`Move`):**
  * `vx`: Linear forward velocity `[-2.5 ~ 3.8]` m/s
  * `vy`: Linear side velocity `[-1.0 ~ 1.0]` m/s
  * `vyaw`: Angular yaw speed `[-4.0 ~ 4.0]` rad/s
* **Gait Selection (`SwitchGait`):**
  * `0`: Idle Stance
  * `1`: Trot
  * `2`: Run
  * `3`: Climb Stairs (Faces stairs forward)
  * `4`: Down Stairs (Backwards down stairs)

---

## 3. Trajectory Tracking Control (`TrajectoryFollow`)

Used to command the robot to execute complex, smooth geometric paths. The path must contain exactly **30 future trajectory points** (`PathPoint` / `stPathPoint`).

### Path Point Schema
```cpp
struct PathPoint {
  float timeFromStart; // Expected time arrival offset (seconds)
  float x;             // Absolute X position coordinate
  float y;             // Absolute Y position coordinate
  float yaw;           // Absolute orientation angle
  float vx;            // Expected linear X velocity
  float vy;            // Expected linear Y velocity
  float vyaw;          // Expected rotational yaw velocity
};
```

### Path Generation C++ Example (Circular Trajectory)
This snippet calculates a circle of radius `0.5m` centered at `(0.0, -1.0)` in the coordinate system of the program startup:
```cpp
std::vector<PathPoint> path;
float time_seg = 0.2;  // Time gap between points
float time_temp = current_time - time_seg;

for (int i = 0; i < 30; i++)
{
  time_temp += time_seg;

  // Local circular path coordinate relative to origin
  float px_local = 0.5 * sin(0.5 * time_temp);
  float py_local = 0.5 * cos(0.5 * time_temp) - 1.0;
  float yaw_local = 0.0;
  float vx_local = 0.25 * cos(0.5 * time_temp);
  float vy_local = -0.25 * sin(0.5 * time_temp);
  float vyaw_local = 0.0;

  // Transform coordinates relative to startup yaw (yaw0) and origin (px0, py0)
  PathPoint pt;
  pt.timeFromStart = i * time_seg;
  pt.x = px_local * cos(yaw0) - py_local * sin(yaw0) + px0;
  pt.y = px_local * sin(yaw0) + py_local * cos(yaw0) + py0;
  pt.yaw = yaw_local + yaw0;
  pt.vx = vx_local * cos(yaw0) - vy_local * sin(yaw0);
  pt.vy = vx_local * sin(yaw0) + vy_local * cos(yaw0);
  pt.vyaw = vyaw_local;
  
  path.push_back(pt);
}
sport_client.TrajectoryFollow(path);
```

---

## 4. Telemetry Stance Feedback

High-level state variables are read by subscribing to the `rt/sportmodestate` topic:

```cpp
void HighStateHandler(const void *message)
{
  const auto* state = (const unitree_go::msg::dds_::SportModeState_ *)message;
  
  // Real-time odometer position
  float x = state->position()[0];
  float y = state->position()[1];
  float z = state->position()[2];
  
  // Orientation roll/pitch/yaw angles from IMU state
  float roll = state->imu_state().rpy()[0];
  float pitch = state->imu_state().rpy()[1];
  float yaw = state->imu_state().rpy()[2];
}
```

---

## 5. Project Relevance
* **Stair Navigation:** In manufacturing setups with multi-level floors, the state machine must call `SwitchGait(3)` (Climb Stairs) before initiating vertical stair traversal.
* **Trajectory Mapping:** `TrajectoryFollow` can be used to move the robot along fixed inspection loops while point clouds are captured.
