# Debugging Connections, Wiring & Status Indicators

This document details user PC connection setups, SBUS wiring, NoMachine GUI remote setups, and pilot LED status indicator codes.

---

## 1. Reference Links to Archive Sources
For original illustrations, wiring diagrams, and manuals, refer to the archived guides:
* [[Go2_Documentation/archive/Debugging_Specification|Raw Debugging Specification]]
* [[Go2_Documentation/archive/Remote_Controller|Raw Remote Controller Index]]
* [[Go2_Documentation/archive/FAQ|Raw FAQ Guide]]

---

## 2. Ethernet Debugging Connection

To communicate with the robot's computers, the developer PC must connect to the Go2's physical Ethernet port (located under the rubber cover on the rear chassis).

```
 ┌──────────────────────┐                     ┌──────────────────────┐
 │     Developer PC     │                     │     Go2 Edu Dock     │
 │  (Ubuntu 20.04/22.04)│                     │   (Orin NX Module)   │
 │                      │                     │                      │
 │ IP: 192.168.123.222  ├─────────────────────┤ IP: 192.168.123.18   │
 └──────────────────────┘    Ethernet Cable   └──────────────────────┘
```

* **IP Binding:** The user's computer must be assigned a static IP (e.g., `192.168.123.222`) within the `192.168.123.X` subnet.
* **Wired Connection:** Wireless development is not supported by the SDK due to packet latency constraints.

---

## 3. Remote Control Sticker & SBUS Wiring

### SBUS Receiver Interface
The Go2 Edu motherboard includes a dedicated physical SBUS port for connecting third-party RC receivers (e.g., Futaba or FrSky).
* **Power Warning:** The SBUS port does **not** provide power output. The receiver must be powered externally.
* **Pin Configuration:** Mapped from left to right: `NC` (Not Connected) / `GND` (Ground) / `SBUS` (Signal).

---

## 4. NoMachine Remote GUI Access

The Jetson expansion dock runs NoMachine to allow GUI remote desktop access. Since the robot does not have a physical monitor attached, the display server must be initialized via SSH first:

1. Connect to the Jetson dock over SSH:
   ```bash
   ssh unitree@192.168.123.18
   ```
2. Run the Nomachine virtual display initialization script:
   ```bash
   ./nomachine.sh
   ```
3. Connect your NoMachine client on your host computer to `192.168.123.18:4000`.

---

## 5. Pilot Lamp LED Code Reference

The pilot LED ring on the Go2 indicates system states:

| Color & Flash Pattern | System State | Description |
| :---: | :--- | :--- |
| **Flashing Green** | Booting | Motherboard is initializing. |
| **Solid Green** | Normal Operation | Powered on. Obstacle avoidance is active. |
| **Solid Blue** | Avoidance Off | Powered on. Obstacle avoidance is disabled. |
| **Solid Yellow** | Range Stance | Robot is in standing range/pose mode. |
| **Solid Purple** | Companion Active | UWB companion tracking is enabled. |
| **Slow Flash Blue** | Calibrating | Motor and IMU sensor calibration in progress. |
| **Slow Flash Yellow**| Low Battery | Battery level is low. Robot will crouch down within 10 minutes. |
| **Slow Flash Red** | System Anomaly | Motherboard boot failure or critical hardware fault. |
| **Fast Flash Red** | Calibration Fail | Sensor calibration failed. |
| **Solid White** | Searchlight | Front white searchlight is on. |

---

## 6. Project Relevance
* **Visual Status Monitoring:** During autonomous patrols, we can monitor the LED ring state using our inspection cameras. A blue LED confirms obstacle avoidance is off, while a flashing yellow LED alerts that the robot is returning to the dock due to low battery.
* **Debugging Workflows:** Knowing how to SSH and run the `nomachine.sh` script is essential to debug ROS 2 nodes or visualize point clouds in RViz2 directly on the Jetson dock.
