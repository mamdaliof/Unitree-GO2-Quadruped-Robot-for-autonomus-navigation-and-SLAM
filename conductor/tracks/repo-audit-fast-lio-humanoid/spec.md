# Track Specification: repo-audit-fast-lio-humanoid

## 1. Goal
Audit the `deepglint/FAST_LIO_LOCALIZATION_HUMANOID` repository to analyze its overall project structure, robot state management, system workflow, and code structure. The audit aims to find system engineering inspiration, identify bugs or loopholes, compare it with our proposed methods, and gather code patterns for future ROS 2 integration.

## 2. Requirements & Audit Scope
The audit must resolve:
* **Project Structure & Organization:** Understand package layouts, launch structures, and system nodes.
* **Robot State & Locomotion Workflow:** How does the repository manage robot state, joint states, odometry, and localization transitions?
* **System Engineering Inspiration:** Extract architecture design points that can improve our Go2 quadruped navigation stack.
* **Bugs, Loopholes & Issues:** Identify vulnerabilities, limitations, or inefficiencies in their codebase.
* **Code Reference Extraction:** Highlight specific code components, classes, or utility scripts to serve as reference implementations for our ROS 2 packages.
* **Method Comparison:** Compare their design choices with our current Go2 system specifications to find potential gaps.

## 3. Deliverables
* **Audit Report:** Located in `docs/literature_reviews/FAST_LIO_LOCALIZATION_HUMANOID/audit_report.md` detailing all findings, architectural layouts, and comparisons.
* **Configuration Guide:** Located in `docs/literature_reviews/FAST_LIO_LOCALIZATION_HUMANOID/localization_config_guide.md` describing extrinsic configs, sensor configurations, and launch parameters.

## 4. Acceptance Criteria
* Audit repository `3rdparty/FAST_LIO_LOCALIZATION_HUMANOID` successfully completed.
* Folder `docs/literature_reviews/FAST_LIO_LOCALIZATION_HUMANOID/` contains both the Audit Report and the Configuration Guide.
* System engineering insights and comparisons are integrated into the main product/workflow/state machine documents if necessary.
