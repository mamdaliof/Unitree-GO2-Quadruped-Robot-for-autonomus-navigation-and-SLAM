# Creating Customer Application

This document will guide users on how to create their own high-level application routine program using the **unitree\_sdk2**.

By utilizing the **sport\_client** class of `unitree_sdk2`, users can create various high-level applications. This section will provide a step-by-step tutorial on using `sport_client` to create a high-level application that **"makes the Go2 robot, which is lying on its back with its four legs in the air, flip over to stand up, adjust its body height, and then walk forward for a certain distance."**

## Reviewing the sport\_client Interface

`sport_client` is a high-level interface class encapsulated by `unitree_sdk2`. By calling the methods of this class, high-level interfaces can be invoked to control the Go2 robot to perform specified actions.

This class is located at `unitree_sdk2/include/unitree/robot/go2/sport/sport_client.hpp`, as shown below:

```c++
#ifndef __UT_ROBOT_GO2_SPORT_CLIENT_HPP__
#define __UT_ROBOT_GO2_SPORT_CLIENT_HPP__

#include <unitree/robot/client/client.hpp>

namespace unitree
{
namespace robot
{
namespace go2
{
/*
 * PathPoint
 */
struct stPathPoint
{
  float timeFromStart;
  float x;
  float y;
  float yaw;
  float vx;
  float vy;
  float vyaw;
};

typedef struct stPathPoint PathPoint;

/*
 * SportClient
 */
class SportClient : public Client
{
public:
  explicit SportClient(bool enableLease = false);
  ~SportClient();

  void Init();

  int32_t Damp();
  int32_t BalanceStand();
  int32_t StopMove();
  int32_t StandUp();
  int32_t StandDown();
  int32_t RecoveryStand();
  int32_t Euler(float roll, float pitch, float yaw);
  int32_t Move(float vx, float vy, float vyaw);
  int32_t Sit();
  int32_t RiseSit();
  int32_t SpeedLevel(int level);
  int32_t Hello();
  int32_t Stretch();
  int32_t SwitchJoystick(bool flag);
  int32_t Content();
  int32_t Heart();
  int32_t Pose(bool flag);
  int32_t Scrape();
  int32_t FrontFlip();
  int32_t FrontJump();
  int32_t FrontPounce();
  int32_t Dance1();
  int32_t Dance2();
  int32_t LeftFlip();
  int32_t BackFlip();
  int32_t HandStand(bool flag);
  int32_t FreeWalk();
  int32_t FreeBound(bool flag);
  int32_t FreeJump(bool flag);
  int32_t FreeAvoid(bool flag);
  int32_t ClassicWalk(bool flag);
  int32_t WalkUpright(bool flag);
  int32_t CrossStep(bool flag);
  int32_t AutoRecoverSet(bool flag);
  int32_t AutoRecoverGet(bool& flag);
  int32_t StaticWalk();
  int32_t TrotRun();
  int32_t EconomicGait();
  int32_t SwitchAvoidMode();

};
}
}
}

#endif//__UT_ROBOT_GO2_SPORT_CLIENT_HPP__
```

