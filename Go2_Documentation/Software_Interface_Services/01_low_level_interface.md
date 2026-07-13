# Low-Level DDS IDL Interface Services

This document details the low-level CycloneDDS IDL definitions used to command motor joint FOC parameters, query battery state, parse IMU readings, and control auxiliary robot utilities.

---

## 1. Reference Links to Archive Sources
For original IDL files and descriptions, refer to the archived documents:
* [Raw Basic Services Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/Basic_Services_Interface.md)
* [Raw RobotStateClient Interface Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/RobotStateClient_Interface.md)
* [Raw VuiClient Interface Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/VuiClient_Interface.md)

---

## 2. Actuator Joint Command Interface (`LowCmd_.idl`)

Motor commands are published to the `rt/lowcmd` topic. 

### Motor Joint Index Mapping
The body houses 12 active joints. The index mapping is defined as:
* **Front Right (FR):** Hip = `0`, Thigh = `1`, Calf = `2`
* **Front Left (FL):** Hip = `3`, Thigh = `4`, Calf = `5`
* **Rear Right (RR):** Hip = `6`, Thigh = `7`, Calf = `8`
* **Rear Left (RL):** Hip = `9`, Thigh = `10`, Calf = `11`

### LowCmd IDL Schema
```idl
struct LowCmd_ {
    octet head[2];                       // Verification bytes (0xFE, 0xEF)
    octet level_flag;                    // Reserved
    octet frame_reserve;                 // Reserved
    unsigned long sn[2];                 // Reserved
    unsigned long version[2];            // Reserved
    unsigned short bandwidth;            // Reserved
    
    MotorCmd_ motor_cmd[20];             // Actuator target parameters (indices 0-11)
    BmsCmd_ bms_cmd;                     // Battery power commands
    
    octet wireless_remote[40];           // Reserved
    octet led[12];                       // Reserved
    octet fan[2];                        // Reserved
    octet gpio;                          // bitmask: &0xFE (Charge On), &0xFD (Motor Power On)
    unsigned long reserve;
    unsigned long crc;                   // CRC32 check value
};
```

### MotorCmd IDL Schema
```idl
struct MotorCmd_ {
    octet mode;       // 0x01 = Servo/FOC mode, 0x00 = Standby/Stop
    float q;          // Target position (rad)
    float dq;         // Target velocity (rad/s)
    float tau;        // Target torque feedforward (N.m)
    float kp;         // Proportional stiffness gain
    float kd;         // Derivative damping gain
    unsigned long reserve[3];
};
```

### BmsCmd IDL Schema
```idl
struct BmsCmd_ {
    octet off;        // Set to 0xA5 to command a battery shutdown
    octet reserve[3];
};
```

---

## 3. Telemetry Feedback State Interface (`LowState_.idl`)

Joint sensors, BMS, and IMU data are published to the `rt/lowstate` topic.

### LowState IDL Schema
```idl
struct LowState_ {
    octet head[2];                       // Verification bytes (0xFE, 0xEF)
    octet level_flag;
    octet frame_reserve;
    unsigned long sn[2];
    unsigned long version[2];
    unsigned short bandwidth;
    
    IMUState_ imu_state;                 // Inertial feedback
    MotorState_ motor_state[20];         // Joint feedback (indices 0-11)
    BmsState_ bms_state;                 // Battery telemetry
    
    short foot_force[4];                 // Foot sensor contacts (0-4095 range)
    short foot_force_est[4];             // Estimated foot contact force
    unsigned long tick;                  // Time counter (increments in ms)
    octet wireless_remote[40];           // Raw gamepad telemetry bytes
    octet bit_flag;                      // Bitmask: &0x80 (Motor Timeout), &0x10 (BMS Timeout)
    
    float adc_reel;                      // Winder current (0-3A)
    octet temperature_ntc1;              // Motherboard center temp (-20 to 100 °C)
    octet temperature_ntc2;              // Automatic charging temp (-20 to 100 °C)
    float power_v;                       // Motherboard/battery voltage
    float power_a;                       // Motherboard/motor current
    unsigned short fan_frequency[4];     // Cooling fan RPM speeds
    unsigned long reserve;
    unsigned long crc;
};
```

### IMUState IDL Schema
```idl
struct IMUState_ {
    float quaternion[4];    // Orientation quaternion (w, x, y, z)
    float gyroscope[3];     // Angular velocity (x, y, z rad/s)
    float accelerometer[3]; // Linear acceleration (x, y, z m/s²)
    float rpy[3];           // Roll, Pitch, Yaw Euler angles (rad)
    octet temperature;      // Sensor temperature (°C)
};
```

### MotorState IDL Schema
```idl
struct MotorState_ {
    octet mode;              // Operating mode
    float q;                 // Position feedback (rad)
    float dq;                // Velocity feedback (rad/s)
    float ddq;               // Acceleration feedback (rad/s²)
    float tau_est;           // Estimated output torque (N.m)
    float q_raw;
    float dq_raw;
    float ddq_raw;
    octet temperature;       // Motor temperature (-100 to 150 °C)
    unsigned long lost;      // Communication packet loss count
    unsigned long reserve[2]; // Index 0: Error bitmask, Index 1: Comm frequency
};
```

### BmsState IDL Schema
```idl
struct BmsState_ {
    octet version_high;
    octet version_low;
    octet status;            // 0: Safe, 7: Charging, 8: Discharging, 11: Alarm
    octet soc;               // State of Charge (1-100%)
    long current;            // Current (positive = charging, negative = discharging)
    unsigned short cycle;    // Battery charge cycles
    octet bq_ntc[2];         // Internal cell temperature probes
    octet mcu_ntc[2];        // BMS board temperature probes
    unsigned short cell_vol[15]; // Voltage arrays of individual cells
};
```

---

## 4. Robot State Client & Volume Interfaces

Two high-level helper classes manage global parameters and light settings:

### `RobotStateClient`
Used to query system settings via RPC:
* **`int32_t GetGo2Version(...)`:** Returns hardware version strings.
* **`int32_t CheckFirmwareVersion(...)`:** Verifies if the motherboard is up to date.

### `VuiClient`
Manages the volume level and voice alerts:
* **`int32_t SetVolume(int volume)`:** Sets speaker output volume `[0 ~ 10]`.
* **`int32_t GetVolume(int& volume)`:** Returns active volume settings.

---

## 5. Project Relevance
* **Dynamic BMS Safeguards:** The `go2_control_node` parses `bms_state.soc` and `bms_state.status` to trigger low-battery alarms or abort missions if a cell temperature exceeds 65 °C.
