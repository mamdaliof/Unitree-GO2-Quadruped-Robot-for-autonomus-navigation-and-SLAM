# C++ DDS Communication Routines

This document details how to establish native DDS communication channels using `unitree_sdk2` wrappers, mapping raw publisher and subscriber threads.

---

## 1. Reference Links to Archive Sources
For the untouched original C++ source files, refer to the archived document:
* [Raw DDS Communication Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Case_reference/DDS_Communication.md)

---

## 2. Channel Initialization & Network card Binding

Before publishing or subscribing, you must initialize the global `ChannelFactory` singleton with a domain ID and the name of the Ethernet card connected to the robot.

```cpp
#include <unitree/robot/channel/channel_publisher.hpp>

int main(int argc, char **argv) {
    // Bind to domain 0 and the Ethernet interface passed from the command line (e.g. enp3s0)
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
}
```

---

## 3. Publisher C++ Implementation

The `ChannelPublisher` class publishes structured IDL message instances over a named topic.

```cpp
#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "HelloWorldData.hpp"

#define TOPIC "TopicHelloWorld"

using namespace unitree::robot;
using namespace unitree::common;

int main(int argc, char **argv)
{
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);

    // Create a publisher pointer targeting the HelloWorld IDL message
    ChannelPublisherPtr<HelloWorldData::Msg> publisher = 
        ChannelPublisherPtr<HelloWorldData::Msg>(new ChannelPublisher<HelloWorldData::Msg>(TOPIC));

    // Initialize the publishing channel
    publisher->InitChannel();

    while (true)
    {
        // Construct and write msg: GetCurrentTimeMillisecond() is helper to stamp
        HelloWorldData::Msg msg(GetCurrentTimeMillisecond(), "HelloWorld.");
        publisher->Write(msg);
        sleep(1);
    }
    return 0;
}
```

---

## 4. Subscriber C++ Implementation

The `ChannelSubscriber` class registers callback functions executed on each message reception.

```cpp
#include <unitree/robot/channel/channel_subscriber.hpp>
#include "HelloWorldData.hpp"

#define TOPIC "TopicHelloWorld"

using namespace unitree::robot;

// DDS callback function
void MessageCallback(const void* msg)
{
    const HelloWorldData::Msg* pm = (const HelloWorldData::Msg*)msg;
    std::cout << "Stamped userID: " << pm->userID() 
              << " | Message: " << pm->message() << std::endl;
}

int main(int argc, char **argv)
{
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);

    // Instantiate subscriber
    ChannelSubscriberPtr<HelloWorldData::Msg> subscriber = 
        ChannelSubscriberPtr<HelloWorldData::Msg>(new ChannelSubscriber<HelloWorldData::Msg>(TOPIC));

    // Initialize channel and bind callback
    subscriber->InitChannel(std::bind(MessageCallback, std::placeholders::_1), 1);

    while (true) {
        sleep(10);
    }
    return 0;
}
```

---

## 5. Project Relevance
* **Custom Interfaces:** This CycloneDDS pattern is utilized in our state machine orchestrator and perception nodes to bypass standard ROS 2 latency when sending high-rate sensor array updates or receiving rapid BMS updates.
