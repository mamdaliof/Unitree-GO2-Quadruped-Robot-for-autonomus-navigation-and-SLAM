# Design Choices Trade-Off Analysis

This document compiles technical evaluations of competing design alternatives across SLAM, safety fallbacks, path planning, and state coordination.

---

## 1. Avoidance & Path Planning: SDK vs. Custom Nav2

We compare using the built-in Go2 SDK avoidance versus implementing custom Nav2 planning algorithms:

| Metrics | Option A: Default SDK Avoidance | Option B: Custom ROS 2 Nav2 Planners |
| :--- | :--- | :--- |
| **Implementation Complexity** | **Very Low** (Uses built-in clients and toggle commands) | **High** (Requires writing point cloud costmap filters, configuring planners) |
| **Adaptability** | **Low** (Black-box firmware, parameters are hard to tune) | **Very High** (Full control over costmap layers, clearances, recovery behaviors) |
| **Computing Overhead** | **Zero** (Runs on the motherboard, not on the Jetson Orin NX) | **Medium to High** (Requires GPU/CPU resources on the Jetson board) |
| **Passage Clearance** | **Fixed** (Cannot squeeze through passages narrower than default limits) | **Variable** (Can dynamically adjust costmap footprint to fit narrow doors) |

### Trade-off Evaluation:
* Default SDK avoidance is chosen as the primary plan because it requires no compute overhead on the Jetson. If default firmware path planning fails in narrow elevator entries or AMC layouts, we fall back to Nav2.
* *Citation Placeholder:* [User Citation Needed]

---

## 2. Safety Fallback: Stand Still vs. Damping

We compare the robot's action when primary sensors (LiDAR) or networks experience data dropouts:

| Metrics | Option A: Stand Still (Target Choice) | Option B: Damping State |
| :--- | :--- | :--- |
| **Mechanical Stress** | **Low** (Motors maintain torque, keeping the robot standing) | **High** (Robot immediately collapses, potentially hitting the ground hard) |
| **Recovery Ease** | **High** (Once signal returns, robot immediately resumes walking) | **Medium** (Requires stand-up recovery sequence) |
| **Collision Safety** | **High** (Robot stops moving immediately) | **Medium** (Robot drops, but momentum could cause it to slide/tumble) |

### Trade-off Evaluation:
* `STAND_STILL` is chosen over `DAMPING` for connection dropouts. This avoids mechanical wear from unnecessary falls, allowing immediate resumption of patrols once connection recovers.
* *Citation Placeholder:* [User Citation Needed]

---

## 3. SLAM Backend: FAST-LIO2 vs. LIO-SAM

We evaluate the two primary real-time tightly-coupled LIO candidates:

| Metrics | Option A: FAST-LIO2 | Option B: LIO-SAM |
| :--- | :--- | :--- |
| **Onboard Compute Load** | **Very Low** | **Medium** |
| **Map Drift Recovery** | **Low** (No built-in loop closure) | **High** (Loop closure factor constraints) |
| **Configuration Complexity** | **Low** | **Medium** |

### Trade-off Evaluation:
* If Orin NX computation is constrained (due to vision/thermal projections), FAST-LIO2 is preferred. If loop closures and drift corrections are essential for large manufacturing floors, LIO-SAM is preferred.
* *Citation Placeholder:* [User Citation Needed]
