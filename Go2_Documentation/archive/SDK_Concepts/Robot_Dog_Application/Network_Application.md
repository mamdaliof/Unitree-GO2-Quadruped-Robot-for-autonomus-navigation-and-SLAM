# Network Application

This chapter will introduce the design concept of Go2 network connections (**Wi-Fi STA**, **Wi-Fi AP**, and **4G**) and how users can apply the network.

# Network Introduction

Go2 supports three network connections: **Wi-Fi STA**, **Wi-Fi AP**, and **4G**. Among them, **Wi-Fi STA** and **Wi-Fi AP** are open for user settings.

- **Wi-Fi STA**: Go2 connects to a **Wi-Fi** hotspot in the environment, achieving external network access capability.

- **Wi-Fi AP**: Go2 comes with a built-in hotspot, which is a built-in local area network that supports mobile phone and other device connections.

- **4G**: Go2's built-in 4G IoT network card is connected to the operator's base station to achieve external network access capability.

!!! note Note:

To reduce traffic consumption, priority should be given to using Wi-Fi STA channels when both Wi-Fi STA and 4G are enabled. When Wi-Fi STA is turned off or unable to access the external network, the 4G channel is automatically enabled. When using 4G channels, some restrictions are placed on accessing domain names to prevent traffic consumption.

!!!

The 4G network connection is automatically controlled by Go2 based on the principle of high priority WIFI and reduced traffic consumption, without the need for users to manually enable it. Users can view the card information and traffic consumption of the current 4G IoT network card through the Go2 app.

The activation of **Wi-Fi STA** and **Wi-Fi AP** network connections is controlled by the user, and users can interact with Go2 via Bluetooth through the Go2 APP, achieving the following functions:

- Enable **Wi-Fi STA** to connect to a **Wi-Fi** hotspot in the environment.

- Enable **Wi-Fi AP**, modify the built-in hotspot of Go2, namely **Wi-Fi** name and **Wi-Fi** password.

!!! note  Note:
 
After Go2 restarts, if the user has not configured **Wi-Fi STA** and **Wi-Fi AP**, then the existing **Wi-Fi STA** or **Wi-Fi AP** and their corresponding configuration parameters will be enabled, depending on the user configuration before shutting down. If the user sets a **Wi-Fi STA** network connection before shutting down, Go2 will try to connect to a **Wi-Fi** hotspot in the environment based on the user's configuration information after restarting. If the user sets a **Wi-Fi AP** network connection before shutting down, Go2 will radiate the AP outward according to the user's configuration information after restarting.

!!!

Operate the Go2 APP (see the application functions in the next section for specific steps). After establishing a Bluetooth connection between Go2 and the APP, the user enters network settings information, and the APP sends relevant instructions for network settings to Go2. Go2 will respond to the instructions, enable **Wi-Fi STA** or **Wi-Fi AP** network connection, and provide feedback on the execution status of the instructions to the APP. The following figure shows the schematic diagram of the interaction between Go2 and the APP network configuration.

!!! note Note:

Only one **Wi-Fi STA** and **Wi-Fi AP** channel will be enabled for Go2. If the user sets **Wi-Fi STA**, the **Wi-Fi AP** will be turned off, and Go2 will try to connect to a **Wi-Fi** hotspot in the environment according to the user's configuration information. If the user has set the **Wi-Fi AP**, the **Wi-Fi STA** will be turned off, and Go2 will radiate the AP outward according to the user's configuration information.

!!!

![image](https://doc-cdn.unitree.com/static/2023/10/23/1bc0a68c81854ac3a80511270c26b340_8001x4501.png)
<center>Schematic diagram of Go2 and APP network configuration interaction</center>

# Application functions

This section mainly includes viewing **4G** IoT network card information, configuring **Wi-Fi AP** and **Wi-Fi STA**.

## View 4G IoT network card information

Click on Settings on the homepage.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/7dae56065c514822b66c41703921516b.PNG)

</center>

Click on Mobile Network.

<center>

![1](https://doc-cdn.unitree.com/static/2023/8/8/d4ce10259cf0409a8da1f97885b00e0e_876x392.png)

</center>

## Configure Wi-Fi AP

### Unbound machine dog

To configure the **Wi-Fi AP** without binding the machine dog, perform the following steps.

Add a machine dog device and click on Connect Machine Dog.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/edb80a34d0744e088cb037f701930059.PNG)

</center>

Attempt to bind the machine dog.

<center>
  

  ![1](https://doc-cdn.unitree.com/static/2023/10/23/d3dc183fe8564640be6f7dd0f803896c.PNG)

  
  </center>

Select AP router mode.

<center>

 ![1](https://doc-cdn.unitree.com/static/2023/10/23/27b7a7d776404c058c47908727a5058a.PNG)

</center>

Set the hotspot name and password.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/c18c0141b4364c1f8cfd902fc6089427.PNG)

</center>

Connect your phone to the hot spot of the dog and return to the app.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/3a544c1356cd433e9e9e69ed0569b6c1_1792x828.png)

</center>

### Machine dog bound

If the machine dog is already bound, the following steps can be performed to configure Wi-Fi AP.

Click on Settings on the homepage.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/1f44b4218bec4a5e8d6d9547033c53ba.PNG)

</center>

Click on Robot Settings.

<center>

![1](https://doc-cdn.unitree.com/static/2023/8/8/46326f67a9db42e1b54e4d7a51ee849f_876x392.png)</center>

Select AP router mode.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/65558f78488d4389b226416e1167e7fa.PNG)

</center>

Set the hotspot name and password.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/b2ea8854dbda4be3af2548be4e9cf2c0.PNG)
</center>

## Configure Wi-Fi STA

### Unbound machine dog

To configure **Wi-Fi STA** without binding the machine dog, follow the steps below.

Add a robotic dog device.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/e7d0ca3f33f2443689b32414932427d2.PNG)

</center>

Attempt to bind the machine dog.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/bfd38034dd5242d2b2df13e273331ff0.PNG)

</center>

Select Wi-Fi connection mode.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/7db855929e224889b6e6a3a6ea3688e2.PNG)

</center>

Enter the Wi-Fi name and password.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/6902529f72564f23a9c2a3ca49d11700.PNG)

</center>

### Machine dog bound

If the machine dog is already bound, to configure**Wi-Fi STA**, the following steps can be performed.

Click on Settings.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/3cf1db0911644e5f8161b0f2d1ad31f3.PNG)

</center>

Click on Robot Settings.

<center>

![1](https://doc-cdn.unitree.com/static/2023/8/8/43275da4b0df4a41829de23f7cc5af6e_876x392.png)

</center>

Select Wi-Fi connection mode.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/dacb8c9a6f824e9ab5663f8449ce50c0.PNG)

</center>

Enter the Wi-Fi name and password.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/6902529f72564f23a9c2a3ca49d11700.PNG)

</center>
