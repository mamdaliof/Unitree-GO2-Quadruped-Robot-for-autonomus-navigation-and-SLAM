# Payload Integration & Mounting Guide

This document details the electrical specifications of the Go2 expansion dock, physical mounting steps for sensors (LiDAR, Camera), and automated charging pile deployment.

---

## 1. Reference Links to Archive Sources
If this documentation lacks detail or you need to inspect raw dimension diagrams, refer to the original files:
* [[Go2_Documentation/archive/Application_Development/Payload|Raw Payload Guide]]

---

## 2. Electrical Interface Specifications

The expansion dock provides power and network channels to external hardware payloads.

| Port / Interface | Meaning / Pinout Specs |
| :--- | :--- |
| **XT30U-F Power** | * **Inputs:** 16V-45V (Peak 60V). 2 input lines (1 for internal dock power, 1 for external arm power).<br>* **Outputs:** 12V @ 3A max, 5V @ 3A max for external payloads. |
| **RJ45 Ethernet** | 2 ports: 1 channel connected to the internal Go2 computer, 1 channel routed to the external user RJ45 port. |
| **M8 Aviation Plug** | 1 port (radar-specific). Pinout: Gigabit Ethernet + 12V/2A power output for radar. |
| **USB Type-A** | 1 USB 3.2 Gen 2 (Host mode only). Power: 5V/1A. Speed: 10Gbps. |
| **USB-DP Alt Type-C** | 1 full-featured Type-C. Supports USB 2.0 and DP 1.4 video output. Power: 5V/3A. |
| **USB Type-C** | 1 USB 3.2 Gen 2 port. Power: 5V/2A. |
| **GH1.25-4PIN** | 1 port. Routes Gigabit Ethernet out to secondary devices (e.g. robotic arm). |

---

## 3. Physical Mounting Workflows

### Mounting the Expansion Dock
1. Remove back cover screws from the Go2 body using a hex wrench.
2. Route main power and Ethernet lines from the body to the dock. Lay cables inside the designated cable guide channels.
3. Fasten the expansion dock to the Go2 chassis using `M3×50` screws.
4. Mount the dock cover and screw in place.

### Mounting the LiDAR (Livox Mid-360 or Hesai XT-16)
1. Bolt the LiDAR module to the front of the top expansion rail.
2. Route the LiDAR integrated cable to the **M8 Aviation Plug** on the expansion dock and lock the collar.

### Mounting the Intel RealSense D435i Camera
1. Connect the Type-C cable to the camera port, threading it through the support frame. Do not yank the cable during assembly.
2. Screw the support to the D435i backplate using `M3` screws.
3. Fasten the camera base mount to the front head mounting holes of the Go2.
4. Plug the camera cable into a USB port on the expansion dock.

---

## 4. Charging Pile & Docking Setup

Automatic relocalization and long-term inspection require the charging dock accessory.

### Hardware Installation
1. Fasten the target nameplate board to the charging station vertical support.
2. Orient the charging board contacts correctly (do not mount backwards).
3. Connect the fast-charger output to the base of the charging board and secure the cord.

### L1 LiDAR Return Charge Guide
Automatic docking relies on the onboard L1 LiDAR recognizing the positioning marker board.
* **Setup Position:** Place the robot on the charging pad before creating the SLAM map. The map origin (`0,0,0`) must correspond to the charging contact coordinates.
* **Alignment Rules:** Avoid placing the charging dock in narrow aisles (minimum width clearance should be `1 meter`). Ensure contact electrodes are clean and free of dust.

### LED Indicator Code
* **Constantly ON:** Charging complete.
* **Slow Flashing (500ms):** Charging in progress.
* **Rapid Flash (3x 100ms) + 1.5s pause:** Overcurrent or undervoltage protection active.
* **Breathing fade:** Idle state.

---

## 5. Project Relevance
* **Coordinate Transforms:** Physical sensor mounting locations correspond to standard TF transformation matrices in our SLAM package (Mid-360 uses translation `[0.1870, 0, 0.0803]` and `13.0°` pitch rotation).
* **Automatic Docking:** The state machine (`go2_state_orchestrator`) must command return-to-dock transitions to trigger the L1 alignment sequence when the BMS reports low battery.
