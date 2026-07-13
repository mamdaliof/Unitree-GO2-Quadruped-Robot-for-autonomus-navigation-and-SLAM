# Basic Motion Control

This article introduces how to use **unitree_sdk2** calls the underlying interface to develop the Go2 robot, and the relevant code file is `go2_low_level.cpp` under the`unitree_sdk2/example/go2` path. In this routine, we will demonstrate how to call the underlying interface to control the right front leg swing of a quadruped robot. The method to run this routine can be found in the "[Quick Start](https://support.unitree.com/home/en/developer/Quick_start) This article will not go into detail here.

## Program Analysis

### Custom Class

In the `Custom` class, classes and functions related to DDS communication are defined, as well as some variables related to controlling leg swing.

#### Member variables

##### Variables related to leg control

|<div style="width: 80pt">Name</div> | <div style="width: 90pt">Type</div> | Description|
| :---: | :---: | :--- |
|  qInit  |  float type array  |  Used in this example to record the initial joint angles of each joint in the right front leg |
|  qDes  |  float type array  | In this example, it is used to express the expected joint angle of each joint in the right front leg  |
|  sin_mid_q  |  float type array  |  In this example, it is used to specify the intermediate joint angle in the cyclic reciprocating motion of each joint in the right front leg  |
|  Kp  |  float type array  |  In this example, it is used to specify the joint space control kp value of each joint in the right front leg  |
|  Kd  |  float type array  |  In this example, it is used to specify the joint space control Kd value of each joint in the right front leg |

##### Communication related variables

|<div style="width: 130pt">Name </div>|<div style="width: 130pt"> Type</div> | Description| 
| :---: | :--- | :--- |
|  lowcmd\_publisher  |  ChannelPublisherPtr<unitree\_go::msg::dds\_::LowCmd\_>  |  The underlying command sends the object, and calling the Write function of the object will send the underlying control command once to the Go2 robot  |
|  lowstate\_subscriber  |  ChannelSubscriberPtr<unitree\_go::msg::dds\_::LowState\_>  |  Subscribing objects to low-level status information, including motor information, IMU data, Unitree handle information, etc  |
|  lowCmdWriteThreadPtr  |  ThreadPtr  |  DDS related underlying command sending thread pointer |
|  cmd  |  unitree\_go::msg::dds\_::LowCmd\_  | The underlying command structure related to DDS is ultimately sent to the Go2 robot through DDS, which is different from LowCmd low\_cmd |
|  state  |  unitree\_go::msg::dds\_::LowState\_  |  DDS related underlying state structures  |
|  low\_cmd  |  UNITREE\_LEGGED\_SDK::LowCmd   |  UNITREE\_LEGGED\_SDKtype structure for underlying control commands  |
|  low\_state  |  UNITREE\_LEGGED\_SDK::low\_state   |  UNITREE\_LEGGED\_SDKStructure of SDK type regarding underlying state information  |

The variables related to communication can be mainly divided into two types: UNITREE\_LEGGED\_SDK Types and unitree\_go::msg::dds\_ The types and their relationships are shown in the following figure:
<center>

