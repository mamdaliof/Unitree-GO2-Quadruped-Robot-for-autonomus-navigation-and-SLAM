---
aliases: ["ANYmal in the Field: Solving Industrial Inspection of an Offshore HVDC Platform with a Quadrupedal Robot - Notes"]
created: ["09-07-2026 16:45"]
tags:
- Literature/Notes
- Project/LearningFactory
---

# 📝 Paper Notes -> ANYmal in the Field

---
## 📢 - Metadata
- **Context**: ETH Zurich research on quadrupedal inspection of offshore HVDC converter platforms.
- **Rationale**: Legged robots are viable for challenging, high-obstacle offshore terrains where wheeled/tracked systems fail.

![[Pasted image 20260709111847.png]]

---

## 🎯 - Value of Mobile Inspection Robots
- **Flexible Perspective**: Avoids the viewpoint limitations, high retrofitting costs, and single-point-of-failure vulnerabilities of fixed camera setups.
- **Early Defect Detection**: Enables higher inspection frequencies than manual routines. Advanced sensors detect anomalies (leakages, gas leaks, hot spots, machinery wear) early.
- **Automated Data Collection**: Provides autonomous 3D maps as a byproduct of navigation, facilitating predictive maintenance to reduce downtime.

---

## ⚙️ - ANYmal Configuration
- **Dimensions & Weight**: 800 × 600 × 700 mm | 30 kg weight | 10 kg payload.
- **Processing & Battery**: Onboard computation | 2 to 4 hours of active battery life.
- **Sensor Suite**:
  - Actuated Gimbal.
  - Visual and Thermal cameras, integrated flashlight.
  - Microphones (audible and ultrasonic sound capture).
  - LiDAR (up to 100 m range).
  - Stereo cameras (up to 7 m range).

---

## 🔍 - Inspection & Observation Capabilities
- **Multi-Modal Inspection**: Integrates visual checks, thermal anomaly detection, and acoustic assessments (audible/ultrasonic).
- **Automated Sensor Reading**: Automatically captures and reads gauges/manometers.
- **Change & Hazard Monitoring**: Uses updated maps to inspect environmental changes, detect misplaced/missing tools, and identify blocked escape doors.

---

## 🗺️ - Navigation & Deployment

### Localization & Path Planning
- Uses LiDAR, depth cameras, and ICP (Iterative Closest Point) algorithms for localization.
- Compares real-time sensor inputs against the pre-recorded map.
- Implements pose graphs for topological navigation, using A* for path planning.

### Deployment Workflow
1. **Manual Mapping**: Operator manually drives the robot via remote control. The robot scans with LiDAR and depth cameras, automatically building and saving a 3D point cloud map.
2. **Checkpoint Registration**: Operator guides the robot to inspection targets and holds an AR tag next to each checkpoint.
3. **Automatic 3D Pose Estimation**: The robot uses the AR tag pattern and its camera to compute the checkpoint's precise 3D location within the mapped coordinate system.
4. **Task Parameterization**: Operator defines the checkpoint type and operational thresholds (e.g., pressure range, temperature limits) via the GUI.

---

### Visual References
- **Obstacles**: ![[Pasted image 20260709112958.png]]
- **Sensor Autoread**: ![[Pasted image 20260709113413.png]]
- **Inspection Modalities**: ![[Pasted image 20260709113536.png]]
- **Change/Hazard Detection**: ![[Pasted image 20260709113757.png]]