# TouchScreen RC Supporting Instructions

The Go2 with a screen remote controller is compatible with accessories like dual cameras, three-in-one systems, dual-camera thermal imaging gimbals, enabling features such as HD image transmission, real-time audio transmission, recording upload, audio playback, text-to-speech, lighting functions (flash/constant/brightness adjustment), red/blue flashing modes, and more. Through voice prompts and red/blue warning lights, it provides safety alerts, promptly notifying users of environmental changes and potential dangers.

# Basic Functions

## Joystick Buttons

![](https://doc-cdn.unitree.com/static/2024/1/10/566ba9b606164945b6daf1c26b03787f_2226x1553.png)

![](https://doc-cdn.unitree.com/static/2024/1/10/bb4a35e407fe4b9dbbb733e3de6b5d2e_2226x705.png)

!!! note **Note**
1. After booting up and standing upright, please turn the right wheel/START to the right to unlock control! Otherwise, the Go2 cannot be operated with the buttons while locked.
2. Remember to reset the three-stage switch after completing the corresponding function to avoid misoperation.
!!!

## Control Modes

The screen remote controller is mapped similarly to the dual-hand controller. If you're familiar with the operation of the dual-hand controller, you can quickly adapt.

Briefly press the power button on the screen remote controller once, then press and hold the power button for **2** seconds or more to turn on the screen remote controller. Once the signal light turns green after booting up, you can use the screen remote controller to control the robot dog.

Command Reference:

<center>

![](https://doc-cdn.unitree.com/static/2025/9/25/432bf8b383f74eef81ce5f1675013acf_1365x1277.png)

</center>

# Compatible Accessories

## Dual Camera/Three-in-One

<center>

![1](https://doc-cdn.unitree.com/static/2024/1/10/72e79b297bdf4ddb9ebfbab65227bf4d_4685x4446.png)      ![1](https://doc-cdn.unitree.com/static/2024/1/10/8c161b8703e2451fb83f3b88724fd616_4686x5156.png)

</center>

### Camera

Run the SIYI FPV app, enter the settings menu, fill in the IP addresses of the front and rear cameras (192.168.144.25/192.168.144.26) in the address settings menu. Settings are preconfigured, open to display camera image transmission.

<center>

![3](https://doc-cdn.unitree.com/static/2024/1/10/ba5fa4e1c87b469f8da96c662accb940_1660x904.png)

</center>

### Voice Broadcasting

Click on the smart load icon on the remote controller's desktop, wait for about **30s**, return to the desktop. When the control icon appears on the desktop, it means the screen remote controller and the three-in-one receiver are successfully connected. You can now click on the desktop icon to control the Go2 three-in-one device.

![](https://doc-cdn.unitree.com/static/2024/1/10/9cffe0b712354d72b7ca9352fe673f13_2006x729.png)

<center>

</center>

The first floating window button can be used for real-time voice broadcasting, playing alarms, and adjusting the volume.
<center>

![3](https://doc-cdn.unitree.com/static/2024/1/10/560e27c4995244b3b375d7391325c86f_1660x904.png)

</center>

The second floating window button allows text-to-speech operations.

<center>

![3](https://doc-cdn.unitree.com/static/2024/1/10/f1557dcb49e145d89844ed55301ef77e_1660x904.png)

</center>

The third floating window button operates the recording function.

<center>

![3](https://doc-cdn.unitree.com/static/2024/1/10/060fdad63aa941d4913aac8c2d62847e_1659x904.png)

</center>

### Red/Blue Flashing Lights

The fourth floating window button controls lighting and red/blue flashing.

<center>

![3](https://doc-cdn.unitree.com/static/2024/1/10/7244cc9647b64c23b2ffa0c8bf98be0d_1660x904.png)

</center>

## Dual-Camera Thermal Imaging Gimbal

<center>

![1](https://doc-cdn.unitree.com/static/2024/1/10/dc00082a2068484c9be512191da801af_4521x5086.png)
</center>

Run the SIYI FPV app (APP version >= 2.5.15.691), enter the settings menu, fill in the IP address of the dual-camera thermal imaging gimbal (192.168.144.29) to display RGB/thermal imaging screens. Use **swiping up/down/left/right on the screen** to operate the gimbal and capture angles.
<center>

![3](https://doc-cdn.unitree.com/static/2024/1/10/20c0fb79ad014e1387b3860af8e1419c_1660x904.png)
</center>

For more gimbal settings, click on the settings button on the top right of the app.

<center>

![3](https://doc-cdn.unitree.com/static/2024/1/10/371aad6a5c4146e39f3ef6661d39c57e_1659x904.png)

</center>

# Troubleshooting

## Abnormal Use of Screen Remote Controller

When powering on, unlock the Go2 by turning the right wheel/START to the right. Otherwise, the Go2 cannot be controlled by the remote commands when locked! 
During screen remote controller usage, do not activate low battery mode! If any abnormalities occur during usage, disable low battery mode.
【System Settings】->【Battery Management】-> Turn off low battery mode.

## Smart Load App Failure to Connect to Go2

After entering the Smart Load App, wait for approximately 30s. If the control floating window does not appear upon returning to the desktop, it means no connection has been established. Please restart the screen remote controller and try connecting again.

## Other Device Connection Issues

Check if other device IPs are conflicting. After changing IPs, attempt to reconnect.

The following IPs are already in use:

| IP Address      | Device Name     |
| :--------------- | :--------------- |
| 192.168.144.11  | Sky End         |
| 192.168.144.12  | Ground End      |
| 192.168.144.20  | Remote Control  |
| 192.168.144.23  | Three-in-One    |
| 192.168.144.25  | Camera 1        |
| 192.168.144.26  | Camera 2        |
| 192.168.144.29  | Dual-Camera Thermal Imaging Gimbal |
