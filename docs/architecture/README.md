# System Architecture & Design Diagrams

This directory contains UML component diagrams, design choices, morphological diagrams, and trade-off matrices for the Go2 Smart Navigation system.

---

## 1. Architecture Diagrams

* **[[docs/architecture/system_architecture.canvas|Obsidian Canvas System Architecture Diagram]]** - Native Obsidian Canvas layout showing the OOP C++ class interfaces, concretes, inheritances, fields, methods, and package associations.
* **[[docs/architecture/system_architecture.drawio|UML System Architecture Diagram]]** - Draw.io UML diagram detailing class fields, methods, and topic subscription mappings across our proposed ROS 2 packages:
  * `go2_control` (high-level motor wrapping client node)
  * `go2_state_orchestrator` (behavior tree orchestrator node)
  * `go2_perception` (point cloud filtration and costmap node)
  * `go2_slam` (tightly-coupled LIO mapping backend node)
* **[[docs/architecture/modules/README|UML Subsystem Modules Documentation]]** - Dedicated documentation files detailing operational rules, constraints, and execution pipelines for each modular package.

---

## 2. Interactive System Engineering Files

These documents serve as active workspaces for brainstorming alternative engineering selections and researching SOTA integrations:

* **[[docs/architecture/key_questions|Key Questions & Pending Research]]** - List of unresolved engineering issues requiring user-provided citations (e.g. measuring 5cm accuracy, mapping slopes, dynamic CPU limits).
* **[[docs/architecture/morphological_diagram|Subsystem Morphological Diagram]]** - Compiles option parameters across all modular software blocks.
* **[[docs/architecture/tradeoff_analysis|Design Choices Trade-Off Analysis]]** - Compares option benefits and limitations (SDK vs Nav2, stand-still fallbacks, SLAM backends).
