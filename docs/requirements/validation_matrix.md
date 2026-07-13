# System Validation & Verification Matrix

This document defines the validation methods used to verify each requirement from the `[[docs/requirements/system_requirements|System Requirements Specification]]`.

---

## 1. Verification Methods (VM)

We define four primary verification methods to validate software and hardware behaviors:

* **VM-01: Simulation Testing**
  * Executing the control, planning, and state machine modules in a simulated environment with mock sensor streams.
* **VM-02: Offline Rosbag Replay (Conditional)**
  * Replaying pre-recorded sensor datasets through SLAM and perception nodes. Because a continuous global ground-truth system (like motion capture) is not present initially, accuracy is verified conditionally:
    * **Condition A (No External Reference):** Qualitative validation. Map consistency is evaluated by measuring  drift alignment when returning to the starting node. (might not possible because we cannot bring the robot exactly same location as before)
    * **Condition B (Static Reference Sensors/Markers Active):** Quantitative validation. If static external distance sensors or physical retroreflective markers are set up along the path, compare the robot's calculated SLAM trajectory coordinates at those specific checkpoints against the physical static sensor ground-truth measurements recorded in the rosbag.
* **VM-03: Physical Hardware Testing**
  * Deploying compiled nodes onto the physical Go2 Edu robot in a spacious, supervised test area (Cube, basement, or AMC) under safe-mode constraints (velocity $< 0.3$ m/s, human supervisor with manual override).
* **VM-04: Static Code & API Audit**
  * For software consistency, passing testing scripts and unittests, compilation warnings checks, and static ROS 2 topic/message schema validation.

---

## 2. Requirement-to-Method Mapping Matrix

| Req ID          | Requirement Title       | Verification Method                            | Validation Test Description                                                                                                                                                                   |
| :-------------- | :---------------------- | :--------------------------------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **REQ-FUN-001** | Mapping Workflow        | **VM-01** (Simulation)<br>**VM-03** (Physical)<br>**VM-04** (API Audit) | Test autonomous exploration path generation in simulation. Verify manual joystick override immediately interrupts autonomous mapping on the physical robot. Run static orchestrator audits.    |
| **REQ-FUN-002** | Staged Sensors          | **VM-02** (Rosbag)<br>**VM-04** (API Audit)    | Replay pre-recorded datasets through Phase 1, Phase 2, and Phase 3 pipelines. Check that coordinate transform matrices update correctly without compilation or DDS runtime errors.            |
| **REQ-FUN-003** | Locomotion Commands     | **VM-01** (Simulation)<br>**VM-03** (Physical)<br>**VM-04** (API Audit) | Send target coordinate displacement vectors (absolute and relative) over standard topics. Verify the robot moves to the correct coordinates within $\pm 10\text{ cm}$ bounds. Run API audits. |
| **REQ-FUN-004** | Safe Avoidance          | **VM-01** (Simulation)<br>**VM-03** (Physical)<br>**VM-04** (API Audit) | Place dynamic obstacles in front of the robot. Verify the robot either halts or plans a path around the obstacle without collision. First test built-in SDK; fall back to Nav2. Run planner API checks. |
| **REQ-SFT-001** | Operational Constraints | **VM-01** (Simulation)<br>**VM-03** (Physical)<br>**VM-04** (API Audit) | Command velocity $> 1.0\text{ m/s}$ and verify output is capped at $1.0\text{ m/s}$. Mock battery state at $14\%$ and verify the state machine triggers a return-to-dock sequence. Run state parameter checks. |
| **REQ-SFT-002** | Safety Fallbacks        | **VM-01** (Simulation)<br>**VM-03** (Physical)<br>**VM-04** (API Audit) | Disconnect the LiDAR feed node. Confirm the state machine immediately stops the robot's movement and sets state to `STAND_STILL`. Run safety flag code checks.                            |
| **REQ-ENV-002** | Localization Accuracy   | **VM-02** (Rosbag)<br>**VM-03** (Physical)<br>**VM-04** (API Audit)     | Walk the robot past pre-surveyed physical landmarks (retroreflective markers). Compare the SLAM calculated position against the physical landmark ground truth. Target error $< 5\text{ cm}$. Verify SLAM node ROS 2 message conformity. |