![](https://doc-cdn.unitree.com/static/2023/10/18/c6773a5a637a483ba15534118138c2d7_308x677.png)

</center>

In this routine, the user logic for controlling leg swing is first used with `UNITREE_LEGGED_SDK` type variable is expressed, and then converted to DDS related types through functions provided in some routines before sending commands to the Go2 robot. This is because SDK for robots such as A1 and Go1 also use `UNITREE_LEGGED_SDK` type, this is for the convenience of previous users to continue and migrate.

#### Member function

 **InitLowCmd()**

```C++
    void Custom::InitLowCmd()
    {
        low_cmd.head[0] = 0xFE; 
        low_cmd.head[1] = 0xEF;
        low_cmd.levelFlag = 0xFF;
        low_cmd.gpio = 0;
    
        for(int i=0; i<20; i++){
            low_cmd.motorCmd[i].mode = (0x01);   // motor switch to servo (PMSM) mode
            low_cmd.motorCmd[i].q = (PosStopF);
            low_cmd.motorCmd[i].Kp = (0);
            low_cmd.motorCmd[i].dq = (VelStopF);
            low_cmd.motorCmd[i].Kd = (0);
            low_cmd.motorCmd[i].tau = (0);
        }
    }
```

    
    

`InitLowCmd()` This function is used to initialize and set the `LowCmd` of type `low_cmd` structure. This function can be placed in the constructor of the `Custom` class and run once. Here are some key points:

1. The head member in the `LowCmd` type represents the frame header, which will be used for CRC verification Set the `head`, `levelFlag`, `gpio`, etc. to the default values as shown in the routine.

   
2. There are 20 members of `motorCmd` in the `LowCmd` type, each with a command to control a corresponding motor on the Go2 robot. However, there are only 12 motors on the Go2 robot, so only the first 12 are valid, and the remaining 8 are reserved.
    
3. `low_cmd.motorCmd[i].mode = (0x01)` ; This command sets the `mode` variable of the `motorCmd` member to 0x01, where 0x01 indicates that the motor is set to servo mode. If the user finds that they cannot control the joint motor of the Go2 robot during debugging, please check if the value of the variable is 0x01.

**LowStateMessageHandler**

The function is a DDS callback function for receiving low-level state information, and the DDS mechanism will trigger this callback function at a certain frequency. Each time the callback function is triggered, the underlying state information will be updated once.

 **LowCmdwriteHandler**()

The purpose of this function is to send a callback function for the underlying control command, which DDS will trigger at a certain frequency. The first part of the code for this callback function represents the user logic for calculating the right front calf swing control command, while the second part sends the control command to the Go2 robot.

```C++
    void LowCmdwriteHandler()
{
     motiontime++;
    
        for(int i=0; i<12; i++){
          printf("%f ", state.motor_state()[i].q());
        }
        printf("\n");
    
        // if( motiontime >= 100){
        if (motiontime >= 0){
            // first, get record initial position
            if (motiontime >= 0 && motiontime < 20){
                qInit[0] = state.motor_state()[FR_0].q();
                qInit[1] = state.motor_state()[FR_1].q();
                qInit[2] = state.motor_state()[FR_2].q();
            }
            // second, move to the origin point of a sine movement with Kp Kd
            if (motiontime >= 10 && motiontime < 400) {
                rate_count++;
                double rate = rate_count / 200.0; // needs count to 200
                Kp[0] = 5.0; Kp[1] = 5.0; Kp[2] = 5.0;
                Kd[0] = 1.0; Kd[1] = 1.0; Kd[2] = 1.0;
    
                qDes[0] = jointLinearInterpolation(qInit[0], sin_mid_q[0], rate);
                qDes[1] = jointLinearInterpolation(qInit[1], sin_mid_q[1], rate);
                qDes[2] = jointLinearInterpolation(qInit[2], sin_mid_q[2], rate);
            }
            double sin_joint1, sin_joint2;
            // last, do sine wave
            float freq_Hz = 1;
            // float freq_Hz = 5;
            float freq_rad = freq_Hz * 2 * M_PI;
            float t = dt * sin_count;
            if (motiontime >= 400){
                sin_count++;
                sin_joint1 = 0.6 * sin(t * freq_rad);
                sin_joint2 = -0.9 * sin(t * freq_rad);
                qDes[0] = sin_mid_q[0];
                qDes[1] = sin_mid_q[1] + sin_joint1;
                qDes[2] = sin_mid_q[2] + sin_joint2;
            }
    
            low_cmd.motorCmd[FR_2].q = qDes[2];
            low_cmd.motorCmd[FR_2].dq = 0;
            low_cmd.motorCmd[FR_2].Kp = Kp[2];
            low_cmd.motorCmd[FR_2].Kd = Kd[2];
            low_cmd.motorCmd[FR_2].tau = 0;
        }
        low_cmd.crc = crc32_core((uint32_t *)&low_cmd, (sizeof(LowCmd)>>2)-1);
    
        lowCmd2Dds(low_cmd, cmd);
        lowcmd_publisher->Write(cmd);
 }
```
The three if statements in the above code block can divide the user logic into three parts:
1. if (motiontime >= 0 && motiontime < 20) -> Record the initial joint angle
2.  if (motiontime >= 10 && motiontime < 400) -> Move to the starting angle of reciprocating motion
3.   if (motiontime >= 400) -> Start reciprocating motion

The following will explain:

1. Record the initial joint angle

```C++
  
  if (motiontime >= 0 && motiontime < 20)
{
  qInit[0] = state.motor_state()[FR_0].q();
  qInit[1] = state.motor_state()[FR_1].q();
  qInit[2] = state.motor_state()[FR_2].q();
}
  
```
This code indicates that when the `motiontime` is less than 20, the joint angle values of the body joint (FR_0), thigh joint (FR_1), and calf joint (FR_2) of the right front leg (FR) will be read and assigned to the elements in the `qInit` array. It can be summarized that the purpose of this code is to record the initial position of the right front leg, as shown in the following figure

![](https://doc-cdn.unitree.com/static/2023/10/18/339568d549984c76b299ec2dd318598e_1004x763.png)

2. Starting angle from motion to reciprocating motion

```C++
  
  if (motiontime >= 10 && motiontime < 400) {
    rate_count++;
    double rate = rate_count / 200.0; // needs count to 200
    Kp[0] = 5.0; Kp[1] = 5.0; Kp[2] = 5.0;
    Kd[0] = 1.0; Kd[1] = 1.0; Kd[2] = 1.0;
    
    qDes[0] = jointLinearInterpolation(qInit[0], sin_mid_q[0], rate);
    qDes[1] = jointLinearInterpolation(qInit[1], sin_mid_q[1], rate);
    qDes[2] = jointLinearInterpolation(qInit[2], sin_mid_q[2], rate);
  }
}
```
  
The purpose of this code segment is to calculate the control command `qDes`, which will drive the right front leg joints to slowly move from the angle specified in the `qDes` array to the joint angle specified in the `sim_mid_q`array, as shown in the following figure

![](https://doc-cdn.unitree.com/static/2023/9/26/6c7a23c310e441559dbd38b89b8c2612_1388x1080.gif)

3. Start reciprocating motion

```C++
  
double sin_joint1, sin_joint2;
// last, do sine wave
float freq_Hz = 1;
// float freq_Hz = 5;
float freq_rad = freq_Hz * 2 * M_PI;
float t = dt * sin_count;
if (motiontime >= 400)
{
  sin_count++;
  sin_joint1 = 0.6 * sin(t * freq_rad);
  sin_joint2 = -0.9 * sin(t * freq_rad);
  qDes[0] = sin_mid_q[0];
  qDes[1] = sin_mid_q[1] + sin_joint1;
  qDes[2] = sin_mid_q[2] + sin_joint2;
}
    
low_cmd.motorCmd[FR_2].q = qDes[2];
low_cmd.motorCmd[FR_2].dq = 0;
low_cmd.motorCmd[FR_2].Kp = Kp[2];
low_cmd.motorCmd[FR_2].Kd = Kd[2];
low_cmd.motorCmd[FR_2].tau = 0;
  
```
The purpose of this code is to calculate the control command `qDes`, which will drive the calf joint in the right front leg to swing around the joint angle specified in the `sim_mid_q` array. As shown in the figure below, the right front calf will swing within the sin_mid_q[2] ± 0.9 rad range, as shown in the figure below

![](https://doc-cdn.unitree.com/static/2023/9/26/e4b7693bb5134493a0a202af30e11d54_1388x1080.gif)

```C++
  
  low_cmd.crc = crc32_core((uint32_t *)&low_cmd, (sizeof(LowCmd)>>2)-1);
lowCmd2Dds(low_cmd, cmd);
lowcmd_publisher->Write(cmd);
  
```
The first line of this code first calculates the CRC checksum. The second line of code uses the `lowCmd2Dds()` function to convert `UNITREE_LEGGED_SDK::low_cmd` variable conversion to DDS  `unitree_go::msg::dds_::LowCmd`_ The `cmd` variable of type. The last line of code represents calling the `Write()` function of `lowcmd_publisher` to send control commands to the Go2 robot.

### DDS conversion function

The following is a series of DDS related conversion functions. When users express control logic, the main focus is on `UNITREE_LEGGED_SDK::LowCmd` and `UNITREE_LEGGED_SDK::LowState` These two types of variables are operated on because they have higher readability. When actually sending commands or obtaining status information to the Go2 robot, it is done through `unitree_go::msg::dds_::LowCmd_` and `unitree_go::msg::dds_::LowState_`  These two types of structures.

Therefore, it is necessary to convert these two types of structures through some conversion functions. Users can focus on the `lowCmd2Dds()` and `dds2LowState()` conversion functions. For intermediate functions, there is no need to overly focus on implementation details. When using them, simply copy and paste them.

|Name | Description|
| --- | --- |
|  void dds2Imu(unitree\_go::msg::dds\_::IMUState\_& dds, IMU& raw)  |  On the Conversion Function of IMU State Information，convert unitree\_go::msg::dds\_::IMUState\_ to UNITREE\_LEGGED\_SDK::IMUis an intermediate function.  |
|  void dds2BmsState(unitree\_go::msg::dds\_::BmsState\_& dds, BmsState& raw)  | Regarding the conversion function of IMU status information, convert unitree\_go::msg::dds\_::IMUState\_ Convert to UNITREE\_LEGGED\_SDK::IMU, which is an intermediate function.
  |
|  void dds2MotorState(std::array<unitree\_go::msg::dds\_::MotorState\_, 20>& dds, MotorState\* raw)  |  Regarding the conversion function of motor state information, unitree\_go::msg::dds\_::MotorState\_ Convert to UNITREE\_LEGGED\_SDK::MotorState, which is an intermediate function.
  |
|  void dds2LowState(unitree\_go::msg::dds\_::LowState\_& dds, LowState& raw)  |  Convert UNITREE\_LEGGED\_SDK::LowState to unitree\_go::msg::dds\_::LowState\_  |
|  void motorCmd2Dds(MotorCmd\* raw, std::array<unitree\_go::msg::dds\_::MotorCmd\_, 20>& dds)  |  Regarding the conversion function of motor control commands,convert UNITREE\_LEGGED\_SDK::MotorCmd to unitree\_go::msg::dds\_::MotorState\_is an intermediate function.  |
|  void bmsCmd2Dds(BmsCmd& raw, unitree\_go::msg::dds\_::BmsCmd\_& dds)  |  Regarding the conversion function of battery management commands, convert UNITREE\_LEGGED\_SDK::BmsCmd to unitree\_go::msg::dds\_::BmsCmd\_ is an intermediate function.  |
|  void lowCmd2Dds(LowCmd& raw, unitree\_go::msg::dds\_::LowCmd\_& dds)  |  convert UNITREE\_LEGGED\_SDK::LowCmd  to unitree\_go::msg::dds\_::LowCmd\_。  |
|  void crc32\_core(uint32\_t\* ptr, uint32\_t len)  | The crc verification function is an intermediate function. |
