import unittest
from unittest.mock import MagicMock, patch

# Simple stub of Go2StateOrchestrator to test transitions
class Go2StateOrchestrator:
    def __init__(self, robot_ctrl_mock):
        self.robot_ctrl = robot_ctrl_mock
        self.active_state = "INITIALIZATION"
        self.battery_percentage = 100.0
        self.sensor_connected = True
        self.kidnap_detected = False

    def execute_transitions(self):
        if self.active_state == "INITIALIZATION":
            if self.sensor_connected:
                self.active_state = "CALIBRATION"
            else:
                self.active_state = "STAND_STILL_SAFETY"
        elif self.active_state == "CALIBRATION":
            self.active_state = "MODE_SELECTION"
        elif self.active_state == "MODE_SELECTION":
            pass

    def check_safety_watchdog(self):
        if self.battery_percentage < 15.0:
            self.active_state = "RETURN_TO_STATION"
            self.robot_ctrl.StopMove()
        elif self.kidnap_detected:
            self.active_state = "STAND_STILL_SAFETY"
            self.robot_ctrl.StopMove()


class TestStateOrchestrator(unittest.TestCase):
    def setUp(self):
        # Create a mock for the C++ RobotInterface wrapper
        self.mock_robot = MagicMock()
        self.orchestrator = Go2StateOrchestrator(self.mock_robot)

    def test_initial_state(self):
        self.assertEqual(self.orchestrator.active_state, "INITIALIZATION")

    def test_successful_transition_flow(self):
        # Step 1: Initial state -> Calibration (on sensor connected)
        self.orchestrator.execute_transitions()
        self.assertEqual(self.orchestrator.active_state, "CALIBRATION")

        # Step 2: Calibration -> Mode Selection
        self.orchestrator.execute_transitions()
        self.assertEqual(self.orchestrator.active_state, "MODE_SELECTION")

    def test_sensor_failure_stops_robot(self):
        self.orchestrator.sensor_connected = False
        self.orchestrator.execute_transitions()
        self.assertEqual(self.orchestrator.active_state, "STAND_STILL_SAFETY")

    def test_low_battery_forces_return(self):
        # Trigger low battery state
        self.orchestrator.battery_percentage = 12.0
        self.orchestrator.check_safety_watchdog()
        
        # Verify state switches and robot is commanded to stop
        self.assertEqual(self.orchestrator.active_state, "RETURN_TO_STATION")
        self.mock_robot.StopMove.assert_called_once()

    def test_kidnap_detection_stops_robot(self):
        # Trigger kidnap state
        self.orchestrator.kidnap_detected = True
        self.orchestrator.check_safety_watchdog()
        
        # Verify state switches and robot is commanded to stop
        self.assertEqual(self.orchestrator.active_state, "STAND_STILL_SAFETY")
        self.mock_robot.StopMove.assert_called_once()


if __name__ == '__main__':
    unittest.main()
