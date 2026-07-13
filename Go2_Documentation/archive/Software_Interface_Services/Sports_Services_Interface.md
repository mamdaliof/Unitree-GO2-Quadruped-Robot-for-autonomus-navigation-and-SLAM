# Sports Services Interface

!!! note **Scope of Application**

This document interface description is applicable to the **Go2 Edu model**, requiring the Go2 software version to be less than V1.1.6.

- If your software version is greater than or equal to V1.1.6, please refer to [Motion Services Interface V2.0](https://support.unitree.com/home/en/developer/Motion_Services_Interface_V2.0).
- For any other questions, feel free to [contact our official technical support](https://global-serviceconsole.unitree.com/#/login?redirect=/work-order).

Thank you for your support!

!!!

# High level control interface
By calling the SDK's sport_ Client, to send motion commands such as speed control and trajectory tracking to Go2w.
## The calling method of high-level control interface

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
//argv[1] is network interface of the robot
  
  //Create a sports client object
  unitree::robot::go2::SportClient sport_client;
  sport_client.SetTimeout(10.0f);//Timeout time
  sport_client.Init();

  sport_client.StandUp(); //Special action, robot dog sitting down
  sleep(3);//delay 3s
  sport_client.StandDown(); //Restore
  sleep(3);

  return 0;
}

```

## Introduction to high-level motion control interface

The high-level control interface can achieve control of Go2's posture, speed, and trajectory tracking, flipping, jumping, and handstand. The relevant functions of the motion control interface are listed below.

| **Function Name** | **Damp**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Damp()| 
| **Function Overview** |  Enter damping state| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  All motor joints stop moving and enter a damping state. This mode has the highest priority and is used for emergency stops in unexpected situations| 

| **Function Name** | **BalanceStand**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t BalanceStand()| 
| **Function Overview** |  Unlock| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Unlock the joint motor and switch from normal standing mode to balanced standing mode. In this mode, the attitude and height of the fuselage will always remain balanced, independent of the terrain. You can control the font of the body by calling the Euler() interface (see the corresponding section of the table for details)|  

| **Function Name** | **StopMove**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t StopMove()| 
| **Function Overview** |  Stop the current action and restore the majority of commands to their default values| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Stop the current motion and restore the internal motion parameters of Go2 to the default values| 

| **Function Name** | **StandUp**  |    
| :-- |  :--|  
| **Function Prototype** |  int32_t StandUp()| 
| **Function Overview** |  Joint locking, standing high| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  The machine dog is standing tall normally, and the motor joint remains locked. Compared to the balanced standing mode, the posture of the robotic dog in this mode will not always maintain balance. The default standing height is 0.33m| 

| **Function Name** | **StandDown**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t StandDown()| 
| **Function Overview** |  Joint locking, standing low| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  The robotic dog lies down and the motor joint remains locked| 

| **Function Name** | **RecoveryStand**| 
| :-- |  :--|  
| **Function Prototype** |  int32_t RecoveryStand()| 
| **Function Overview** |  Restore Standing| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Restore from a overturned or lying state to a balanced standing state. Whether it is overturned or not, it will return to standing| 

| **Function Name** | **Euler**| 
| :-- |  :--|  
| **Function Prototype** |  int32_t Euler(float roll, float pitch, float yaw)| 
| **Function Overview** |  Posture when standing and walking| 
| **Parameter** | **Roll:** Value range [-0.75~0.75 ] (rad) **Pitch:** Value range [-0.75~0.75 ] (rad) **Yaw:** Value range [-0.6~0.6 ] (rad)| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Set the body posture angle for Go2 balance when standing or moving. The Euler angle is represented by the rotation order around the relative axis of the body and z-y-x| 

| **Function Name** | **Move**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Move(float vx, float vy, float vyaw)| 
| **Function Overview** |  Mobile| 
| **Parameter** | **vx:** Value range [-2.5~3.8 ] (m/s) **vy:** Value range [-1.0~1.0 ] (m/s) **vyaw:** Value range [-4~4 ] (rad/s)| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Control movement speed. The set speed is the speed represented by the body coordinate system| 

| **Function Name** | **Sit**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Sit()| 
| **Function Overview** |  Sit down.  |                                                                             | **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Special action, robot dog sitting down. It should be noted that special actions need to be executed after the previous action is completed, otherwise it may result in abnormal actions| 

| **Function Name** | **RiseSit**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t RiseSit()| 
| **Function Overview** |  Stand up (relative to sitting down)| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Restore from sitting to balanced standing| 

| **Function Name** | **SwitchGait**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t SwitchGait (int d)| 
| **Function Overview** |  Switch gait| 
| **Parameter** | **d:** Gait enumeration value, with values ranging from 0 to 4, where 0 is idle, 1 is trot, 2 is trot running, 3 is forward climbing mode, and 4 is reverse climbing mode| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  The forward climbing mode is for the robot to face the stairs, while the reverse climbing mode is for the robot to face the stairs with its back| 

| **Function Name** | **BodyHeight**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t BodyHeight (float height)| 
| **Function Overview** |  Set the relative height of the body above the ground when standing and walking.  |                                                                                          
| **Parameter** | **Height:** Relative value to the default fuselage height, value [-0.18~0.03 ] (m)| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Adjust the height of the body relative to the default state when standing or walking in balance. The default body height for Go2 is 0.33. For example, BodyHeight (-0.1) indicates adjusting the body height to 0.33-0.1=0.23 (m)| 

| **Function Name** | **FootRaiseHeight**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t FootRaiseHeight (float height)| 
| **Function Overview** |  Set the relative height of foot lift during movement| 
| **Parameter** | **Height:** Relative value to the default foot lift height, value [-0.06~0.03 ] (m)| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Note** |  Set the leg lift height relative to the default state during Go2 movement, with Go2 default foot lift height of 0.09. For example, FootRaiseHeight (0.01) indicates setting the leg lift height to 0.09+0.01=0.1 (m)| 

| **Function Name** | **SpeedLevel**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t SpeedLevel (int level)| 
| **Function Overview** |  Set the speed range| 
| **Parameter** | **level**: Speed range enumeration value, with values of -1 for slow speed, 0 for normal speed, and 1 for fast speed| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **Hello**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Hello()| 
| **Function Overview** |  Say hello| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **Stretch**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Stretch()| 
| **Function Overview** |  Stretch| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **TrajectoryFollow** | 
| :-- |  :--| 
| **Function Prototype** |  int32_trajectoryFollow (std:: vector<PathPoint>path)| 
| **Function Overview** |  Track Tracking. | 
| **Parameter** |  path is the target motion trajectory of the robotic dog in the future, It consists of 30 trajectory points, PathPoints| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Note** |  The structure definition of the trajectory point (PathPoint) in the path is as follows:![](https://doc-cdn.unitree.com/static/2023/10/18/cac6508a993845eea0e4b7125f9009ad_530x273.png)Each trajectory point contains the position and speed of the robotic dog at a certain time in the future, with the reference coordinate system being the absolute coordinate system of the robot. Through trajectory tracking, more complex and flexible movements can be achieved. For specific usage methods, please refer to examples| 

| **Function Name** | **SwitchJoystick**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Switch Joystick (bool flag)| 
| **Function Overview** |  Native remote control response switch| 
| **Parameter** |  flag: Set true to respond to the native remote control, and false to not respond to the remote control| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  After turning off the remote control response, the remote control commands will not interfere with the current program operation| 

| **Function Name** | **ContinuousGait**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Continuously Gait (bool flag)| 
| **Function Overview** |  Continuous movement| 
| **Parameter** |  flag: Set true to on and false to off| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Note** |  After starting a continuous gait, the robot dog will continue to maintain a gait state, even if the current speed is 0| 

| **Function Name** | **Wallow**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Wallow()| 
| **Function Overview** |  Rolling| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **Pose**| 
| :-- |  :--|  
| **Function Prototype** |  int32_t Pose (bool flag)| 
| **Function Overview** |  Pose| 
| **Parameter** |  flag: Set true to pose and false to restore| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **Scrape**| 
| :-- |  :--|  
| **Function Prototype** |  int32_t Scrape()| 
| **Function Overview** |  Greeting the New Year| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **FrontFlip**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t FrontFlip()| 
| **Function Overview** |  Front flip| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **FrontJump**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t FrontJump()| 
| **Function Overview** |  Jump Forward| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **FrontPounce**| 
| :-- |  :--|  
| **Function Prototype** |  int32_t FrontPounce()| 
| **Function Overview** |  Move Forward| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **Dance1**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Dance1()| 
| **Function Overview** |  Dance Paragraph 1| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **Dance2**| 
| :-- |  :--|  
| **Function Prototype** |  int32_t Dance2()| 
| **Function Overview** |  Dance Paragraph 2| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **GetState**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t GetState (const std:: vector<std:: string>&_vector, std:: map<std:: string, std:: string>&_map)| 
| **Function Overview** |  Retrieve the current status of the robot, including:<br>state: motion status<br>bodyHeight: body height,<br>footRaiseHeight: leg lift height,<br>speedLevel: speed gear,<br>gait gait,<br>joystick: remote control status,<br>dance: in motion,<br>continuous gait: in continuous gait,<br>economicGait: in power-saving gait| 
| **Parameters** | **_ Vector**: the vector reference of the robot status name**_ Map**: Map reference for the state name and corresponding value.
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Reference example:![]( https://doc-cdn.unitree.com/static/2023/10/11/d603f3b753694f478e6d97d4a548461c_812x422.png )When the robot is in a damping state, the above example will output {"data": "damping"} results| 

The interface error code is as follows:
| Error number |  Error description| 
| :-- |  :--| 
| 4101 |  Wrong number of trajectory points, returned by the client| 
| 4201   | Action timeout error, the specified action was not completed within the expected time
|   
|4205|The state machine has not been initialized|
|4206| If the attitudes of robot are not correct before performing actions such as waving or greeting, the action will not be executed|
| 3104 | DDS timeout|

## example

Here is an example of controlling a robotic dog to achieve posture control while standing.

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
  //argv[1] is network interface of the robot

  //Create a sport_ Client object
  unitree::robot::go2::SportClient sport_client;
  sport_client.SetTimeout(10.0f); //Timeout
  sport_client.Init(); //Initializationsport client

  double t = 0; //Program runtime
  double dt = 0.01; // Control step size

  // Create a signal object to capture the signal for program exit
  signal(SIGINT, sigint_handler);

  while (1)
  {
    t += dt;
    // Attitude tracking a trigonometric function trajectory
    sport_client.Euler(0.2 * sin(2 * t), 0.2 * cos(2 * t) - 0.2, 0.);
    sport_client.BalanceStand();
    usleep(int(dt * 1000000));
    if(stopped)
    {
      break;
    }

  }
  // Reset posture upon program exit
  sport_client.Euler(0, 0, 0);
  return 0;
}

```

# High level state interface

## High level state interface call method

By subscribing to the "rt/portmodestate" topic, you can obtain the position, speed, posture, and other motion states of the robot.

```C++

#include <unitree/idl/go2/SportModeState_.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>

//High level status topic, where rt represents real-time and lf represents low-frequency
#define TOPIC_HIGHSTATE "rt/sportmodestate"

using namespace unitree::robot;

// Callback function for obtaining motion status
void HighStateHandler(const void* message)
{
  unitree_go::msg::dds_::SportModeState_ state = *(unitree_go::msg::dds_::SportModeState_*)message;

  // Print output machine dog position
  std::cout<<"position: "
           <<state.position()[0]<<", "
           <<state.position()[1]<<", "
           <<state.position()[2]<<std::endl;
  // Print out quaternion of robot dog posture (w,x,y,z)
  std::cout<<": "
           <<state.imu_state().quaternion()[0]<<", "
           <<state.imu_state().quaternion()[1]<<", "
           <<state.imu_state().quaternion()[2]<<", "
           <<state.imu_state().quaternion()[3]<<std::endl;
}

int main()
{
  //Initializationsdk Interface
  std::string networkInterface = "enp2s0";// Name of the network card connected by the robot
  unitree::robot::ChannelFactory::Instance()->Init(0, networkInterface);

  // Create a Subscriber
  ChannelSubscriber<unitree_go::msg::dds_::SportModeState_> suber(TOPIC_HIGHSTATE);

  //InitializationChannel
  suber.InitChannel(HighStateHandler);

  while(1)
  {
    usleep(20000);
  }

  return 0;
}

```

## Introduction to Creating High Level State Types

The method to obtain the status of high-level parts is as follows

```c++
TimeSpec stamp(); 
uint32_t errorCode(); // Error
IMU imuState();// IMU status
Uint8_t mode();// Sports mode
/* Sports mode
0. idle, default stand
1. balanceStand
2. pose
3. locomotion
4. reserve
5. lieDown
6. jointLock
7. damping
8. recoveryStand
9. reserve
10. sit
11. frontFlip
12. frontJump
13. frontPounc
*/

float progress(); // Action execution status: 0. dance false; 1. dance true
uint8_t gaitType(); // Gait type
/*
Gait type 
0.idle  
1.trot  
2.run  
3.climb stair  
4.forwardDownStair   
9.adjust
*/

float footRaiseHeight();// Leg lift height
std::array<float, 3> position();// 3D position
float bodyHeight();// Body height
std::array<float, 3> velocity();// Three-dimensional velocity
float yawSpeed();// Yaw speed
std::array<float,4> rangeObstacle();// Obstacle distance
std::array<int16_t,4> footForce();// Four foot force
std::array<float,12> footPositionBody();// The position of the foot end relative to the body
std::array<float,12> footSpeedBody();// The speed of the foot relative to the body
std::array<PathPoint, 10> pathPoints();// The current tracked path point
```

The method for obtaining IMU data is:

```C++

std::array<float, 4> quaternion();    // Quaternion (w, x, y, z)
std::array<float, 3> gyroscope();    // Angular velocity (unit: rad/s)
std::array<float, 3> accelerometer();    // Acceleration m/(s2)
std::array<float, 3> rpy();    // Unit: rad
int8_Temperature ();// temperature

```

The structure of PathPoint is:

```C++

typedef struct
{
  float tFromStart; // Time at which the path point is located
  float x; //x position
  float y; //y position
  float yaw; // Yaw angle
  float vx; //x speed
  float vy; //y speed
  float vyaw; // Yaw speed
} PathPoint;

```
