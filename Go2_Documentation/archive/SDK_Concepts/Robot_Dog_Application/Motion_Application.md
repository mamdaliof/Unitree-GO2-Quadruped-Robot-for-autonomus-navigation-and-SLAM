# Motion Application

# Robot Coordinate System

The coordinate system of a robot is defined as X facing forward, Y facing left, and Z facing up. The default ground clearance for standing robots is 0.33m, the distance between the left front foot and the center of the body is [x: 0.19257, y: 0.135], and the leg lift height for walking is 0.09m.

 

![](https://doc-cdn.unitree.com/static/2023/9/5/7ba474139e0e46878156aebf948a1bdb_8000x4500.jpg " Coordinate System Definition ")

   
![](https://doc-cdn.unitree.com/static/2023/9/5/46cc9394c1dc45e4b41d6c9f9de8aeae_8000x4500.jpg " Default standing state ")

                                                                      

# Robot Status

![](https://doc-cdn.unitree.com/static/2023/10/16/92c7ff0ab69f460c9ac788dd1dc2ca61_8000x4500.png)

**Robot state switching mechanism**

## Introduction to robot status

The motion of a robot includes damping, standing locking, balanced standing, basic motion, special actions, and protective state states. During operation, the robot switches between different states through a state machine to achieve different control tasks. The explanations for each state are as follows:

|Robot status | Description | Schematic diagram|
| :---: | :--- | :---: |
|Damping state | All joint motors immediately stop moving and enter damping mode.  |  ![](https://doc-cdn.unitree.com/static/2023/8/31/e179c2e36b3f4094aa771a7c77788849_640x360.gif) |
|Standing locked state | The robot remains standing while keeping the motor locked.  | ![](https://doc-cdn.unitree.com/static/2023/8/31/5ac38327816149d89720abf3de8a1957_640x360.gif)
 |
|Balanced Standing State | The robot remains standing in place. Compared to the standing locked state, in this state, the robot will adapt to changes in terrain and maintain a constant posture and body height.  | ![](https://doc-cdn.unitree.com/static/2023/8/31/1ff4657d37fe40f088c5c90b033e3b77_640x360.gif)
 |
|Basic motion state | The robot executes the given motion commands according to the given gait, such as speed tracking, trajectory tracking, etc. The walking state provides multiple optional gaits and supports speed control and trajectory tracking control modes.  |![](https://doc-cdn.unitree.com/static/2023/8/31/8bf0df1ca5cc45c48429a60d75b8c4cd_640x360.gif)
 |
|Special Action Status | The robot executes a given special action command, such as forward jump, forward somersault, etc!  | ![](https://doc-cdn.unitree.com/static/2023/8/31/bc517f60f77a4fdcbe4feee47a3448e9_640x360.gif)
 |
|Protected state | The robot may experience an irresistible strong impact that may cause its posture to flip and enter a protected state. This state can be automatically restored to standing state by calling the interface.  | ![](https://doc-cdn.unitree.com/static/2023/8/31/216c06f3947a49acb88c81a7112cf6ed_640x360.gif)
 |

## Switching mechanism of robot state

The switching mechanism of each state of the robot is shown in Figure 2.1, and the specific switching process of each state is explained below:

* **Damping**: Switching the damping state has the highest priority, and all states can immediately switch to the damping state, equivalent to a soft emergency stop system.

* **Standing lock**: Standing lock is the state of connecting damping and balanced standing. The robot dog needs to enter the balanced standing state from the damping state before calling the corresponding motion service to achieve robot control.

* **Balanced Standing**: In a balanced standing state, various interfaces of the SDK can be called to achieve robot motion control.

* **Protection state**: When the robot recognizes a strong impact and determines that it cannot perform normal motion actions, it will enter the protection state. The SDK provides an interface for restoring from packet state to damping or standing state.

* **Basic Motion**: During the motion execution process, the SDK interface can be called to put the robot into a damped or balanced standing state to terminate the current motion service.

* **Special Action**: When entering the special action execution state, other motion control services will be suspended first, waiting for the current action to complete and enter the balanced standing state before taking effect.

# Robot high-level motion control

The high-level motion control interface services of robots can be divided into basic motion control and special motion control. In basic motion control services, corresponding interfaces can be called to achieve different movements of robots such as posture and body height control, speed control, trajectory tracking control, and obstacle avoidance. At the same time, interfaces can be called to switch the walking gait of robots according to different terrain scenarios and task requirements. In the special action control service, the corresponding interface can be called to implement the built-in special actions of the robot, such as sitting, jumping forward, and flipping forward. The high-level motion control interface supported by the robot is shown in the following figure.

![](https://doc-cdn.unitree.com/static/2023/10/16/be9bce9970634d30af7bb222a1f323b0_8000x4500.png " Robot high-level motion control interface diagram ")

## Basic motion control

### Sports mode

|Motion control mode | Description | Schematic diagram|
| :---: | :--- | :---: |
|  Attitude and body height control | In standing and walking modes, the body maintains the given posture and height  |![](https://doc-cdn.unitree.com/static/2023/8/31/65a5f65a8c6c49ba883c08d3a791259e_640x360.gif)
 |
|  Speed control | The robot travels at a given speed  |  ![](https://doc-cdn.unitree.com/static/2023/8/31/9685cd39c9634828aaa461613230d783_640x360.gif)
 |
|Trajectory tracking control | The robot follows a given trajectory |    |
|Obstacle avoidance | The robot travels at a given speed while avoiding obstacles around it |       |

### Gait

|Robot gait | Description | Schematic diagram|
| :---: | :--- | :---: |
|  trot gait  |  trotgait is the most efficient gait among quadruped robots  | ![](https://doc-cdn.unitree.com/static/2023/8/31/027192a494f64638a5de8c6400560bef_640x360.gif)
 |
|  trot running Gait  |  This gait has a higher stride and frequency than a normal trot gait, and has a higher walking speed | ![](https://doc-cdn.unitree.com/static/2023/8/31/b625b98f1a03413ea25e37586f82db92_640x360.gif)
 |
|  climbing mode |  This gait can adapt to more complex terrain and achieve functions such as climbing buildings and climbing obstacles  |   |

## Special Actions

Sports services provide a variety of built-in actions that can be arranged as needed. The following are the built-in special actions and related descriptions.

|Special Action | Action Execution Process | Schematic Diagram|
| :---: | :---: | :---: |
|  sit down  | ![](https://doc-cdn.unitree.com/static/2023/10/16/1f987e4291c8465ba3d1c37d03e8ee7f_596x339.png) |  ![](https://doc-cdn.unitree.com/static/2023/8/31/b253c11e31e8436e9545a3337eea188b_640x360.gif)    |
|  Recovery from sitting down movements  |
|  Stretch out  | ![](https://doc-cdn.unitree.com/static/2023/10/16/1305f5f4cb3e44caba625ceb092a7f00_557x321.png) | ![](https://doc-cdn.unitree.com/static/2023/8/31/016b836cc3bf41fbbec7ca52fe4e659c_640x360.gif) |
|  Roll around  | ![](https://doc-cdn.unitree.com/static/2023/10/16/4d8d05ad67824f2ba89496bf1489d922_557x321.png) | ![](https://doc-cdn.unitree.com/static/2023/8/31/df90a2aeb7ca4cebaa9b70cb76a05e2a_640x360.gif) |
|  Happy  | ![](https://doc-cdn.unitree.com/static/2023/10/16/e182a947266b4e3b8aa9781f7a4b90b4_557x321.png) | ![](https://doc-cdn.unitree.com/static/2023/8/31/f4b37ed34d7a4720a3db6d653613d671_640x360.gif)
 |
|  Dance  | ![](https://doc-cdn.unitree.com/static/2023/10/16/61c31e858c084b62ba1dcebc053abf62_557x321.png) |![](https://doc-cdn.unitree.com/static/2023/8/31/93130a44dcad484f964310eff29283f9_640x360.gif)
 |
| Greeting the New Year with a bow  |![](https://doc-cdn.unitree.com/static/2023/10/16/d78e5553eff14421acd4d20d8c06f514_557x321.png) | ![](https://doc-cdn.unitree.com/static/2023/8/31/584cda13e04e474a9afb07963d33a8ec_640x360.gif)
 |
| Forward somersault  | ![](https://doc-cdn.unitree.com/static/2023/10/16/b917d299b7fe476f8e116de909135d71_557x321.png) |   |
|  Jump forward  | ![](https://doc-cdn.unitree.com/static/2023/10/16/ba26b87858cb4b7ba85ff28c015fe765_557x321.png) | ![](https://doc-cdn.unitree.com/static/2023/8/31/2ed0caa577024c3d934010075e28d1f6_640x360.gif)
 |
|  Move forward!  | ![](https://doc-cdn.unitree.com/static/2023/10/16/8da3b57d28154847811eb218a3473c6b_914x294.png)
 |   |
