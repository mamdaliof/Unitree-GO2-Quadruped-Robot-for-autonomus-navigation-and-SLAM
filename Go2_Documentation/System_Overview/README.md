# System Overview Index & Registry

This directory contains processed general documentation covering product specifications, hardware interfaces, pilot LED status codes, debugging connection setups, and the compiled developer FAQ.

---

## 1. Directory Mapping & Content Index

To find general product information or resolve compilation issues, refer to the processed files below:

### [01_about_go2.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/System_Overview/01_about_go2.md)
* **What is in it:** Product models comparison (AIR, PRO, X, EDU), physical standing/lying dimensions, joint ranges of motion, supply voltage, torque limits, searchlights, and accessory hardware listings (NVIDIA Jetson, D435i, Mid-360, XT-16, D1 mechanical arm).
* **Original raw file:**
  * [About_Go2.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/About_Go2.md)

### [02_debugging_and_wiring.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/System_Overview/02_debugging_and_wiring.md)
* **What is in it:** Ethernet wired connections for User PC to Dock communication, SBUS receiver pin interfaces, remote controllers button mappings, Nomachine remote GUI scripts, and pilot lamp status indicator codes.
* **Original raw files:**
  * [Debugging_Specification.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Debugging_Specification.md)
  * [Remote_Controller.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Remote_Controller.md)
  * [FAQ.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/FAQ.md)

### [03_faq.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/System_Overview/03_faq.md)
* **What is in it:** Complete compiled list of developer FAQs, including file permissions, hanging-power failures, obstacle detection rules, cmake compiler missing setups, opencv4 linking soft links, and PyTorch dependency installations.
* **Original raw file:**
  * [FAQ.md](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/FAQ.md)

---

## 2. Project Relevance
* **Hardware Constraints:** Specifications (`01_about_go2.md`) outline joint range limits (e.g. calf joint limits `[-156° ~ -48°]`), which are set as software bounds in our joint controllers.
* **Pilot LEDs (`02_debugging_and_wiring.md`):** LED colors provide direct feedback on state changes (e.g., permanently on blue signals that obstacle avoidance is disabled, while yellow signals companion mode).
* **Workspace Setup (`03_faq.md`):** Resolves environment compilation issues (OpenCV link errors, missing CMake compilers) when building the ROS 2 packages.
