# Product Guidelines: Unitree Go2 Smart Inspection

## 1. Documentation & Writing Style (Dual Human/LLM Focus)
* **LLM-Optimized Format:** Use highly structured Markdown (`.md`) with explicit headers, lists, metadata blocks (key-value pairings), and clear tags to allow easy parsing/indexing by LLMs.
* **Concise & Human-Readable:** Keep documentation direct, emphasizing practical code examples, command-line arguments, parameter guides, and quick-start tutorials. Avoid long paragraphs; use lists and tables.
* **Obsidian-Style WikiLinks:** Cross-reference requirements, design choices, meeting notes, and files using standard wikilinks (e.g., `[[meetings/2026-06-01-meeting-poorya-leicai]]`).
* **Technical Reports:** Document design decisions, trade-offs, limitations, and advantages with academic-style citations for external sources.
* **Interactive Design Alignment:** Proactively outline technical details, explain design suggestions, and explain the proposed implementation strategy to keep the developer fully in the loop before starting work.

## 2. Code Commenting & Citation Standards
* **Insightful Class & Function Headers:** Explain the *purpose* of each class/module, its inputs/outputs, and brief usage instructions.
* **Algorithmic Annotation:** Inline comments must explain complex steps (e.g., point cloud processing, feature extraction, glass-filtering math).
* **Tagging Conventions:** Consistently use `TODO:`, `FIX:`, `HINT:`, and `WARNING:` tags to mark active tasks, bugs, tips, or potential issues.
* **Citations & References:** If code or algorithms are derived from external repositories or academic papers, explicitly cite them in the comments (e.g., `// Derived from FAST-LIO2 [https://github.com/hku-mars/FAST-LIO]`).

## 3. Testing & Quality Assurance
* **Test-Driven Development (TDD):** Define unit tests before implementing the core logic of classes or functions. Allow flexibility to modify or add unit tests as edge cases are encountered.
* **Linting & Warning Suppression:** Strive for warning-free builds. All compiler/linter warnings must be resolved or documented with clear explanations for why they are ignored.
* **Simulation Verification (Optional/Conditional):** Maintain a clear separation between hardware-dependent code and core logic to allow execution and validation in simulation (e.g., Gazebo/Webots) if available.

## 4. Workspace & Directory Structure
The project utilizes a dual-level layout:
* **High-Level Workspace:** Project documentation, meetings (`meetings/`), literature (`literature/`), daily logs (`daily-reports/`), and conductor files.
* **Development Workspace:** Standard ROS 2 workspace (e.g., `src/`, `build/`, `install/`) to hold custom packages.
* **External Integration:** Provision a dedicated folder (e.g., `src/external/` or `3rdparty/`) to hold, audit, or mimic external repositories (like custom Go2 drivers or SLAM algorithms).
