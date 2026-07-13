# UWB Services Interface

The UWB module consists of a UWB base station and UWB tags. It adopts ultra wideband positioning method and can provide the pose information of the tags in the base station. We will convert the collected UWB data into idl format and publish it through DDS. If you need to use UWB data for secondary development, you can obtain it by subscribing to the corresponding DDS topic. The specific usage steps are as follows, and a simple case is attached for reference.
# Interface Description

![](https://doc-cdn.unitree.com/static/2023/10/12/d246a79283a24ea2a4b3d89788ba1ce2_8856x4501.png)

Users can obtain UWB data by subscribing to the DDS topic “**rt/uwbstate**”  in the format of **UwbState\_.idl**.

```C++

// generated from rosidl_generator_dds_idl/resource/idl.idl.em
// with input from unitree_go:msg/UwbState.idl
// generated code does not contain a copyright notice

#ifndef __unitree_go__msg__uwb_state__idl__
#define __unitree_go__msg__uwb_state__idl__

module unitree_go {

module msg {

module dds_ {

struct UwbState_ {
octet version[2];         // Version number (array: 0-hardware, 1-software)

octet channel;            // Signal channel
octet joy_mode;           // Mode (0-joystick control, 1-walk tracking, 2-run tracking, 3-stand up, 4-lie down, 5-damping, 6-roll, 7-trigger motion, 8-stand)

float orientation_est;    // The azimuth of the label in the base station coordinate system
float pitch_est;          // The elevation angle of the label in the base station coordinate system
float distance_est;       // Distance between tag and base station

float yaw_est;            // The yaw angle corresponding to the label orientation in the base station coordinate system

float tag_roll;           // Roll angle of label
float tag_pitch;          // The pitch angle of the label
float tag_yaw;            // Yaw angle of the label

float base_roll;          // Roll angle of the fuselage
float base_pitch;         // The pitch angle of the fuselage
float base_yaw;           // Yaw angle of the fuselage

float joystick[2];        // Rocker value, ranging from -1.00 to 1.00. Joystick [0] is x, and joystick [1] is y. The x-axis is facing upwards and the y-axis is facing left.

octet error_state;        // Error status code
octet buttons;            // Key mode
octet enabled_from_app;   // Does the App turn on tracking (0 is off, 1 is tracking)

};
};  // module dds_
};  // module msg
};  // module unitree_go

#endif  // __unitree_go__msg__uwb_state__idl__
```    
The data available for user secondary development in **UwbState\_.idl** mainly includes the position and orientation of the tag in the base station coordinate system, tag IMU, body IMU, and joystick value. The remaining data is used for displaying the status of the **Unitree Go App** developed by Yushu.

     
* The position and orientation of the label in the base station: The position is in spherical coordinates

* **orientation\_est**: The azimuth angle of the label in the base station coordinate system, in rad, as shown in the schematic diagram β。

* **distance\_est**: The elevation angle of the label in the base station coordinate system, in rad, as shown in the schematic diagram α。

* **distance\_est**: The distance between the label and the base station, in meters, as shown in the diagram.

* **yaw\_est**: The yaw angle corresponding to the label orientation in the base station coordinate system, in rad, as shown in the diagram γ.

![](https://doc-cdn.unitree.com/static/2023/8/8/bb4cc7c94014420eac610157169167d7_8001x4501.jpeg)

*   Label IMU
    
    *   **tag\_roll**：Tag roll angle, in rad.
        
    *   **tag\_pitch**：Tag pitch angle, in rad.
        
    *   **tag\_yaw**：Tag yaw angle, in rad.
        
*   Body IMU
    
    *   **base\_roll**：Body roll angle, in rad.
        
    *   **base\_pitch**：The elevation angle of the fuselage, in rad.
        
    *   **base\_yaw**：Airframe yaw angle, in rad.
        
*   Rocker value
    
    *   **joystick**\[2\]: Accompanying the two axis joystick values of the remote control, the range is -1.00~1.00. **joystick**\[0\] is the x-axis value, and upward is positive; joystick\[1\] is the y-axis value, with a positive value to the left.

<center>
        
![](https://doc-cdn.unitree.com/static/2023/8/8/c1348daeb1424d34ba16b8a43dc8b57c_146x268.png)

</center>

*   The remaining parts are intended for use by Yushu **Unitree Go App** and have special meanings that you do not need to care about.
    
    *   **version**\[2\]: version number, **version**\[0 \] is the hardware version, **version**\[1\] is the software version.
        
    *   **channel**：Signal channel
        
    *   **joy\_mode**：Robot motion mode
        
    *   **error\_state**：Error status code
        
    *   **buttons**：Button mode
        
    *   **enabled\_from\_app**：Does the App open accompanying
        

# Cases

A simple example of subscribing to "**rt/uwbstate**" to obtain UWB data is as follows. This case needs to be used after the DDS related environment configuration is completed. If not clear, please install unitree_sdk2 first.Use "./subscribe_uwb_state eno1" to run it, where "eno1" is your network interface in local.

```C++
/**
 * @file subscribe_uwb_state.cpp
 * @brief Subscribe the uwb state published from DDS topic
 * @date 2025-01-02
 */
#include "iostream"
#include <unitree/idl/go2/UwbState_.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>

#define TOPIC_UWBSTATE "rt/uwbstate"

using namespace unitree::robot;

void HighStateHandler(const void* message)
{
    unitree_go::msg::dds_::UwbState_ uwbstate_ = *(unitree_go::msg::dds_::UwbState_*)message;

    std::cout << "orientation_est:" << uwbstate_.orientation_est() << std::endl;
    std::cout << "pitch_est:" << uwbstate_.pitch_est() << std::endl;
    std::cout << "distance_est:" << uwbstate_.distance_est() << std::endl;
    std::cout << "yaw_est:" << uwbstate_.yaw_est() << std::endl;

    std::cout << "tag_roll:" << uwbstate_.tag_roll() << std::endl;
    std::cout << "tag_pitch:" << uwbstate_.tag_pitch() << std::endl;
    std::cout << "tag_yaw:" << uwbstate_.tag_yaw() << std::endl;

    std::cout << "base_roll:" << uwbstate_.base_roll() << std::endl;
    std::cout << "base_pitch:" << uwbstate_.base_pitch() << std::endl;
    std::cout << "base_yaw:" << uwbstate_.base_yaw() << std::endl;

    std::cout << std::endl;
}

int main(int argc, char **argv)
{

  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);

  //创建一个Subscriber
  ChannelSubscriber<unitree_go::msg::dds_::UwbState_> suber(TOPIC_UWBSTATE);

  //初始化Channel
  suber.InitChannel(HighStateHandler);

  while(1)
  {
    usleep(20000);
  }

  return 0;
}
 ```   

**The CMakeLists.txt configuration is as follows**

```C++
project(example)
cmake_minimum_required(VERSION 3.16)

include_directories(/usr/local/include/ddscxx /usr/local/include/iceoryx/v2.0.2)

link_libraries(unitree_sdk2 ddsc ddscxx rt pthread)

add_executable(subscribe_uwb_state subscribe_uwb_state.cpp)
```
**Print Results**
```C
orientation_est:1.45361
pitch_est:0.612117
distance_est:2.2581
yaw_est:1.74529
tag_roll:-1.57486
tag_pitch:0.00332104
tag_yaw:-1.33394
base_roll:-0.00436199
base_pitch:-0.0273653
base_yaw:0.0620915
```
# Other

In addition to “**rt/uwbstate**”, there are also DDS topics related to UWB, such as "rt/api/uwbswitch", which is used to disable and enable Go2 companion functions for use by the **Unitree Go App**.
