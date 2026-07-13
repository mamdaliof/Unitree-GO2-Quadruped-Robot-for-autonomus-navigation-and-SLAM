# Get Remote Control Status

# Introduction to Remote Control Data Interface

The buttons of each part of the remote control are explained as shown in the figure. The functions of a remote control mainly consist of left and right joystick and function buttons. Each joystick has two degrees of freedom and can output joystick values in the x and y directions, with a range of \[-1.0~1.0\]. The combination of function keys / function keys corresponds to a unique integer key value. Users can obtain the values of the joystick and the key values of the buttons by subscribing to the "rt/wirelesscontroller" message.

<centrt>

![](https://doc-cdn.unitree.com/static/2024/1/8/5a0057f38e464df3a1bdfb806edb1334_1600x819.png)

</centrt>

The source code of the program in the following sections can be found at [unitree_sdk2/example/wireless](https://github.com/unitreerobotics/unitree_sdk2/tree/main/example/wireless) and [unitree_sdk2/example/advanced_gamepad](https://github.com/unitreerobotics/unitree_sdk2/tree/main/example/advanced_gamepad), respectively.

# Remote control data

## Obtain remote control data

The method to obtain remote control data is as follows

```C++
unitree_go::msg::dds_::WirelessController_ joystick; // Remote control data dds

joystick.lx(); // Obtain data for left joystick x, range [-1.0~1.0]
joystick.ly(); // Obtain left joystick y data, range [-1.0~1.0]
joystick.rx(); // Obtain right joystick x data, range [-1.0~1.0]
joystick.ry(); // Obtain right joystick y data, range [-1.0~1.0]
joystick.keys(); // Obtain remote control key values
```

The correspondence between remote control key values and buttons is defined by the following consortium. Assign the obtained key value to the value variable in the union, and then determine whether the corresponding key has been pressed by determining whether the member variable in the components is 1.

```C++
typedef union
{
  struct
  {
    uint8_t R1 : 1;
    uint8_t L1 : 1;
    uint8_t start : 1;
    uint8_t select : 1;
    uint8_t R2 : 1;
    uint8_t L2 : 1;
    uint8_t F1 : 1;
    uint8_t F2 : 1;
    uint8_t A : 1;
    uint8_t B : 1;
    uint8_t X : 1;
    uint8_t Y : 1;
    uint8_t up : 1;
    uint8_t right : 1;
    uint8_t down : 1;
    uint8_t left : 1;
  } components;
  uint16_t value;
} xKeySwitchUnion;

```

For example:

 ```C++
xKeySwitchUnion key;
key.value = joystick.keys(); // Assign the obtained remote control key value to the value variable in the consortium

 // By determining the components A value in the consortium, it can be determined whether the A key has been pressed
if ((int)key.components.A == 1)
{
  std::cout << "The key A is pressed " << std::endl;
}
```

## Complete routine

*   In the main function, a joystick\_dds\_model dds model will be created and subscribed to messages from the "rt/wirelesscontroller" node    
*   When the value of the remote control changes, the program will enter the JoystickHandler() callback function and output the value of the remote control.
    

```C++
#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/idl/go2/WirelessController_.hpp>
#include <unitree/robot/client/client.hpp>

#define TOPIC_JOYSTICK "rt/wirelesscontroller"

using namespace unitree::common;

// Remote Control Key Value Consortium
typedef union
{
  struct
  {
    uint8_t R1 : 1;
    uint8_t L1 : 1;
    uint8_t start : 1;
    uint8_t select : 1;
    uint8_t R2 : 1;
    uint8_t L2 : 1;
    uint8_t F1 : 1;
    uint8_t F2 : 1;
    uint8_t A : 1;
    uint8_t B : 1;
    uint8_t X : 1;
    uint8_t Y : 1;
    uint8_t up : 1;
    uint8_t right : 1;
    uint8_t down : 1;
    uint8_t left : 1;
  } components;
  uint16_t value;
} xKeySwitchUnion;

// Callback function for obtaining motion status
void JoystickHandler(const void *message)
{
  unitree_go::msg::dds_::WirelessController_ joystick = *(unitree_go::msg::dds_::WirelessController_ *)message;
  
  // Remote control raw data
  std::cout << "lx: " << joystick.lx() << std::endl     // left joystick x
            << "ly: " << joystick.ly() << std::endl     // left joystick y
            << "rx: " << joystick.rx() << std::endl     // right joystick x
            << "ry: " << joystick.ry() << std::endl     // right joystick y
            << "keys: " << joystick.keys() << std::endl // key
            << "------" << std::endl;
  xKeySwitchUnion key;
  key.value = joystick.keys();

  // Determine whether a button has been pressed
  if ((int)key.components.A == 1)
  {
    std::cout << "The key A is pressed " << std::endl;
  }
}

int main(int argc, char **argv)
{
    // Initialize SDK interface
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }

  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);

  unitree::robot::ChannelSubscriberPtr<unitree_go::msg::dds_::WirelessController_> joystick_suber;
  joystick_suber.reset(new unitree::robot::ChannelSubscriber<unitree_go::msg::dds_::WirelessController_>(TOPIC_JOYSTICK));
  joystick_suber->InitChannel(JoystickHandler, 1);

  while (1)
  {
    usleep(20000);
  }
  return 0;
}

```
!!! note 
After running the program, there will only be output when the remote control joystick changes or a button is pressed.
!!!

# Remote Control Advanced Packaging

The above routine can only obtain the "pressed"/"released" states of the remote control button, and cannot reflect whether it is currently in the moment of pressing. The rocker data read is the original value, excluding dead zones, filtering, etc. If you want to solve the above problems, you can perform advanced encapsulation on the remote control data.The source code of the program can be found at `unitree_sdk2/example/wireless_controller`.

## Button class

Firstly, define a button state type as follows. Pressed indicates whether the button is currently in a pressed state, n\_press / on\_release indicates whether the button is currently exactly in the pressed or released state.

```C++
    class Button
    {
    public:
        Button() {}

        void update(bool state)
        {
            on_press = state ? state != pressed : false;
            on_release = state ? false : state != pressed;
            pressed = state;
        }

        bool pressed = false;
        bool on_press = false;
        bool on_release = false;
    };
```

## Advanced remote control class

Subsequently, define a new type of remote control and update the status of the remote control buttons and joystick based on the remote control status message.

   ```C++
 // full gamepad
    class Gamepad
    {
    public:
        Gamepad() {}

        void Update(unitree_go::msg::dds_::WirelessController_ &key_msg)
        {
            // update stick values with smooth and deadzone
            lx = lx * (1 - smooth) + (std::fabs(key_msg.lx()) < dead_zone ? 0.0 : key_msg.lx()) * smooth;
            rx = rx * (1 - smooth) + (std::fabs(key_msg.rx()) < dead_zone ? 0.0 : key_msg.rx()) * smooth;
            ry = ry * (1 - smooth) + (std::fabs(key_msg.ry()) < dead_zone ? 0.0 : key_msg.ry()) * smooth;
            ly = ly * (1 - smooth) + (std::fabs(key_msg.ly()) < dead_zone ? 0.0 : key_msg.ly()) * smooth;

            // update button states
            key.value = key_msg.keys();

            R1.update(key.components.R1);
            L1.update(key.components.L1);
            start.update(key.components.start);
            select.update(key.components.select);
            R2.update(key.components.R2);
            L2.update(key.components.L2);
            F1.update(key.components.F1);
            F2.update(key.components.F2);
            A.update(key.components.A);
            B.update(key.components.B);
            X.update(key.components.X);
            Y.update(key.components.Y);
            up.update(key.components.up);
            right.update(key.components.right);
            down.update(key.components.down);
            left.update(key.components.left);
        }

        float smooth = 0.03;
        float dead_zone = 0.01;

        float lx = 0.;
        float rx = 0.;
        float ry = 0.;
        float ly = 0.;

        Button R1;
        Button L1;
        Button start;
        Button select;
        Button R2;
        Button L2;
        Button F1;
        Button F2;
        Button A;
        Button B;
        Button X;
        Button Y;
        Button up;
        Button right;
        Button down;
        Button left;

    private:
        xKeySwitchUnion key;
    };

```

## Business logic implementation

In programming practice, two threads can be used, one thread listens to and stores remote control messages, and the other thread executes at a scheduled time to update remote control status and execute control logic. Taking the calculation of the number of times A key is pressed as an example, the callback functions for two threads are as follows:

    
 ```C++
class GamepadExample
{
public:
    // ...

    // Message listening callback
    void MessageHandler(const void *message)
    {
        std::lock_guard<std::mutex> lock(joystick_mutex);
        joystick_msg = *(unitree_go::msg::dds_::WirelessController_ *)message;
    }

    // Timing control callback
    void Step()
    {
        {
            std::lock_guard<std::mutex> lock(joystick_mutex);
            gamepad.Update(joystick_msg);
        }

        // some operations
        if (gamepad.A.on_press)
        {
            press_count += 1;
        }
    }

    // ...

protected:
    // ...
    unitree_go::msg::dds_::WirelessController_ joystick_msg;
    Gamepad gamepad;
    std::mutex joystick_mutex;
    int press_count = 0;
};
```

    

## Full code

Remote control and button type header files.

```C++
#pragma once

#include <stdint.h>
#include <cmath>
#include "unitree/idl/go2/WirelessController_.hpp"

namespace unitree::common
{
    // union for keys
    typedef union
    {
        struct
        {
            uint8_t R1 : 1;
            uint8_t L1 : 1;
            uint8_t start : 1;
            uint8_t select : 1;
            uint8_t R2 : 1;
            uint8_t L2 : 1;
            uint8_t F1 : 1;
            uint8_t F2 : 1;
            uint8_t A : 1;
            uint8_t B : 1;
            uint8_t X : 1;
            uint8_t Y : 1;
            uint8_t up : 1;
            uint8_t right : 1;
            uint8_t down : 1;
            uint8_t left : 1;
        } components;
        uint16_t value;
    } xKeySwitchUnion;

    // single button class
    class Button
    {
    public:
        Button() {}

        void update(bool state)
        {
            on_press = state ? state != pressed : false;
            on_release = state ? false : state != pressed;
            pressed = state;
        }

        bool pressed = false;
        bool on_press = false;
        bool on_release = false;
    };

    // full gamepad
    class Gamepad
    {
    public:
        Gamepad() {}

        void Update(unitree_go::msg::dds_::WirelessController_ &key_msg)
        {
            // update stick values with smooth and deadzone
            lx = lx * (1 - smooth) + (std::fabs(key_msg.lx()) < dead_zone ? 0.0 : key_msg.lx()) * smooth;
            rx = rx * (1 - smooth) + (std::fabs(key_msg.rx()) < dead_zone ? 0.0 : key_msg.rx()) * smooth;
            ry = ry * (1 - smooth) + (std::fabs(key_msg.ry()) < dead_zone ? 0.0 : key_msg.ry()) * smooth;
            ly = ly * (1 - smooth) + (std::fabs(key_msg.ly()) < dead_zone ? 0.0 : key_msg.ly()) * smooth;

            // update button states
            key.value = key_msg.keys();

            R1.update(key.components.R1);
            L1.update(key.components.L1);
            start.update(key.components.start);
            select.update(key.components.select);
            R2.update(key.components.R2);
            L2.update(key.components.L2);
            F1.update(key.components.F1);
            F2.update(key.components.F2);
            A.update(key.components.A);
            B.update(key.components.B);
            X.update(key.components.X);
            Y.update(key.components.Y);
            up.update(key.components.up);
            right.update(key.components.right);
            down.update(key.components.down);
            left.update(key.components.left);
        }

        float smooth = 0.03;
        float dead_zone = 0.01;

        float lx = 0.;
        float rx = 0.;
        float ry = 0.;
        float ly = 0.;

        Button R1;
        Button L1;
        Button start;
        Button select;
        Button R2;
        Button L2;
        Button F1;
        Button F2;
        Button A;
        Button B;
        Button X;
        Button Y;
        Button up;
        Button right;
        Button down;
        Button left;

    private:
        xKeySwitchUnion key;
    };
} // namespace unitree::common
```

A routine that calculates the number of times the A key is pressed.

 ```C++
#include <mutex>
#include "unitree/idl/go2/WirelessController_.hpp"
#include "unitree/robot/channel/channel_subscriber.hpp"

#include "gamepad_test.hpp"

#define TOPIC_JOYSTICK "rt/wirelesscontroller"

using namespace unitree::common;
using namespace unitree::robot;

class GamepadExample
{
public:
    GamepadExample() {}

    // setup dds model
    void InitDdsModel(const std::string &networkInterface = "")
    {
        ChannelFactory::Instance()->Init(0, networkInterface);
        joystick_subscriber.reset(new ChannelSubscriber<unitree_go::msg::dds_::WirelessController_>(TOPIC_JOYSTICK));

        joystick_subscriber->InitChannel(std::bind(&GamepadExample::MessageHandler, this, std::placeholders::_1), 1);
    }

    // set gamepad dead_zone parameter
    void SetGamepadDeadZone(float deadzone)
    {
        gamepad.dead_zone = deadzone;
    }

    // set gamepad smooth parameter
    void setGamepadSmooth(float smooth)
    {
        gamepad.smooth = smooth;
    }

    // callback function to save joystick message
    void MessageHandler(const void *message)
    {
        std::lock_guard<std::mutex> lock(joystick_mutex);
        joystick_msg = *(unitree_go::msg::dds_::WirelessController_ *)message;
    }

    // work thread
    void Step()
    {
        {
            std::lock_guard<std::mutex> lock(joystick_mutex);
            gamepad.Update(joystick_msg);
        }

        // some operations
        if (gamepad.A.on_press)
        {
            press_count += 1;
        }

        // print gamepad state
        std::cout << "lx: " << gamepad.lx << std::endl
                  << "A: pressed: " << gamepad.A.pressed
                  << "; on_press: " << gamepad.A.on_press
                  << "; on_release: " << gamepad.A.on_release
                  << std::endl << "press count: " << press_count
                  << std::endl << "===========================" << std::endl;
    }

    // start the work thread
    void Start()
    {
        control_thread_ptr = CreateRecurrentThreadEx("nn_ctrl", UT_CPU_ID_NONE, 40000, &GamepadExample::Step, this);
    }

protected:
    ChannelSubscriberPtr<unitree_go::msg::dds_::WirelessController_> joystick_subscriber;
    unitree_go::msg::dds_::WirelessController_ joystick_msg;

    Gamepad gamepad;

    ThreadPtr control_thread_ptr;

    std::mutex joystick_mutex;

    int press_count = 0;
};

int main()
{
    // create example object
    GamepadExample example;

    // set gamepad params
    example.setGamepadSmooth(0.2);
    example.SetGamepadDeadZone(0.5);

    // start program
    example.InitDdsModel();
    example.Start();

    while (1)
    {
        usleep(20000);
    }
    return 0;
}
```
