# FAULTS

# Fault

The engineers of Go2 have put in a lot of effort in the design and manufacturing process, but they still inevitably encounter some unexpected problems in practical use. When problems occur, operators, developers, and other devices will be notified through fault alarms.

There are different types and sources of faults. The current fault information can be obtained through the APP or SDK.

**System malfunction**

A system malfunction indicates a hardware or software malfunction in the robot. They include fault source code and fault code, and can be notified to users through apps or SDKs, and recorded by cloud services in online mode. Resolving these faults requires a solution based on the specific fault code.

**Behavioral malfunction**

A behavioral fault indicates that the robot is unable to execute a certain instruction. This usually indicates that the current operating conditions of the robot do not allow the execution of the command or that the robot is currently in an occupied state.

**Application failure**

App failure, such as the dog not being bound, unable to connect, or network abnormality.

**Fault recovery**

Normal warning faults and other warning conditions will automatically disappear after they disappear.

Special faults such as motor protection, motherboard disconnection, etc. require a restart of the dog to recover.

<center>

![](https://doc-cdn.unitree.com/static/2023/11/17/2afe89c56a3c4c4ebc72c87ac1a9b7fd_2400x1080.jpg)

![](https://doc-cdn.unitree.com/static/2023/11/17/d4fb9302ae6b46039e564076849c67f1_2400x1080.jpg)

</center>
