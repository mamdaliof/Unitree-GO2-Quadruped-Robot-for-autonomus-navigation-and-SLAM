# Implementation Plan: System Engineering & Documentation (`system-engineering`)

## Phase 1: Initial Research & Directory Setup
* [ ] **Step 1: Scaffolding Directory Structure**
  * Create high-level documentation directories:
    * `docs/requirements/`
    * `docs/state_machines/`
    * `docs/architecture/`
    * `docs/literature_reviews/`
    * `docs/llm_references/`
  * Create code workspace directory structure:
    * `src/go2_interfaces/` (ROS2 messages/services)
    * `src/go2_state_orchestrator/` (Python state machine package)
    * `src/go2_perception/` (C++ point cloud filtering node)
    * `src/go2_slam/` (C++ modular SLAM node placeholder)
    * `src/go2_control/` (C++ wrapper placeholder)

* [ ] **Step 2: Literature Review & Design Choices Report**
  * Analyze existing papers (ANYmal, Spot) from `literature/` and other sources.
  * Write `docs/literature_reviews/legged_robots_industrial_inspection.md` with:
    * Design choices (quadruped vs. wheels/tracks, payload, locomotion control).
    * SLAM algorithms comparison (FAST-LIO2, LIO-SAM, RTAB-Map) and why particular approaches were used.
    * Advantages, limitations, and citations.

## Phase 2: System Requirements & State Machine Design
* [ ] **Step 3: Define Requirements & Validation Matrix**
  * Write `docs/requirements/system_requirements.md` mapping out functional, performance, and safety requirements.
  * Map requirements to verification methods (simulation, bag playbacks, physical robot).

* [ ] **Step 4: State Machine & Module Interfaces Definition**
  * Design the system state machine (Idle, Mapping, Navigation, Safe-Mode, Error-Recovery).
  * Write `docs/state_machines/system_state_machine.md` with a Mermaid state diagram, state descriptions, and transition criteria.
  * Define the ROS 2 APIs (topics, services, actions) and class APIs for each package inside `docs/architecture/module_interfaces.md`.

## Phase 3: LLM-Friendly SDK Documentation
* [ ] **Step 5: Process Go2 Developer Documentation**
  * Analyze `Go2_Documentation/All_Go2_Developer_Docs.md` and related files.
  * Extract Go2 SDK API command endpoints, ROS 2 topics, and arguments.
  * Generate `docs/llm_references/go2_sdk_api_reference.json` (machine-readable) and `docs/llm_references/go2_commands_cheat_sheet.md` (optimized for LLM retrieval and human quick-reference).

## Phase 4: Verification, Test Skeletons & Final Review
* [ ] **Step 6: Secondary Repository Audit**
  * Scan relevant public ROS 2 repositories/custom Go2 implementations (using literature and internet search if needed) to validate our proposed interface structures, topic names, and state machines.
  * Update spec/docs to correct any flaws or API mismatches.

* [ ] **Step 7: Unit Test Skeletons & Verification**
  * Create gtest skeletons in `src/go2_perception/test/` to check class method expectations.
  * Create pytest skeletons in `src/go2_state_orchestrator/test/` using `launch_testing` to verify state transitions under mock conditions.
  * Verify tests build and pass with a mock build.

* [ ] **Step 8: Generate Technical Report**
  * Write `docs/technical_report.md` outlining the overall design choices, limitations, advantages, and progress summary for the system engineering phase.
