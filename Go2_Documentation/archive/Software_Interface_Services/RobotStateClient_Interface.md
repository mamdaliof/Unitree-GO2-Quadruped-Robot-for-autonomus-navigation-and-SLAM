# RobotStateClient Interface

## RobotStateClient class

RobotStateClient is a client provided by the device state service. Through RobotClient, it is convenient to control the internal services of Go2, obtain service status, device status, and system resource usage information through RPC (some functional interfaces are not yet open).

### List of interface error codes:

|Error number | Error description | Remarks|
|:---: | :--- | :---|
|5201 | Service switch execution error| Server return|
|5202 | The service is protected and cannot be turned on or off| Server return|

### Class and interface description:

|Class Name | Creation and Deconstruction|
|:---: | :---|
|RobotStateClient | explicit RobotStateClient(); ~RobotStateClient();|

| **Function name** | **ServiceSwitch** |
| --- | --- |
| **Function prototype** | int32\_t ServiceSwitch(const std::string& name, int32\_t swit, int32\_t& status) |
| **Function overview** | Service switch. |
| **Parameter** | **name**: service name <BR> **swit**: switch, value 1 for on, 0 for off. <BR> **status**: service status after the operation is executed (0: on, 1: off) |
| **Return value** | Return 0 if the call is successful, otherwise return the relevant error code. |
| **Remark** | |

|**Function Name**|**SetReportFreq**|
|:---: | :---|
|**Function Prototype**| int32_t SetReportFreq(int32_t interval, int32_t duration)|
|**Function Overview**| Set the frequency of service status reporting|
|**Parameter**|**interval**: Set the reporting time interval in seconds< BR>**duration**: Set the duration in seconds|
|**Return Value**| If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
|**Note**| Currently, the app's service status function is used and the refresh frequency is set|

| **Function Name** | **Service List** |
| --- | --- |
| **Function Prototype** | int32_t ServiceList(std::vector<ServiceState>& serviceStateList); |
| **Function Overview** | Query the current service status. |
| **Parameters** | **serviceStateList**: List of current services and their statuses. |
| **Return Value** | Returns the list upon successful call, otherwise returns the relevant error code. |
| **Remarks** | List format: Name: Service name, Status: Status, Protect: Protected status |

### Service Name List

|Service Name | Description|
|:---: |:---:|
|sport_ mode | Main motion control service （The software version is less than 1.1.6） |
|mcf | Main motion control service （The software version is greater than or equal to 1.1.6）|
|basic_ service | underlying service|
|chat_ go | Clumsy Dog Service|
|net_ switcher | Net switch|
|obstacles_ avoidance | Obstacle Avoidance Service|
|ota_ box | OTA firmware upgrade service|
|unitree_ lidar | Radar Services|
|utrack | accompanying services|
|video_ hub | Video Source Service|
|webrtc_ bridge | webrtc communication service|
|vui_ service | Offline voice service|
