# Go2 Product Specifications & Hardware Capabilities

This document details the physical parameters, joint motion limits, battery capacities, and accessories for the Go2 quadruped models.

---

## 1. Reference Links to Archive Sources
For original product tables and detailed accessory diagrams, refer to the archived guides:
* [Raw About Go2 Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/About_Go2.md)

---

## 2. Model Comparisons (AIR vs. PRO vs. X vs. EDU)

The Go2 is manufactured in four configurations. Secondary development capabilities and external payloads are supported on the **EDU** version.

| Parameter | AIR | PRO | X | EDU |
| :--- | :---: | :---: | :---: | :---: |
| **Standing Size (L×W×H)** | `70×31×40` cm | `70×31×40` cm | `70×31×40` cm | `70×31×40` cm |
| **Lying Size (L×W×H)** | `76×31×20` cm | `76×31×20` cm | `76×31×20` cm | `76×31×20` cm |
| **Weight with Battery** | ~15 kg | ~15 kg | ~15 kg | ~15 kg |
| **Max Payload Load** | ~7 kg | ~8 kg | ~8 kg | **~8 kg (Limit 12 kg)** |
| **Max Locomotion Speed** | 2.5 m/s | 3.5 m/s | 3.7 m/s | **3.7 m/s (Limit 5.0 m/s)** |
| **Max Step / Climb Obstacle**| 15 cm | 16 cm | 16 cm | **16 cm** |
| **Max Climbing Slope** | 30° | 40° | 40° | **40°** |
| **Primary Joint Torque** | / | ~45 N.m | ~45 N.m | **~45 N.m** |
| **Foot Force Sensors** | No | No | No | **Yes (Standard)** |
| **Secondary Dev APIs** | No | No | Basic | **Full Support** |
| **High Computing Dock** | No | No | No | **Optional (40 / 100 TOPS)** |

---

## 3. Joint Layout & Motion Boundaries

Each of the four legs has 3 degrees of freedom (Hip, Thigh, Calf), totaling 12 active joints on the robot.

* **Hip Joint (Joint 0):** Controls leg abduction/adduction. Axis of rotation is the X-axis.
  * *Radian Limit:* `-48° to 48°` (`-0.838 to 0.838` rad)
* **Thigh Joint (Joint 1):** Controls forward/backward leg pitch. Axis of rotation is the Y-axis. Vertical is 0°.
  * *Radian Limit (Front Legs):* `-200° to 90°` (`-3.49 to 1.57` rad)
  * *Radian Limit (Rear Legs):* `-260° to 30°` (`-4.53 to 0.523` rad)
* **Calf Joint (Joint 2):** Controls knee joint extension/flexion. Axis of rotation is the Y-axis.
  * *Radian Limit:* `-156° to -48°` (`-2.72 to -0.838` rad)

---

## 4. Power & Battery Specifications

The Go2 supports two battery models depending on the version:

| Parameter | Standard Battery (`BT2-05`) | Long-Life Battery (`BT2-06`) |
| :--- | :---: | :---: |
| **Compatible Models** | Air / Pro / X / EDU (Base) | **EDU (High-Capacity)** |
| **Capacity** | 8000 mAh (236.8 Wh) | **15000 mAh (432 Wh)** |
| **Rated Voltage** | 29.6V DC | **28.8V DC** |
| **Max Charging Voltage** | 33.6V DC | **33.6V DC** |
| **Operating Duration** | ~1 to 2 hours | **~3 to 5 hours** |
| **Charging Method** | Slow charging (3.5A) | **Fast charging / Charging pile (9A)** |
| **Full Charging Duration** | ~2 hours | **~1 hour 15 minutes** |

---

## 5. Official Accessories Specs

* **Expansion Dock:** Provides either an NVIDIA Jetson Orin Nano (8GB, 40 TOPS) or Orin NX (16GB, 100 TOPS) running Ubuntu.
* **3D LiDARs:** Supports Livox Mid-360 (FOV 360° × 59°) and Hesai XT-16 (FOV 360° × 30°).
* **Intel RealSense D435i:** Depth camera with depth FOV `86° × 57°`, supporting up to 1280×720 resolution at 30 FPS.
* **D1 Manipulator Arm:** 6 DOF mechanical arm + 1 gripper. Weight ~2.37 kg, payload limit ~500g, span ~550mm, controlled via DDS subscriptions.
* **Speaker & Flasher (Three-in-One):** 30W lighting, 30W speaker, 10W red/blue warning flashers. Effective sound range up to 500m.

---

## 6. Project Relevance
* **Dynamic Loading Limits:** In our smart inspection project, the additional payloads (Mid-360 LiDAR + Orin NX Dock + RealSense camera + warning lights) sum to approximately 2.5 kg. This fits well within the 8 kg nominal payload limit of the Go2 Edu, leaving enough payload budget for a D1 manipulator arm.
* **Patrol scheduling:** Knowing that the 15000 mAh battery provides 3 to 5 hours of continuous operation allows us to schedule inspection sweeps every 2 hours with 30-minute fast charging breaks.
