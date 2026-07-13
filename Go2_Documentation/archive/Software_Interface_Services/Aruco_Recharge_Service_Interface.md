# Aruco Recharge Service Interface

# Go2 Aruco Recharge Service Interface

!!! note Attention:

Only Go2 with NX docking station is supported to use this service. During use, only the front camera of Go2 is called, so it is necessary to ensure that the front camera of Go2 is not obstructed.
  Before recharging, please install the charging board and Aruco maker holder correctly, and when recharging with the Aruco maker correctly, the Go2 should face the Aruco maker as much as possible, and the distance from the Aruco maker should not exceed `1.5m`. Users need to remotely control to the vicinity of the charging pad or use navigation to allow Go2 to navigate to the vicinity of the charging pad, and then call the Aruco maker recharge service. In addition, the camera parameters of each Go2 may be different, which may result in deviations in Aruco maker recognition. Different versions of motion control for Go2 may result in prolonged pose adjustment time during recharging.
!!!

### Aruco Recharge Service Download
[Go2 Download](https://oss-global-cdn.unitree.com/static/d778b298a34647f8bf27d14512896bfd.zip)
[Go2-W Download](https://oss-global-cdn.unitree.com/static/dae7aa244f1a41728fcaf225b4b7cecf.zip)

### 1.Aruco maker printing and installation instructions

​	Download the [Aruco Recharge](https://oss-global-cdn.unitree.com/static/af1fdf42bc334572a0375523d1f4daef.zip) and unzip it, attach a Aruco maker image to the file for self printing and pasting. If you need to replace the Aruco maker with another one, there are the following restrictions: the Aruco maker type only supports `36h11` type, the length of the black part of the printed Aruco maker is` 0.1075m`, and the x positive direction of the printed Aruco maker must face left and the y positive direction must face down, as shown in the picture. 

![](https://doc-cdn.unitree.com/static/2024/9/27/bb5127f5b2da4bb2a6a0b2e5be71798b_200x200.png)

If the length of the black part of the printed Aruco maker is not `0.1075m`, it is necessary to modify the corresponding parameters of `aruco_size` in `aruco_config.yaml` to match the actual measured parameters.

![](https://doc-cdn.unitree.com/static/2024/10/21/8a7543df128e4936953510001f928c59_915x717.png)

Please install the charging pad bracket and paste the Aruco maker according to the following diagram.
![](https://doc-cdn.unitree.com/static/2023/12/27/be13bbf6711841a0b1373019d9c7c072_2424x1303.png)

!!! note Printing precautions: 
 It is best to print with hard matte material to avoid reflection that may cause problems with Aruco maker recognition; And there should be a white edge of about `1cm` around the Aruco maker, and the Aruco maker should be kept flat when pasting.
!!!

### 2. Recharge restriction conditions

When recharging, try to face the Aruco maker with the Go2's head as close as possible, and the distance from the Aruco maker should not exceed `1.5m`. Do not move the Aruco maker during the Go2 movement, and do not place other Aruco makers in the field of view. If you need to use the aruco recharge service at night, you need to supplement the light source separately and do not use the indicator light that comes with the Go2's head.

### 3.Instructions for the operation, interface calling, and status feedback of the recharge service

​	Use command `/aruco_recharge` program with aruco_charge; Open another terminal and use `ros2` to publish the topic of starting recharge. The example is as follows:

`ros2 topic pub /aruco_cmd std_msgs/msg/String "data: 'aruco_start'" -t 1`； DDS can also be used to publish topics in the corresponding format. After release, if a Aruco maker within the field of view is recognized, the recharge service will automatically issue control instructions to move Go2 onto the charging pad.

​	When Go2 successfully lies on the charging pad, it will post the topic`/aruco_state` to the public, with the content being `"aruco_arrive"`. At this time, Go2 will detect the charging status. If it is in the charging state for a certain period of time (about `10 seconds`), it will publish the`/aruco_state` topic to the public, with the content of `"aruco_success"`. At this time, the recharge service will automatically shut down and exit. The topic feedback results are shown in the figure:

![](https://doc-cdn.unitree.com/static/2024/9/27/03a4902b1ce04fceb9291171d27b59f9_283x111.png)

​	If Go2 does not detect that it is in a charging state, it will stand up again to adjust its posture. If the charging status is not detected after lying on the charging pad for three consecutive times, the`/aruco_state` topic will be posted to the public with the content `"aruco_failed"`. At this point, the recharge service automatically shuts down and exits. The topic feedback results are shown in the figure:

![](https://doc-cdn.unitree.com/static/2024/9/27/109a341c3fd9458481c6aa3352074649_230x228.png)

### 4. Additional document description

​	When running the recharge service, several `CSV` format log files will be automatically generated, and deleting them will not affect the operation of the recharge service. It won't take up too much space and can be ignored directly.

### 5.Explanation of failed recharge situations

​	When calling the recharge service, Go2 will automatically detect the charging status. If Go2 is lying behind the charging pad and not in a charging state, it will automatically stand up and readjust its position. Try again up to three times. If it is still not in charging state after three attempts, it is considered a charging failure. At this point, it is necessary to manually shut down or restart the recharge node.

### 6.Explanation of failed operation of recharge service

​	The SDK version that comes with the docking station can directly run the recharge service. If the SDK is upgraded or the location of individual link libraries is changed, it will cause the recharge program to not run properly.
!!! note Attention
If the following error occurs when running the recharge program

![](https://doc-cdn.unitree.com/static/2024/9/27/de56ece73efe4750b9564c4e7be25b24_799x42.png)
!!!

​	This indicates that the version of the Unitree SDK linked by this program is inconsistent with the SDK version in the current system or that the location of the dynamic link library has changed.

​	Enter `ldd aruco_charge` on the terminal to view the link location of the current program's dynamic library.

![](https://doc-cdn.unitree.com/static/2024/9/27/08866062df5c4790bdb601eb2fe201be_1368x691.png)

The two link libraries highlighted by the red box are the cause of this issue.

#### Solution 1

​	Firstly, delete these two soft links. Use the following command

`sudo rm /usr/local/lib/aarch64/libddsc.so.0`

`sudo rm /usr/local/lib/aarch64/libddscxx.so.0`

​	Then, enter `ldd aruco_recharge` on the terminal`

![](https://doc-cdn.unitree.com/static/2024/9/27/4d46fef255c34166939514561a506837_1419x617.png)

​	If the information popped up by the terminal at this time is consistent with the link position circled in the red box, it can run normally. Input/ The aruco_charge interface will appear as follows

![](https://doc-cdn.unitree.com/static/2024/9/27/ad95f330a382462da13f909b07ef53c7_1228x72.png)

At this point, the recharge program can run normally.

#### Solution 2

If method one is completed

```shell
sudo rm /usr/local/lib/aarch64/libddsc.so.0
sudo rm /usr/local/lib/aarch64/libddscxx.so.0
```

​	Afterwards, `ldd aruco_recharge` found that the linked positions of `libddsc.so.0` and `libddscxx.so.0` were different from those in the figure or had broken links. You will need to reinstall Unitree SDK2, which comes with an SDK included in this compressed package and can be installed directly. It is recommended to install to the default location during installation, otherwise linking to dynamic libraries may easily fail.

Precautions for installing SDK

​	If you have previously installed the SDK, you need to delete `libunitree_sdk2. a` from the original installation directory. The default installation location is in the/usr/local/lib directory, and you can use `sudo rm/usr/local/lib/libunitree_sdk2. a`

![](https://doc-cdn.unitree.com/static/2024/9/27/2b181c3b753942bd9bc4006c2c2cc7a6_1410x900.png)

​	After deletion, create a new folder named `build` in unitree_sdk2 and `cd`  into that folder.

![](https://doc-cdn.unitree.com/static/2024/9/27/3e1f9b3a08864a9eb0bdc0e40036d49c_1406x428.png)

​	Execute `cmake ..` (Recommended to install directly to the system default location)

![](https://doc-cdn.unitree.com/static/2024/9/27/11ae14dbf70b43068157b9d7c74df8f9_1290x712.png)

​	After execution, if the terminal prompt message is consistent with the above picture, it can proceed normally downwards.

​	Enter `sudo make install`

​	Just wait for the installation to complete

![](https://doc-cdn.unitree.com/static/2024/9/27/fc4027eb859a417da27aad1a54bd0d0d_1465x803.png)

![](https://doc-cdn.unitree.com/static/2024/9/27/438a6a5546dd4b7a8f5c890f46a51a07_1450x801.png)

​	At this point, return to the directory where the recharge program is located and enter `ldd aruco_charge`

It will appear
![](https://doc-cdn.unitree.com/static/2024/9/27/b055bad5e55f48f184921d7df927e720_1368x691.png)

​	At this point, follow the first step to delete the incorrect soft link

```shell
sudo rm /usr/local/lib/aarch64/libddsc.so.0
sudo rm /usr/local/lib/aarch64/libddscxx.so.0
```

​	Enter `ldd aruco_charge`

![](https://doc-cdn.unitree.com/static/2024/9/27/3c769b156ca94f209ab541b7e1dff6dd_1419x617.png)

You can see the link to the location where the SDK was installed just now. At this point, the recharge program can run `./aruco_recharge` normally, as shown in the figure

![](https://doc-cdn.unitree.com/static/2024/9/27/69c31e2c16fc4b9d974638e2ef4270a7_1284x925.png)
