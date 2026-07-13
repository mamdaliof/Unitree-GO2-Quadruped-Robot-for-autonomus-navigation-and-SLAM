# UWB Application

# Summary

Unitree Go2 UWB is a vector positioning module developed by Yushu Technology, which can achieve centimeter level positioning within the plane of the aircraft body. Built in 3-axis accelerometer and 3-axis gyroscope IMU, providing labeled posture. This module is applied to the accompanying functions of Go2 integration and can also be used for user secondary development.

![](https://doc-cdn.unitree.com/static/2023/8/8/e96a4a4e42dd43d8834fc0394635589b_5000x2813.png)

# Technical Proposal

The UWB module consists of two parts: a tag and a base station, with an integrated antenna, joystick, buttons, etc. on the tag; There are 4 antennas of the same specification arranged on the base station. The base station interacts with the tag antenna through the antenna and analyzes the pose information of the tag.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/24/7405daf5f6c2496cbba4d71432083a35_5244x2329.png)
</center>

# Instructions for use

## Key Description

|**Keys** | **Functions** | **Specific Instructions**|
| :---: | :---: | --- |
|  Power button | Turn on/off power | - Press briefly once to turn it on <BR>  - Press and hold for more than 2 seconds to turn off       |
|  P key | System reset | - Short press twice continuously to cycle between damping, lying down, and standing up modes for the robot  <BR>   - When the robot rolls over, long press for 1 second to restore standing     |
| M key | Companion mode switch | - Short press once to exit Companion mode and enter Rocker mode  <BR>    - Quick short press twice to enter Slow Auto Companion mode with a maximum speed of 1.5m/s   <BR>     -  In Slow Auto Companion mode, short press twice to enter Fast Auto Companion mode with a maximum speed of 3.0m/s    |
|  L1 key | Robot orientation setting |- Short press once to adjust the robot counterclockwise by approximately    <BR>    -  Short press twice to adjust the robot clockwise by approximately 5.7°       |
|  L2 key | Enable/disable automatic obstacle avoidance | - Short press 2 times continuously to activate obstacle avoidance function <BR>    - Short press 1 time to disable obstacle avoidance    |

## Rocker Description

The label joystick belongs to a two axis joystick, and by moving the joystick, the robot can be controlled to move forward and turn. The corresponding relationship between the direction of joystick movement and the direction of robot motion is shown in the following figure.

<center>

![](https://doc-cdn.unitree.com/static/2023/10/24/191b50f44c354e69881463c92952867c_687x529.png)

</center>

## Usage process

After Go2 is powered on and stands up automatically, the accompanying remote control can be used. By default, the companion function is disabled, and functions such as joystick control can be used normally. If you need to use the companion function, please follow the procedure below to switch to companion. The specific process is as follows:

**Wearing and activating companion mode** **[Important steps!!!]**

* With the antenna facing upwards, wear the accompanying remote control on the right side of the waist; The human body is standing on the left side of the robot, with the torso aligned with the robot's orientation

* Quickly press the M key twice to enter slow companion mode

* In slow companion mode, briefly press the M key twice again to enter fast companion mode

**Turn obstacle avoidance on/off**

Press the L2 key twice in a row to activate obstacle avoidance, and briefly press once to deactivate obstacle avoidance

**Exit Companion Mode**

* Short press the M key once

* Move the joystick in any direction

* Shutdown

* Place the remote control horizontally
