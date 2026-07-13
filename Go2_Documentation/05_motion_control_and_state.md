# Motion Control and State Feedback

This document describes the high-level movement controls, low-level joint actuators, and telemetry states for the Go2 Edu.

## 1. High-Level Control Interface (`SportClient`)

High-level locomotion and posture adjustments are commanded using the `SportClient` API. The client generates JSON requests sent to `/api/sport/request`.

### Locomotion & Position Control Commands

* **`StandUp()` / `StandDown()`**
  * Locks leg joints. Standing height defaults to `0.33` meters.
* **`BalanceStand()`**
  * Unlocks joints to maintain body height and orientation relative to ground slope.
* **`RecoveryStand()`**
  * Automatically recovers standing orientation from a fallen or rolled-over state.
* **`Move(float vx, float vy, float vyaw)`**
  * Sets linear velocities `vx` `[-2.5 ~ 3.8]` m/s, `vy` `[-1.0 ~ 1.0]` m/s, and rotational speed `vyaw` `[-4.0 ~ 4.0]` rad/s.
* **`Euler(float roll, float pitch, float yaw)`**
  * Adjusts static body orientation in roll `[-0.75 ~ 0.75]` rad, pitch `[-0.75 ~ 0.75]` rad, and yaw `[-0.60 ~ 0.60]` rad.
* **`BodyHeight(float height)`**
  * Adjusts height offset relative to default `0.33`m. Range is `[-0.18 ~ 0.03]` meters.
* **`FootRaiseHeight(float height)`**
  * Adjusts foot step height relative to default `0.09`m. Range is `[-0.06 ~ 0.03]` meters.
* **`SwitchGait(int gait)`**
  * Sets movement pattern: `0` = Idle, `1` = Trot, `2` = Trot Running, `3` = Forward Stairs, `4` = Reverse Stairs.
* **`SwitchJoystick(bool flag)`**
  * `false` disables the default remote controller joystick signals from overriding user software control.

---

## 2. High-Level Locomotion Feedback (`rt/sportmodestate`)

Used to retrieve real-time body state estimations.
* **Topic:** `rt/sportmodestate` (or `rt/portmodestate` depending on network rate)
* **Message Class:** `unitree_go::msg::dds_::SportModeState_`

### Core Feedback Parameters
```cpp
std::array<float, 3> position();      // 3D position in odom frame
std::array<float, 3> velocity();      // 3D velocity in body frame
float yawSpeed();                     // Rotational speed (rad/s)
IMU imuState();                       // IMU quaternion, gyro, and accel
uint8_t mode();                       // Current sport mode (Locomotion, Idle, Sit)
uint8_t gaitType();                   // Current gait type
float footRaiseHeight();              // Current step lift height
std::array<int16_t, 4> footForce();   // Joint contact forces
std::array<float, 12> footPositionBody(); // 3D Foot end coordinates (x,y,z * 4) in body frame
```

---

## 3. Low-Level Control Interface (`LowCmd` / `/lowcmd`)

Direct joint FOC (Field-Oriented Control) allows raw motor torque, position, and stiffness commands to be published.
* **Topic:** `/lowcmd`
* **Message Type:** `unitree_go::msg::dds_::LowCmd_`

Each command targets 20 joints via `MotorCmd[20]` arrays:
```cpp
struct MotorCmd {
  uint8 mode;     // Control Mode: FOC mode = 0x01, Stop mode = 0x00
  float q;        // Target position (rad)
  float dq;       // Target velocity (rad/s)
  float tau;      // Target torque (N.m)
  float kp;       // Proportional stiffness gain
  float kd;       // Derivative damping gain
};
```

---

## 4. Low-Level Feedback Telemetry (`rt/lowstate`)

Provides joint-level motor readings and sensor feedback.
* **Topic:** `rt/lowstate`
* **Message Class:** `unitree_go::msg::dds_::LowState_`

Includes `MotorState[20]` feedbacks:
```cpp
struct MotorState {
  uint8 mode;       // Active motor mode
  float q;          // Current joint angle (rad)
  float dq;         // Current joint velocity (rad/s)
  float ddq;        // Current joint acceleration (rad/s^2)
  float tau_est;    // Estimated output torque (N.m)
  int8 temperature; // Motor temperature (°C)
};
```
Also includes BMS battery telemetry: `voltage`, `current`, `charge percentage (%)`, and `temperatures`.

---

## 5. High-Level Locomotion Controller Code (C++)

This example commands the robot to perform pitch and roll oscillations while standing:

```cpp
#include <unitree/robot/go2/sport/sport_client.hpp>
#include <cmath>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    return -1;
  }

  // Initialize SDK Channel Factory
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);

  unitree::robot::go2::SportClient sport_client;
  sport_client.SetTimeout(10.0f);
  sport_client.Init();

  double elapsed_time = 0.0;
  double dt = 0.02; // 50 Hz control loop

  std::cout << "Starting posture balance oscillation. Press Ctrl+C to stop..." << std::endl;

  while (true)
  {
    elapsed_time += dt;

    // Calculate sinusoid oscillation angles
    float roll = 0.15 * sin(1.5 * elapsed_time);
    float pitch = 0.15 * cos(1.5 * elapsed_time) - 0.1;
    float yaw = 0.0;

    // Send pose updates
    sport_client.Euler(roll, pitch, yaw);
    sport_client.BalanceStand();

    usleep(static_cast<int>(dt * 1000000));
  }
  
  // Reset orientation on exit
  sport_client.Euler(0.0, 0.0, 0.0);
  return 0;
}
```
