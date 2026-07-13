# Low-Level joint Control & Motor Diagnostics

This document details direct motor command configurations, Joint Linear Interpolation, sinusoidal swinging routines, and the bitmask decoding of motor errors.

---

## 1. Reference Links to Archive Sources
For original code examples and diagrams, refer to the archived guides:
* [[Go2_Documentation/archive/Case_reference/Basic_Motion_Control|Raw Basic Motion Control Guide]]
* [[Go2_Documentation/archive/Case_reference/Exapmle_of_motor_errors|Raw Motor Errors Guide]]

---

## 2. Low-Level Joint Actuation & FOC parameters

Direct joint control targets the 12 primary motors (Hip, Thigh, Calf * 4 legs) using the `LowCmd` topic.

### Motor command Structure (`motor_cmd`)
Each motor index within `LowCmd.motorCmd[20]` accepts five parameters for control:
* **`mode`:** Must be set to `0x01` (Servo/FOC mode). Setting to `0x00` stops the motor.
* **`q`:** Target joint angle in radians (`PosStopF` defaults to nullifying target position).
* **`dq`:** Target joint velocity in rad/s (`VelStopF` defaults to nullifying target velocity).
* **`Kp`:** Proportional stiffness gain (control position scaling).
* **`Kd`:** Derivative damping gain (control velocity scaling).
* **`tau`:** Feedforward torque in N.m.

### Initialization function
```cpp
void Custom::InitLowCmd() {
    low_cmd.head[0] = 0xFE; 
    low_cmd.head[1] = 0xEF;
    low_cmd.levelFlag = 0xFF;
    low_cmd.gpio = 0;

    for(int i = 0; i < 20; i++){
        low_cmd.motorCmd[i].mode = 0x01; // Enable servo mode
        low_cmd.motorCmd[i].q = PosStopF;
        low_cmd.motorCmd[i].Kp = 0;
        low_cmd.motorCmd[i].dq = VelStopF;
        low_cmd.motorCmd[i].Kd = 0;
        low_cmd.motorCmd[i].tau = 0;
    }
}
```

---

## 3. Joint Linear Interpolation & Sinusoidal Swing

When moving the leg from an arbitrary initial state to a specific starting angle, a linear interpolation keeps the joint velocity within safe limits.

### Linear Interpolation function
```cpp
float jointLinearInterpolation(float init_pos, float target_pos, float rate) {
    // Clamping rate parameter between 0.0 and 1.0
    double r = std::max(0.0, std::min(1.0, (double)rate));
    return init_pos * (1.0 - r) + target_pos * r;
}
```

### Sinusoidal swinging sequence (`LowCmdwriteHandler`)
A typical swinging script divides movement into three time steps:
1. **`motiontime < 20`:** Record the initial joint angles (`qInit`).
2. **`10 <= motiontime < 400`:** Interpolate slowly from `qInit` to the midpoint angle `sin_mid_q` to avoid sudden jerks.
3. **`motiontime >= 400`:** Execute periodic sinusoidal oscillation:
   $$
   q_{des} = q_{mid} + A \sin(\omega t)
   $$
```cpp
// Sinusoidal swinging math example (executed at 500Hz loop)
float freq_Hz = 1.0;
float freq_rad = freq_Hz * 2 * M_PI;
float t = dt * sin_count;

if (motiontime >= 400) {
    sin_count++;
    float sin_joint1 = 0.6 * sin(t * freq_rad);   // Thigh swing swing
    float sin_joint2 = -0.9 * sin(t * freq_rad);  // Calf swing swing
    
    qDes[0] = sin_mid_q[0];
    qDes[1] = sin_mid_q[1] + sin_joint1;
    qDes[2] = sin_mid_q[2] + sin_joint2;
}
```

---

## 4. Leg-SDK to DDS Data Conversions

The SDK handles joint math using human-readable structs (`UNITREE_LEGGED_SDK`), but sends them over DDS using CycloneDDS message types (`unitree_go::msg::dds_`).

Use the following helper functions to bridge the structures:
* **`lowCmd2Dds(LowCmd& raw, LowCmd_& dds)`:** Copies local FOC values to the publishing packet.
* **`dds2LowState(LowState_& dds, LowState& raw)`:** Maps DDS subscriber feedbacks to readable joint arrays.

---

## 5. Motor Error Bitmask Decoding

Motor states contain error codes in `reserve[0]` of the `MotorState` feedback structure. If a motor jams or overheats, it enters a self-protection mode.

### Error Bitmask Map (`reserve[0]`)

| Bit | Error Type | Trigger Cause |
| :---: | :--- | :--- |
| **0** | Over Current | Motor current exceeds operating range. |
| **1** | Over Voltage | Bus voltage exceeds 45V. |
| **2** | Driver Overheat | Motor casing or driver temperature exceeds 90 °C. |
| **3** | Motor Bus Under Voltage | Bus voltage drops below 11V. |
| **4** | Winding Overheat | Jamming or overloading heats winding past 140 °C. |
| **5** | Encoder Abnormal | Encoder data is corrupt or unreachable. |
| **8** | Communication Interrupted | Packet loss between Jetson and driver node. |

### C++ Bitmask Decoder
```cpp
class GetDetailMotorErrors {
private:
    struct MotorErrorState {
        std::string error_type;
        short int state;
    };
    std::vector<MotorErrorState> motor_errors = {
        {"Over current", 0}, {"Over voltage", 0}, {"Driver overheat", 0},
        {"Motor bus under voltage", 0}, {"Winding overheat", 0},
        {"Encoder abnormal", 0}, {"Reserved", 0}, {"Reserved", 0},
        {"Communication interrupted", 0}
    };
public:
    void ReportErrors(int error_code) {
        for (size_t i = 0; i < motor_errors.size(); i++) {
            // Check bit representation
            motor_errors[i].state = (error_code & (1 << i)) >> i;
            if (motor_errors[i].state > 0) {
                std::cout << "Warning: " << motor_errors[i].error_type << std::endl;
            }
        }
    }
};
```
*Note: If a motor enters protection, turn off the main battery, wait for it to cool down, and reboot the system.*

---

## 6. Project Relevance
* **Joint Safety Limits:** We use the `GetDetailMotorErrors` decoder within our `go2_control_node` to trigger automatic state transition to DAMPING if any joint casing temperature exceeds the safe 90 °C limit.
* **Low-Level Control:** Sinusoidal swinging logic helps in writing the trajectory calibration steps for our robot feet.
