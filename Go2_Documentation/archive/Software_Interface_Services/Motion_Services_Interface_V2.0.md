# Motion Services Interface V2.0

!!! note  Attention:

### Motion Control Service Interface V2.0 Update Notice

**Release Date**: May 12, 2025  
**Version Update Content**: Go2 officially releases V1.1.6. This update primarily involves adjustments to high-level motion control interfaces and calling logic, with corresponding SDK updates.

---

#### Compatibility Instructions

- **Applicability**: This document's interfaces apply to **Go2 Edu models** with software version ≥ V1.1.6. 
- **SDK Update**: Before calling interfaces, ensure you update [unitree_sdk2](https://github.com/unitreerobotics/unitree_sdk2) to the latest version.

---

#### Version Check & Compatibility

- **Version Check**: Use the **Unitree App** to check your device's current software version.  
- If your Go2 software version is below V1.1.6, refer to these legacy documents:  
  - [Motion Switcher Service Interface](https://support.unitree.com/home/en/developer/Motion%20Switcher%20Service%20Interface)  
  - [High-Level Motion Service Interface](https://support.unitree.com/home/en/developer/sports_services)  
  - [AI Motion Service Interface](https://support.unitree.com/home/en/developer/AI_motion_service)  

---

Thank you for your support! For questions, [contact official technical support](https://global-serviceconsole.unitree.com/#/).  

!!!

# Introduction

The high-level interface of operation control service is divided into two parts: high-level control interface and high-level status interface.

- **High-level control interface**: By calling the `sport_client` of the SDK, motion commands such as mode switching and speed control can be sent to Go2.
- **High-level status interface**: By subscribing to the `sportmodestate` message in the SDK, you can obtain the motion status of Go2, including its position, speed, attitude, and current motion mode.

# High-level control interface

## Call method of high-level control interface

```C++

#include <unitree/robot/go2/sport/sport_client.hpp>
#include <unistd.h>

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
  // argv[1] is passed from the terminal and represents the network interface name of the robot's connection

  // Create a sport client object
  unitree::robot::go2::SportClient sport_client;
  sport_client.SetTimeout(10.0f); // Set timeout
  sport_client.Init();

  sport_client.Sit(); // Special action: the robot sits down
  sleep(3); // Delay for 3 seconds
  sport_client.RiseSit(); // Recover
  sleep(3);

  return 0;
}

```

## Introduction to High-Level Motion Control Interfaces

The high-level control interface can achieve control of Go2's posture, speed, somersaults, jumps, handstands, and more. Below is a list of related functions for the motion control interface.

| **Function Name**   | **Damp**                                                                                   |
|---------------------|--------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t Damp()`                                                                          |
| **Function Overview**| Enter damping state.                                                                      |
| **Parameters**      | None                                                                                      |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                      |
| **Notes**           | All motor joints stop moving and enter damping state. This mode has the highest priority and is used for emergency stops in unexpected situations. |

| **Function Name**   | **BalanceStand**                                                                                                    |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t BalanceStand()`                                                                                             |
| **Function Overview**| Release lock.                                                                                                       |
| **Parameters**      | None                                                                                                                                               |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | Release the joint motor lock and switch from normal standing mode to balance standing mode. In this mode, the robot's posture and height will remain balanced regardless of terrain. You can control the robot's posture by calling the Euler() interface (see corresponding sections in the table). |

| **Function Name**   | **StopMove**                                                                                                         |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t StopMove()`                                                                                                 |
| **Function Overview**| Stop the current movement and reset most parameters to their default values.                                        |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | Stops the current motion and resets the internal motion parameters of Go2 to their default values.                  |

| **Function Name**   | **StandUp**                                                                                                         |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t StandUp()`                                                                                                  |
| **Function Overview**| Lock joints and stand tall.                                                                                         |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | The robot stands tall with locked joints. Unlike the balance standing mode, the robot's posture will not remain balanced in this mode. The default standing height is 0.33m. Locked posture can easily cause motor overheating, so please unlock in time. |

| **Function Name**   | **StandDown**                                                                                                        |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t StandDown()`                                                                                                 |
| **Function Overview**| Lock joints and crouch low.                                                                                         |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | The robot crouches low with locked joints.                                                                          |

| **Function Name**   | **RecoveryStand**                                                                                                    |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t RecoveryStand()`                                                                                              |
| **Function Overview**| Recover to standing position.                                                                                       |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | Recover from a fallen or crouched state to a balanced standing position. Regardless of whether it is fallen or not, it will recover to standing. |

| **Function Name**   | **Euler**                                                                                                            |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t Euler(float roll, float pitch, float yaw)`                                                                 |
| **Function Overview**| Posture during standing and walking.                                                                                |
| **Parameters**      | **roll:** Range \[-0.75~0.75\] (rad); **pitch:** Range \[-0.75~0.75\] (rad); **yaw:** Range \[-0.6~0.6\] (rad).       |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | Set the robot's posture angle during balanced standing or movement. The Euler angles are represented in the order of rotation around the robot's relative axes and z-y-x. |

| **Function Name**   | **Move**                                                                                                             |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t Move(float vx, float vy, float vyaw)`                                                                       |
| **Function Overview**| Movement control.                                                                                                   |
| **Parameters**      | **vx:** Range \[-2.5~3.8\] (m/s); **vy:** Range \[-1.0~1.0\] (m/s); **vyaw:** Range \[-4~4\] (rad/s).                 |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | Control movement speed. The set speed is represented in the robot's coordinate system. The Move interface has two characteristics: (1) The motion control part does not filter the Move command; (2) The latest Move command will be maintained for 1 second. Recommendation: When using this interface, apply filtering before sending; when not using Move, send Move(0,0,0) or StopMove(). |

| **Function Name**   | **Sit**                                                                                                              |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t Sit()`                                                                                                       |
| **Function Overview**| Sit down.                                                                                                            |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | Special action: the robot sits down. Note that special actions should be executed only after the previous action has been completed; otherwise, it may cause abnormal actions. |

| **Function Name**   | **RiseSit**                                                                                                          |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t RiseSit()`                                                                                                   |
| **Function Overview**| Stand up (relative to sitting).                                                                                     |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | Recover from a sitting state to a balanced standing position.                                                        |

| **Function Name**   | **SpeedLevel**                                                                                                       |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t SpeedLevel(int level)`                                                                                      |
| **Function Overview**| Set speed level.                                                                                                    |
| **Parameters**      | **level:** Speed level enumeration value, -1 for slow, 0 for normal, and 1 for fast.                                  |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           |                                                                                                                      |

| **Function Name**   | **Hello**                                                                                                            |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t Hello()`                                                                                                     |
| **Function Overview**| Greet.                                                                                                               |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           |                                                                                                                      |

| **Function Name**   | **Stretch**                                                                                                          |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t Stretch()`                                                                                                    |
| **Function Overview**| Stretch.                                                                                                             |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           |                                                                                                                      |

| **Function Name**   | **SwitchJoystick**                                                                                                   |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t SwitchJoystick(bool flag)`                                                                                   |
| **Function Overview**| Enable or disable the native joystick response.                                                                     |
| **Parameters**      | **flag:** Set to true to enable the native joystick response, and false to disable it.                               |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | After disabling the joystick response, moving the joystick will not interfere with the current program's operation. |

| **Function Name**   | **Content**                                                                                                          |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t Content()`                                                                                                   |
| **Function Overview**| Express happiness.                                                                                                   |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           |                                                                                                                      |

| **Function Name**   | **Heart**                            |
|--------------------|-------------------------------------|
| **Prototype**      | `int32_t Heart()`                     |
| **Function Overview**| Make a heart shape with paws.       |
| **Parameters**     | None                                |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          |                                     |

| **Function Name**   | **Pose**                                   |
|--------------------|--------------------------------------------|
| **Prototype**      | `int32_t Pose(bool flag)`                  |
| **Function Overview**| Strike a pose.                            |
| **Parameters**     | **flag:** Set to `true` to strike a pose, `false` to return to normal stance. |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          |                                           |

| **Function Name**   | **Scrape**                            |
|--------------------|---------------------------------------|
| **Prototype**      | `int32_t Scrape()`                     |
| **Function Overview**| Bow as a greeting.                    |
| **Parameters**     | None                                  |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          |                                       |

| **Function Name**   | **FrontFlip**                         |
|--------------------|---------------------------------------|
| **Prototype**      | `int32_t FrontFlip()`                  |
| **Function Overview**| Perform a front flip.                |
| **Parameters**     | None                                  |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | This action is potentially dangerous. Please maintain a safe distance from others before execution to ensure personal safety. Note that Unitree Technology will not be liable for any accidents caused by improper operation. Additionally, this action may accelerate hardware damage and reduce its lifespan. Use with caution. |

| **Function Name**   | **FrontJump**                         |
|--------------------|---------------------------------------|
| **Prototype**      | `int32_t FrontJump()`                  |
| **Function Overview**| Perform a front jump.                |
| **Parameters**     | None                                  |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          |                                       |

| **Function Name**   | **FrontPounce**                       |
|--------------------|---------------------------------------|
| **Prototype**      | `int32_t FrontPounce()`                |
| **Function Overview**| Lunge forward.                       |
| **Parameters**     | None                                  |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          |                                       |

| Function Name | Dance1                               |
|---------------|--------------------------------------|
| Function Prototype     | `int32_t Dance1()`           |
| Overview      | Dance Sequence 1          |
| Parameters    | None.                                |
| Return Value  | Returns 0 on success, otherwise returns the relevant error code. |
| Remarks       |  |

| **Function Name**   | **FreeBound**                                           |
| ------------ | ------------------------------------------------------------ |
| **Function Prototype** | `int32_t FreeBound(bool flag)`                            |
| **Overview** | Bound Run Mode.                                                   |
| **Parameters**     | flag: Set to true to enter bound run; set to false to exit bound run and enter agile mode.                     |
| **Return Value**   | Returns 0 on success, otherwise returns the relevant error code.                        |
| **Remarks**     | Enters bound run mode. Bound gait.|
| **Function Name**   | **FreeJump**                                           |
| ------------ | ------------------------------------------------------------ |
| **Function Prototype** | `int32_t FreeJump(bool flag)`                         |
| **Overview** | Jump Mode.                                                   |
| **Parameters**     | flag: Set to true to enter jump mode; set to false to exit jump mode and enter agile mode.                     |
| **Return Value**   | Returns 0 on success, otherwise returns the relevant error code.                        |
| **Remarks**     | Enters jump mode. Jump-running gait.|

| **Function Name**   | **FreeAvoid**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t FreeAvoid(bool flag)`                            |
| **Function Overview**| Enter avoidance mode.                                    |
| **Parameters**     | **flag:** Set to `true` to enter avoidance mode, `false` to exit and enter agile mode. |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | In this mode, the robot can avoid obstacles while moving; when stationary, it can dodge objects in front of it. |

| **Function Name**   | **WalkUpright**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t WalkUpright(bool flag)`                           |
| **Function Overview**| Enter rear-leg standing mode.                              |
| **Parameters**     | **flag:** Set to `true` to enter rear-leg standing mode, `false` to exit and enter agile mode. |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | Entering rear-leg standing mode.<BR> The motors in this gait are prone to overheating, so please manage your business logic to avoid robot falls due to motor overheating. |

| **Function Name**   | **CrossStep**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t CrossStep(bool flag)`                          |
| **Function Overview**| Enter cross-step mode.                                  |
| **Parameters**     | **flag:** Set to `true` to enter cross-step mode, `false` to exit and enter agile mode. |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | Entering cross-step mode.<BR> The motors in this gait are prone to overheating, so please manage your business logic to avoid robot falls due to motor overheating. |

| **Function Name**   | **AutoRecoverSet**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t AutoRecoverSet(bool flag)`                          |
| **Function Overview**| Enable or disable auto-recovery.                            |
| **Parameters**     | **flag:** Set to `true` to enable auto-recovery, `false` to disable it. |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | When the device has a payload, it is recommended to disable this setting. If the device falls and flips violently, it may damage the payload, such as the gimbal, camera, and other sensors installed on the robot's head. To avoid this, please make sure to disable this setting. |

| **Function Name**   | **AutoRecoverGet**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t AutoRecoverGet(bool& flag)`                         |
| **Function Overview**| Check if auto-recovery is enabled.                          |
| **Parameters**     | None.                     |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. `flag` is `true` if auto-recovery is enabled, `false` if disabled. |
| **Notes**          | |

| **Function Name**   | **ClassicWalk**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t ClassicWalk(bool flag)`                           |
| **Function Overview**| Enter classic gait mode.                                  |
| **Parameters**     | **flag:** Set to `true` to enter classic gait mode, `false` to exit and enter agile mode. |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | AI-classic gait, with strong adaptability to complex terrain, supports climbing stairs, gravel, meadows, and slippery surfaces. The walking posture is stable and elegant. |

| **Function Name**   | **TrotRun**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t TrotRun()`                                      |
| **Function Overview**| Enter regular running mode.                              |
| **Parameters**     | None.                     |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | Running gait, with a maximum speed of 3.7m/s. This gait is somewhat risky due to its high speed, so please operate with caution. It does not have the ability to handle complex terrain, so it is prone to falling on uneven ground. |

| **Function Name**   | **StaticWalk**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t StaticWalk()`                                    |
| **Function Overview**| Enter regular walking mode.                              |
| **Parameters**     | None.                     |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | The default gait of the original regular mode, this gait does not have the ability to handle complex terrain, but the walking posture is elegant. |

| **Function Name**   | **EconomicGait**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t EconomicGait()`                                   |
| **Function Overview**| Enter regular endurance mode.                              |
| **Parameters**     | None.                     |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | The robot's height is higher in this mode, and the rate of power consumption is slower, which can extend the usage time. A single long-endurance battery can last up to 4 hours on a full charge. |

| **Function Name**   | **SwitchAvoidMode**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t SwitchAvoidMode()`                                  |
| **Function Overview**| In avoidance mode, disable obstacle avoidance in front when the joystick is not pushed, as well as obstacle avoidance behind. |
| **Parameters**     | None.                     |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | It is generally not recommended to use this mode. If you need to use it, please understand the function overview. |

The interface error codes are as follows:
| **Error Code** | **Description**     |
|---------------|---------------------|
| 4101          | Trajectory point count error, returned by the client. |
| 4201          | Action timeout error, the specified action was not completed within the expected time. |
| 4205          | State machine not initialized. |
| 4206          | Robot posture is not suitable for performing waving or bowing actions, so they are not executed. |
| 3104          | DDS timeout. |

## Example

Below is an example of controlling the robot dog to achieve posture control while standing.

```c++

#include <cmath>
#include <signal.h>
#include <unistd.h>

#include <unitree/robot/go2/sport/sport_client.hpp>

bool stopped = false;

void sigint_handler(int sig)
{
  if (sig == SIGINT)
  {
    stopped = true;
  }
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
  // argv[1] is the network interface name passed from the terminal

  // Create a sport_client object
  unitree::robot::go2::SportClient sport_client;
  sport_client.SetTimeout(10.0f); // Set timeout
  sport_client.Init(); // Initialize sport client

  double t = 0; // Program running time
  double dt = 0.01; // Control step size

  // Create a signal object to capture the program exit signal
  signal(SIGINT, sigint_handler);

  while (1)
  {
    t += dt;
    // Posture tracking a trigonometric function trajectory
    sport_client.Euler(0.2 * sin(2 * t), 0.2 * cos(2 * t) - 0.2, 0.);
    sport_client.BalanceStand();
    usleep(int(dt * 1000000));
    if(stopped)
    {
      break;
    }

  }
  // Reset posture when the program exits
  sport_client.Euler(0, 0, 0);
  return 0;
}

```

# High-Level Status Interface

## Calling Method of the High-Level Status Interface

By subscribing to the "rt/sportmodestate" topic, you can obtain the robot's position, speed, posture, and other motion states.

```C++

#include <unitree/idl/go2/SportModeState_.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>

// High-level status topic, where rt indicates real-time and lf indicates low frequency
#define TOPIC_HIGHSTATE "rt/sportmodestate"

using namespace unitree::robot;

// Callback function to obtain motion status
void HighStateHandler(const void* message)
{
  unitree_go::msg::dds_::SportModeState_ state = *(unitree_go::msg::dds_::SportModeState_*)message;

  // Print the robot's position
  std::cout<<"position: "
           <<state.position()[0]<<", "
           <<state.position()[1]<<", "
           <<state.position()[2]<<std::endl;
  // Print the robot's posture quaternion (w,x,y,z)
  std::cout<<": "
           <<state.imu_state().quaternion()[0]<<", "
           <<state.imu_state().quaternion()[1]<<", "
           <<state.imu_state().quaternion()[2]<<", "
           <<state.imu_state().quaternion()[3]<<std::endl;
}

int main()
{
  // Initialize the SDK interface
  std::string networkInterface = "enp2s0"; // Network interface name connected to the robot
  unitree::robot::ChannelFactory::Instance()->Init(0, networkInterface);

  // Create a Subscriber
  ChannelSubscriber<unitree_go::msg::dds_::SportModeState_> suber(TOPIC_HIGHSTATE);

  // Initialize Channel
  suber.InitChannel(HighStateHandler);

  while(1)
  {
    usleep(20000);
  }

  return 0;
}

```

## Introduction to High-Level Status Types

The method to obtain the high-level status is as follows:

```c++
TimeSpec stamp(); 
uint32_t error_code(); // Current mode (since there are many modes, this member variable is used to feedback information)
IMU imu_state(); // IMU status
std::array<float, 3> position(); // 3D position
float body_height(); // Body height
std::array<float, 3> velocity(); // 3D velocity
float yaw_speed(); // Yaw speed
```

The method to obtain the IMU data is as follows:

```C++

std::array<float, 4> quaternion();     // Quaternion (w,x,y,z)
std::array<float, 3> gyroscope();      // Angular velocity (unit: rad/s)
std::array<float, 3> accelerometer();  // Acceleration m/(s^2)
std::array<float, 3> rpy();            // Euler angles (unit: rad)
int8_t temperature(); // Temperature
```

In the "rt/sportmodestate" topic, the motion state machine corresponding to the `error_code` field is shown in the table below.

<table style="width: 100%;">
  <tr style="background-color: #f0f0f0;">
    <th style="width: 50%;">error_code</th>
    <th style="width: 50%;">State Machine Name</th>
  </tr>
  <tr>
    <td>100</td> <td>Agile</td></td>
  </tr>
  <tr>
    <td>1001</td> <td>Damping</td>
  </tr>
  <tr>
    <td>1002</td> <td>Standing Lock</td>
  </tr>
  <tr>
    <td>1004/2006</td> <td>Crouch</td>
  </tr>
  <tr>
    <td>1006</td> <td>Greeting/Stretching/Dancing/Bowing/Heart Shape/Happy</td>
  </tr>
  <tr>
    <td>1007</td> <td>Sit</td>
  </tr>
  <tr>
    <td>1008</td> <td>Front Jump</td>
  </tr>
  <tr>
    <td>1009</td> <td>Lunge</td>
  </tr>
  <tr>
    <td>1013</td> <td>Balance Standing</td>
  </tr>
  <tr>
    <td>1015</td> <td>Regular Walking</td>
  </tr>
  <tr>
    <td>1016</td> <td>Regular Running</td>
  </tr>
  <tr>
    <td>1017</td> <td>Regular Endurance</td>
  </tr>
  <tr>
    <td>1091</td> <td>Strike a Pose</td>
  </tr>
  <tr>
    <td>2007</td> <td>Dodge</td>
  </tr>
  <tr>
    <td>2008</td> <td>Bound Run</td>
  </tr>
  <tr>
    <td>2009</td> <td>Jump Run</td>
  </tr>
  <tr>
    <td>2010</td> <td>Classic</td>
  </tr>
  <tr>
    <td>2011</td> <td>Handstand</td>
  </tr>
  <tr>
    <td>2012</td> <td>Front Flip</td>
  </tr>
  <tr>
    <td>2013</td> <td>Back Flip</td>
  </tr>
  <tr>
    <td>2014</td> <td>Left Flip</td>
  </tr>
  <tr>
    <td>2016</td> <td>Cross Step</td>
  </tr>
  <tr>
    <td>2017</td> <td>Upright</td>
  </tr>
  <tr>
    <td>2019</td> <td>Towing</td>
  </tr>
</table>
