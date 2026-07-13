# Python Services Interface

# unitree_sdk2_python
unitree_sdk2 python interface

# Installation
## Dependencies
- python>=3.8
- cyclonedds==0.10.2
- numpy
- opencv-python

## Installing unitree_sdk2_python
Execute the following in the terminal:
```bash
cd ~
sudo apt install python3-pip
git clone [https://github.com/unitreerobotics/unitree_sdk2_python.git](https://github.com/unitreerobotics/unitree_sdk2_python.git)
cd unitree_sdk2_python
pip3 install -e .
````

## FAQ

##### 1\. Error when running `pip3 install -e .`

```bash
Could not locate cyclonedds. Try to set CYCLONEDDS_HOME or CMAKE_PREFIX_PATH
```

This error indicates that the cyclonedds path cannot be found. First, compile and install cyclonedds:

```bash
cd ~
git clone [https://github.com/eclipse-cyclonedds/cyclonedds](https://github.com/eclipse-cyclonedds/cyclonedds) -b releases/0.10.x 
cd cyclonedds && mkdir build install && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=../install -DBUILD_DDSPERF=OFF
cmake --build . --target install
```

Navigate to the `unitree_sdk2_python` directory, set `CYCLONEDDS_HOME` to the path where you just compiled cyclonedds, and then install `unitree_sdk2_python`:

```bash
cd ~/unitree_sdk2_python
export CYCLONEDDS_HOME="/{path to your cyclonedds}/cyclonedds/install"
pip3 install -e .
```

For details, see:
[https://pypi.org/project/cyclonedds/\#installing-with-pre-built-binaries](https://pypi.org/project/cyclonedds/#installing-with-pre-built-binaries)

# Usage

The python sdk2 interface remains consistent with the unitree\_sdk2 interface, achieving robot status acquisition and control through request-response or publish-subscribe topics. Corresponding examples are located in the `/example` directory. Before running the examples, you need to configure the robot's network connection according to the document [《Quick Start》](https://support.unitree.com/home/zh/developer/Quick_start).

## DDS Communication

Execute the following in the terminal:

```bash
python3 ./example/helloworld/publisher.py
```

Open a new terminal and execute:

```bash
python3 ./example/helloworld/subscriber.py
```

You should see the data information output in the terminal. The data transmitted by `publisher.py` and `subscriber.py` is defined in `user_data.py`. Users can define the data structures they need to transmit as required.

## High-Level State and Control

The data structures and control methods for the high-level interface are consistent with unitree\_sdk2. For details, see: [https://support.unitree.com/home/zh/developer/sports\_services](https://support.unitree.com/home/zh/developer/sports_services)

### High-Level Control

Execute the following in the terminal:

```bash
python3 ./example/go2/high_level/go2_sport_client.py [network_interface_name]
```

Where `[network_interface_name]` is the name of the network card connected to the robot. Please modify it according to the actual situation. Format examples: `enp2o`, `exp889dsxspod21`
This example provides several test methods; select one by inputting the sequence number to execute:

```python
TestOption(name="damp", id=0),        
TestOption(name="stand_up", id=1),    
TestOption(name="stand_down", id=2),  
TestOption(name="move forward", id=3),        
TestOption(name="move lateral", id=4),    
TestOption(name="move rotate", id=5),  
TestOption(name="stop_move", id=6),  
TestOption(name="switch_gait", id=7),    
TestOption(name="switch_gait", id=8),
TestOption(name="balanced stand", id=9),      
TestOption(name="recovery", id=10),
TestOption(name="recovery", id=10),      
TestOption(name="left flip", id=11),      
TestOption(name="back flip", id=12),
TestOption(name="free walk", id=13),  
TestOption(name="free bound", id=14),
TestOption(name="free avoid", id=15),  
TestOption(name="walk stair", id=16),
TestOption(name="walk upright", id=17),
TestOption(name="cross step", id=18),
TestOption(name="free jump", id=19)  
```

## Low-Level State and Control

The data structures and control methods for the low-level interface are consistent with unitree\_sdk2. For details, see: [https://support.unitree.com/home/zh/developer/Basic\_services](https://support.unitree.com/home/zh/developer/Basic_services)

### Low-Level Motor Control

First, use the app to turn off the high-level motion service (`sport_mode`), otherwise, it will cause command conflicts.
Execute the following in the terminal:

```bash
python3 ./example/go2/low_level/go2_stand_example.py [network_interface_name]
```

The rear-left thigh (hip) joint will be held at 0 degrees (for safety, $k_p=10$ and $k_d=1$ are set here), and the rear-left calf joint will continuously output $1 \text{ Nm}$ of torque.

## Wireless Controller Status Acquisition

Execute the following in the terminal:

```bash
python3 ./example/wireless_controller/wireless_controller.py [network_interface_name]
```

The terminal will output the status of each button. For the definition and data structure of the controller buttons, see: [https://support.unitree.com/home/zh/developer/Get\_remote\_control\_status](https://support.unitree.com/home/zh/developer/Get_remote_control_status)

## Front Camera

Use OpenCV to acquire the front camera (ensure the system has a graphical interface; press ESC to exit the program):

```bash
python3 ./example/go2/front_camera/camera_opencv.py [network_interface_name]
```

## Obstacle Avoidance Switch

```bash
python3 ./example/obstacles_avoid_switch/obstacles_avoid_switch.py [network_interface_name]
```

The robot will loop through enabling and disabling the obstacle avoidance function. For details on the obstacle avoidance service, see [https://support.unitree.com/home/zh/developer/ObstaclesAvoidClient](https://support.unitree.com/home/zh/developer/ObstaclesAvoidClient)

## Light and Volume Control

```bash
python3 ./example/vui_client/vui_client_example.py [network_interface_name]
```

The robot will cycle through adjusting the volume and light brightness. For details on this interface, see [https://support.unitree.com/home/zh/developer/VuiClient](https://support.unitree.com/home/zh/developer/VuiClient)
