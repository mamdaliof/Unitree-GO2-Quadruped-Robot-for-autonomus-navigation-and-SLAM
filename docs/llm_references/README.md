# LLM Developer References

This directory contains intermediate representations of the Go2 SDK and ROS 2 package parameters, structured specifically to help AI agents index and context-query the codebase.

---

## 1. Directory Contents

* **[go2_sdk_api_reference.json](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/docs/llm_references/go2_sdk_api_reference.json):** A structured registry mapping CycloneDDS topics, message formats, high-level client RPCs, and default values.
* **[go2_commands_cheat_sheet.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/docs/llm_references/go2_commands_cheat_sheet.md):** A markdown cheat sheet mapping high-level movement commands, absolute positioning calls, and relative displacements.

---

## 2. Usage Instructions
AI agents can read `go2_sdk_api_reference.json` directly to retrieve topic structures and commands without parsing raw C++ header files.
