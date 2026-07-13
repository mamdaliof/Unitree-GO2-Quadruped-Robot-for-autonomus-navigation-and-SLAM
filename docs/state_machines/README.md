# State Machines & Behavioral Logic

This directory contains transition logic, safety state triggers, and behavior tree designs for coordinating the robot's high-level missions.

---

## 1. Directory Contents

* **`system_state_machine.md` (Pending):** Transition criteria and states (Idle, Stand Stand-still, Autonomous Mapping, Patrol Navigating, Emergency Stop, Return-to-Dock) modeled using Mermaid flowcharts.
* **`recovery_sequences.md` (Pending):** Specific step-by-step procedures for handling joint shutdowns, orientation rollovers, and network packet dropouts.

---

## 2. Validation Mapping
All state machine and behavioral coordination nodes will be validated against:
* [[docs/requirements/validation_matrix#VM-01: Simulation Testing|VM-01 (Simulation)]] - Mock battery drop and network latency triggers.
* [[docs/requirements/validation_matrix#VM-04: Static Code & API Audit|VM-04 (API Audit)]] - Behavioral tree compilation checks.
