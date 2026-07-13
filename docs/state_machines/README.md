# State Machines & Behavioral Logic

This directory contains transition logic, safety state triggers, and behavior diagrams for coordinating the robot's high-level missions.

---

## 1. Visual State Machine Diagrams

* **[[docs/state_machines/system_state_machine.canvas|Obsidian Canvas State Machine]]** - Interactive canvas detailing the state nodes, transition paths, and safety actions.
* **[[docs/state_machines/system_state_machine.drawio|Draw.io Vector State Machine Diagram]]** - Vector graphics flowchart showing the state transitions.

---

## 2. States & Transition Descriptions

1. **`IDLE` (Locked Stand/Lying Down):** Default boot state. Motors have low stiffness.
2. **`AUTONOMOUS_MAPPING`:** Automatically navigating the floor to sweep and construct the 3D map.
3. **`MANUAL_MAPPING` (Backup):** Human manual joystick override to guide the robot during mapping if autonomous exploration fails.
4. **`PATROL_NAVIGATION`:** Autonomously patrolling the manufacturing floor via planned waypoints.
5. **`STAND_STILL_SAFETY`:** Triggered by LiDAR dropout or connection lag. Holds current standing stance and waits.
6. **`LOW_BATTERY_RETURN`:** Triggered when battery drops below 15%, returning to docking contacts.
7. **`EMERGENCY_DAMPING`:** Triggered on rollover detection (projected gravity check) to immediately collapse legs and prevent joint damage.

---

## 3. Validation Mapping
All state machine and behavioral coordination nodes will be validated against:
* [[docs/requirements/validation_matrix#VM-01: Simulation Testing|VM-01 (Simulation)]] - Mock battery drop and network latency triggers.
* [[docs/requirements/validation_matrix#VM-04: Static Code & API Audit|VM-04 (API Audit)]] - Behavioral tree compilation checks.
