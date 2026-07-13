# Quick Start

This article introduces how to develop for the Go2 robot using the unitree\_sdk2.

## Environment Dependencies

### System Environment

It is recommended to develop on **Ubuntu 20.04** or **Ubuntu 22.04**. Development on Mac or Windows systems is currently not supported, nor is development on Go2's internal computer.

### Network Environment

The network adapter on the user's computer that communicates with the Go2 robot must be set to the **123 subnet**. The IP address for this adapter is recommended to be set to **192.168.123.222** ("222" can be changed to something else). It is **not allowed** to set this adapter's IP address to 192.168.123.161, as this is the IP address of the Go2 robot's built-in computer.

### Dependency Installation

The following dependencies need to be installed:

```bash
sudo apt install cmake
sudo apt install gcc
sudo apt install build-essential
sudo apt install libeigen3-dev
```

## Installation and Compilation

> **The following description assumes the working directory is the user's home directory.**

### Installing unitree\_sdk2

Download the [ unitree\_sdk2](https://github.com/unitreerobotics/unitree_sdk2) compressed package and extract it to the user's home directory. Open a terminal and execute the following commands sequentially to install unitree\_sdk2:

```c++
cd ~/unitree_sdk2/
mkdir build
cd build
cmake ..
sudo make install
```

Or, install to a specified directory:

```c++
cd ~/unitree_sdk2/
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/opt/unitree_robotics
sudo make install
```

!!! note Attention
In the above command, CMAKE\_INSTALL\_PREFIX is used to specify that unitree\_sdk2 should be installed in the `/opt/unitree_robotics` directory. If you want to install unitree\_sdk2 in a different directory, modify this path accordingly.
!!!

### Example Compilation

Open a terminal and execute the following commands sequentially to compile the examples:

```c++
cd ~/unitree_sdk2
mkdir build
cd build
cmake ..
make
```

If the `make` command finishes with 100% progress and no errors, it means the compilation was successful.

<center>

</center>

If the `make` command is executed successfully, the generated examples will be located in the `build/bin` directory. The files shown in green characters in the image below are the binary files corresponding to the successfully compiled examples.

<center>

</center>

!!! note Attention
Due to continuous updates to unitree\_sdk2, the executable files shown in the image above may differ from the latest version.
!!!

### Network Configuration

When running examples, control commands will be sent from the user's computer to the Go2 robot's built-in computer via the local area network. Therefore, it is necessary to perform a few essential configuration steps to form a local network between the two computers.

Configuration Steps:

1.  Connect one end of a network cable to the Go2 robot and the other end to the user's computer. Enable and configure the computer's **USB Ethernet**. The IP address of the robot's onboard computer is **192.168.123.161**, so the computer's USB Ethernet address needs to be set to the same subnet as the robot, for example, by entering **192.168.123.222** ("222" can be changed to something else) in the Address field.

<center>
    

</center>

      To test whether the user's computer and the Go2 robot's built-in computer are connected properly, you can enter `ping 192.168.123.161` in the terminal. The connection is successful if output similar to the image below appears.

2.  Check the network card name corresponding to the 123 subnet
       Use the `ifconfig` command to view the network card name for the 123 subnet, as shown below:

<center>
   

</center>

As shown in the image above, the network card name corresponding to the IP **192.168.123.222** is `enxf8e43b808e06`. Users need to remember this name, as it will be a necessary parameter when running the examples.

## Running Examples

After successful compilation, the `unitree_sdk2/build/bin` folder will contain the binary files corresponding to examples like `low_level`, `high_level`, and `wireless`. These examples can generally be divided into high-level control examples and low-level control examples. For details, please refer to the section on **[Example Reference](https://support.unitree.com/home/zh/developer/Basic_motion_control)**. The following section uses the `low_level` example as an illustration. This is a low-level control example that controls the Go2 robot's front right leg to swing rhythmically.

### Disabling Motion Control Service

Before running this example, you must first disable Go2's main motion control service (MCF). This can be done in **App -\> Device -\> Service Status** by clicking to disable the corresponding service. Alternatively, you can disable the motion control service by calling the service status switch interface. For information on this method, refer to the [ go2\_stand\_example ](https://www.google.com/search?q=https://github.com/unitreerobotics/unitree_sdk2/blob/main/example/go2/go2_stand_example.cpp) example in `unitree_sdk2`, which demonstrates how to disable the motion control service by calling the [ Motion Switcher Service Interface](https://support.unitree.com/home/zh/developer/Motion%20Switcher%20Service%20Interface).

!!! note Attention
The main motion control service must be disabled because the low-level control example also acts as a motion control service. Both send control commands to Go2. If multiple motion controls are active simultaneously, the Go2 robot will receive two or more control commands, leading to confusion and potential loss of control. Therefore, before running a low-level control program, ensure the corresponding service is disabled.
!!!

Motion Control Service Names:
| Service Name | Corresponding Version |
| --- | --- |
| mcf | Go2 Main Motion Control Service (Software Version \> 1.1.6) |
| sport\_mode | Go2 Main Motion Control Service (Software Version \< 1.1.6)|
| wheeled\_sport | Go2 W Main Motion Control Service |

### Running the Example

Open a terminal and execute the following commands sequentially to run the example.

```c++
cd ~/unitree_sdk2/build/bin
./go2_low_level [Network Interface]
```

`[Network Interface]` is the name of the network adapter you use to link the robot, such as `enxf8e43b808e06`. You can use the `ifconfig` command to view the network card name. Be sure to select the network card name with the IP address previously set to 192.168.123.222.

!!! note Attention
This example will cause the Go2 robot's legs to swing. To protect the robot, you should ensure all four legs are suspended off the ground before running this example.
!!!

### Example Running Result Preview

At this point, the robot's front right lower leg will swing rhythmically.

## More Examples

The `go2_stand_example` example can control the quadruped robot to transition from a resting (crawling) state to a standing state, and then return to the resting state after a period of standing. This example also uses the [ Motion Switcher Service Interface](https://support.unitree.com/home/zh/developer/Motion%20Switcher%20Service%20Interface) to disable Go2's main motion control service. Therefore, users do not need to manually disable Go2's main motion control service (`sport_mode`/`mcf`) via the App before running this example.

### Running the Example

Open a terminal and execute the following commands sequentially to run the example.

```c++
cd ~/unitree_sdk2/build/bin
./go2_stand_example [Network Interface]
```

!!! note Attention
Before running the `go2_stand_example` example, the Go2 robot should be stationary and resting on the ground.
!!!