> **For a detailed introduction to the motion interfaces, please refer to the chapter [High-Level Sport Service Interface](https://support.unitree.com/home/en/developer/sports_services)**

## Creating the Application File

Next, let's create the application file in the `example` folder of `unitree_go2_sdk` for better management.

> **The following narration assumes the working path is /home/unitree/**

Enter the following commands sequentially. This sequence of commands will create a folder named `user` under the `example` folder of `unitree_go2_sdk`, where users can manage the application code and files. Then, it will create a file named `app_height.cpp`. The user will write the application logic mentioned earlier in this file.

```c++
cd /home/unitree/unitree_go2_sdk/example
mkdir user
cd user
touch app_height.cpp
```

Next, let's edit `app_height.cpp`.

1.  **Include Header Files:**

```c++
#include <unitree/robot/client/client.hpp>
#include "robot/go2/sport/sport_client.hpp"
```

2.  **Initialize DDS Interface and Create High-Level Interface Object**

```c++
unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
 //argv[1] is the network interface name connected to the robot dog, passed from the terminal
unitree::robot::go2::SportClient sport_client;
sport_client.SetTimeout(10.0f);//Timeout duration
sport_client.Init();
sport_client.WaitLeaseApplied();
```

3.  **Call Functions to Implement Application Logic**

```c++
sport_client.RecoveryStand(); //Recovery stand-up
sleep(3);
sport_client.Sit(); //Sit down
sleep(3);
sport_client.RiseSit(); //Recover from sitting position
sleep(1);
sport_client.Move(0.2,0,0); //Set the desired velocity in the X direction to control the Go2 robot to walk forward for a certain distance
sleep(2); //Walk forward for 2 seconds
```

**The complete code is:**

```c++
#include <unitree/robot/client/client.hpp>
#include <unitree/robot/go2/sport/sport_client.hpp>

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }
  //Initialize interface
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
  
  //Instantiate sport_client and initialize
  unitree::robot::go2::SportClient sport_client;
  sport_client.SetTimeout(10.0f);//Timeout duration
  sport_client.Init();
  sport_client.WaitLeaseApplied();
  int moveTime = 3; // move 3 second
  auto startTime = std::chrono::steady_clock::now();
  while(true)
  { 
    
    sport_client.RecoveryStand(); //Recovery stand-up
    sleep(3);
    sport_client.Sit(); //Sit down
    sleep(3);
    sport_client.RiseSit(); //Recover from sitting position
    sleep(1);
    sport_client.Move(0.2,0,0); //Set the desired velocity in the X direction to control the Go2 robot to walk forward for a certain distance
    sleep(2); //Walk forward for 2 seconds
    
    // Get current time point
    auto currentTime = std::chrono::steady_clock::now();
    // Calculate elapsed time
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
    // Exit loop if elapsed time is greater than or equal to 3 seconds (Note: The variable is moveTime=3, not 2 as in the comment above)
    if (elapsedTime.count() >= moveTime) 
    {
        break;
    }
  }
  
    sleep(2); 
    return 0;
}
```

## Compiling the Application File

After completing the application logic, the next step is to compile the application file.

Add the compilation commands at the very bottom of the `unitree_go2_sdk/CMakeLists.txt` file to include the routine you just wrote and generate the corresponding executable file, then save the file.

```c++
    add_executable(app example/user/app_height.cpp)
target_link_libraries(app unitree_sdk2)
    
```

Finally, compile the routine. You can refer to the routine compilation section in the [Quick Start (快速开始)](https://support.unitree.com/home/zh/developer/Quick_start) chapter for compilation methods.

```c++
cd /home/unitree/unitree_go2_sdk
mkdir build
cd build
cmake ..
make
```

## Running the Application

Open a terminal and execute the following commands sequentially to run the application:

```c++
cd /home/unitree/unitree_go2_sdk/build
sudo ./app_height
```

\!\!\! note Note
This application forwards the control commands to the Go2 robot via the main motion control service. Therefore, ensure that the main motion control service is running normally before running this application. For details, please refer to the Quick Start and App Binding chapters.
\!\!\!

## More Applications

This is for posture control while the robot is in a standing state. Users can refer to the above process to try it themselves.

```c++
#include <unitree/robot/client/client.hpp>
#include <unitree/robot/go2/sport/sport_client.hpp>
#include <unistd.h>
#include <cmath>

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }
  //Initialize interface
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
  
  //Instantiate sport_client and initialize
  unitree::robot::go2::SportClient sport_client;
  sport_client.SetTimeout(10.0f);//Timeout duration
  sport_client.Init();
  sport_client.WaitLeaseApplied();
  double t=0;
  double dt=0.01;
  {
    t+=dt;
    sport_client.Euler(0.4*sin(2*t), 0.4*cos(2*t)-0.4, 0.); 
    sport_client.BalanceStand();
    usleep(int(dt*1000000));
  }
  return 0;
}
```
