# Light Control

This article will introduce how to use unitree_go2_sdk to control the LED emitting from the head of the GO2 robot dog

The SDK currently provides two methods for setting / obtaining **white** lights, and developers can customize the brightness of LEDs according to different scene requirements. Adjust the gear to between 0 and 10.
<center>
  

<img src="https://doc-cdn.unitree.com/static/2023/10/18/9c463ad1fe7540b1ba3855ed3514b4ba_5364x4986.png" width =500>
  
</center>

## Routine code

Path: `unitree_sdk2/example/go2/go2_vui_client.cpp`

The routine achieves the effect of controlling the light's off ->dark ->on ->off in a loop.

```C++
#include <unitree/robot/go2/vui/vui_client.hpp>

int main(int32_t argc, const char** argv)
{
    if (argc < 2)
    {
        std::cout << "Please fill in the correct network card name" << std::endl;
        exit(0);
    }
    /*
     * Initilaize ChannelFactory
     */
    std::string networkInterface = "eth0";
    networkInterface = argv[1];
    unitree::robot::ChannelFactory::Instance()->Init(0, networkInterface);
    unitree::robot::go2::VuiClient vc;

    /*
     * Set request timeout 1.0s
     */
    vc.SetTimeout(1.0f);
    vc.Init();

    //Test Api

    int level = 0, value = 0;
    int ret;

    while (true)
    {
        ret = vc.SetBrightness(level);
        std::cout << "SetBrightness  level=" << level << ", api return:" << ret << std::endl;
        ++level %= 11;
        sleep(1);
        ret = vc.GetBrightness(value);
        std::cout << "GetBrightness value=" << value << ", api return:" << ret << std::endl;
        sleep(1);
    }

    return 0;
}
```

## Introduction to relevant interfaces

|Function Name | SetBrightness|
|:-------- | :--------|
|**Function Prototype**| int32_t SetBrightness(int level); |
|**Parameter**| level: Brightness range 0-10|
|**Return Value**| If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
|**Remarks**| Set brightness|

|Function Name | GetBrightness|
|:-------- | :--------|
|**Function Prototype**| int32_t GetBrightness(int&);|
|**Parameter**| Integer reference parameter|
|**Return Value**| If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
|**Remarks**| Obtain the current brightness|
