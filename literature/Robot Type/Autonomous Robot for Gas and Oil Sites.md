---
aliases: ["A Review of Quadruped Robots: Structure, Control, and Autonomous Motion - Notes"]
created: ["09-07-2026 17:25"]
tags:
- Literature/Notes
- Project/LearningFactory
---

# 📝 Paper Notes -> A Review of Quadruped Robots

---
## 📢 - Metadata & Context
- **Context**: Challenge introduced by [TotalEnergies](https://totalenergies.com/).
- **Rationale for Autonomous Inspection**: Operators spend ~5.5 hours per shift on repetitive tasks. Automation reduces operational costs and human exposure.
- **Key Tasks for Automation**:
  - Visual routine inspection
  - Process parameter monitoring
  - Gauge reading
  - Fluid sampling

---

## 💡 - Identified Robotic Solutions

### 1. MIMROex
- **Developer & Date**: Fraunhofer IPA, 2011.
- **Navigation & Control**: SLAM-based navigation with teleoperation teach-and-repeat capability.
- **Payload**: 6 DOF end-effector.
- **Infrastructure**: Network connectivity required.
- **Sensors**: Camera, fire sensor, gas sensor.

### 2. SENSABOT
- **Developer**: NREC - Carnegie Mellon University.
- **Navigation & Control**: Teleoperation.
- **Design**: Cog-rail complementary structure.
- **Sensors**: Laser scanner, camera, thermal camera, vibration sensor, toxic gas sensor.

![[Pasted image 20260709171012.png]]

---

## 🏢 - Target Environment Constraints
- **Layout**: Multi-floor industrial environment.
- **Mobility**: Robot must autonomously ascend and descend stairs to traverse levels.
- **Footprint**: Site area is approximately 15 × 15 meters.
- **Obstacles**: Layout contains pipes, drums, columns, valves, pumps, and associated instrumentation.
- **Connectivity & Power**: Wireless communication is mandatory. Robot must be battery-powered with adequate runtime autonomy.

---

## 💠 - Action Items (Check Later)
- [ ] Research SENSABOT (Carnegie Mellon University / NREC).
- [ ] Review MIMROex development details (Fraunhofer IPA).
- [ ] Investigate general surface robotics.