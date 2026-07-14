# Module: `go2_state_orchestrator` (Planner & State Orchestration)

This module implements the global path planning, local obstacle avoidance, autonomous exploration coordinate selection, and the high-level mission state machine.

---

## 1. Subsystem Architecture

This module implements the abstract **[PlannerInterface](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/src/go2_navigation/include/go2_navigation/planner_interface.hpp)**:

* **`PlannerInterface` Sub-class:** Generic interface for planning algorithms.
* **`Go2StateOrchestrator` Node:** High-level controller node coordinating the active system states. It has shared pointers to `RobotInterface`, `SLAMInterface`, and `PlannerInterface`.

---

## 2. Operations & Execution Workflow

1. **State Machine Management:** Coordinates transitions between mapping loops, calibration checkups, inspection patrols, and battery return-to-dock actions.
2. **Pose & Map Feed:** Receives localized coordinate positions and global grid maps from SLAM. It passes them to the planner via `UpdatePose(pose)` and `UpdateGridMap(map)`.
3. **Obstacle costmap updates:** Feeds point clouds to the local planner costmap via `UpdateCostmap(cloud)` to maintain collision clearance grids.
4. **Goal Generation & Filtering:**
   * Generates exploration targets (`GenerateFrontierGoals()`).
   * Filters goals (`FilterGoalsByFOV()`) to select targets within the forward 100° FOV preference.
5. **Path Execution:** Computes collision-free trajectories (`ComputeGlobalPath()`) and outputs commanded velocities (`ComputeLocalVelocity()`) sent to the robot interface wrapper.

---

## 3. Operational Rules & Constraints

* **Autonomous Exploration FOV:** Frontier goals are filtered to prefer the forward **100° FOV**. If the forward sector is blocked, it falls back to side and rotational exploration goals to secure loop closures.
* **Safety Watchdog:** The state machine monitors batteries and diagnostic packets. If battery level drops below **15%**, it immediately transitions to `RETURN_TO_STATION` mode.
* **Stand-Still Safety:** If a critical sensor drop or SLAM kidnap occurs, the orchestrator immediately commands the robot control interface to `StopMove()` and transitions the state machine to `STAND_STILL_SAFETY`.
