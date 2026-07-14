# UML Subsystem Modules Documentation

This directory contains the detailed documentation, operational rules, and execution constraints for each of the top-level modular packages in the Go2 navigation and SLAM workspace.

---

## 1. Subsystem Modules Directory

* **[control.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/docs/architecture/modules/control.md):** Low-level driver connection wrappers, MCF switcher silent modes, command timeout watchdogs, and velocity caps.
* **[perception.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/docs/architecture/modules/perception.md):** Spatial calibrations, LiDAR extrinsic transformations, raw stream handlers, and 3D bounding box self-filtering dimensions.
* **[slam.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/docs/architecture/modules/slam.md):** Mapping phase, global PCD map loading/saving persistence, localization, and kidnap-detection watchdogs.
* **[state_orchestrator.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/docs/architecture/modules/state_orchestrator.md):** State machine, mission transitions, frontier goal generation, FOV path planner limits, and battery return triggers.
