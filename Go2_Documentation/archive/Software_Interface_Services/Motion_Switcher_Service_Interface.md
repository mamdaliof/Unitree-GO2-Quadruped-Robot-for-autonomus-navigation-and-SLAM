# Motion Switcher Service Interface

!!! note  **Applicable Scope**  

This document's interface description is applicable to the **Go2 Edu model**.  

  - Should you have any other questions, you are welcome to [contact official technical support](https://serviceconsole.unitree.com/#/work-order).  

Thank you for your support!

!!!

## Motion Control Mode Name Description

| Service Name | Motion Control Service Version |
| --- | --- |
| mcf | $\ge$1.1.6 |
| ai=AI Mode, normal = Normal Mode, advanced = Advanced Mode | \<1.1.6 |

## MotionSwitcherClient Class

MotionSwitcherClient is the Client provided by the motion control switching service. Through MotionSwitcherClient, you can easily switch the Go2 motion control mode via RPC. It also provides interfaces to set or get whether Go2 is in a silent state (when Go2 is in a silent state, Go2's default motion controls are not started, and this setting remains effective after Go2 restarts).

### Interface Error Code List

| Error Number | Error Description | Notes |
| --- | --- | --- |
| 7001 | Request parameter error. | Server response |
| 7002 | Switching service is busy, please try again later. | Server response |
| 7004 | Motion control mode name is not supported. | Server response |
| 7005 | Internal command execution error in motion control mode. | Server response |
| 7006 | Detection command execution error in motion control mode. | Server response |
| 7007 | Switching command execution error in motion control mode. | Server response |
| 7008 | Release command execution error in motion control mode. | Server response |
| 7009 | Custom configuration error. | Server response |

### Class and Interface Description

| Class Name | Construction and Destruction |
| --- | --- |
| MotionSwitcherClient | explicit MotionSwitcherClient(); \</BR\> \~MotionSwitcherClient(); |

| **Function Name** | **CheckMode** |
| --- | --- |
| **Function Prototype** | int32\_t CheckMode(std::string& form, std::string& name) |
| **Function Summary** | Detects the current form and motion control mode. |
| **Parameters** | **form**: The current Go2 form. "0" for Standard Form; "1" for Wheel-Foot Form \<BR\> **name**: Motion control mode name. Please refer to "Motion Control Mode Name" above for details. |
| **Return Value** | Returns 0 if the call is successful, otherwise returns the relevant error code. |
| **Notes** | |

| **Function Name** | **SelectMode** |
| --- | --- |
| **Function Prototype** | int32\_t SelectMode(const std::string& name) |
| **Function Summary** | Selects the motion control mode. |
| **Parameters** | **name**: Motion control mode name. |
| **Return Value** | Returns 0 if the call is successful, otherwise returns the relevant error code. |
| **Notes** | |

| **Function Name** | **ReleaseMode** |
| --- | --- |
| **Function Prototype** | int32\_t ReleaseMode() |
| **Function Summary** | Releases the motion control mode. |
| **Parameters** | None |
| **Return Value** | Returns 0 if the call is successful, otherwise returns the relevant error code. |
| **Notes** | |

| **Function Name** | **SetSilent** |
| --- | --- |
| **Function Prototype** | int32\_t SetSilent(bool silent) |
| **Function Summary** | Sets the silent state. |
| **Parameters** | **silent:** Whether to set the silent state |
| **Return Value** | Returns 0 if the call is successful, otherwise returns the relevant error code. |
| **Notes** | |

| **Function Name** | **GetSilent** |
| --- | --- |
| **Function Prototype** | int32\_t GetSilent(bool& silent) |
| **Function Summary** | Gets the silent setting. |
| **Parameters** | **silent:** Whether the silent state is set |
| **Return Value** | Returns 0 if the call is successful, otherwise returns the relevant error code. |
| **Notes** | |
