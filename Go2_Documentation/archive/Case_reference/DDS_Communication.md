# DDS Communication

Routine path: `unitree_sdk2/example/helloworld/publisher.cpp` 
```C++
#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>                                  
#include "HelloWorldData.hpp"

#define TOPIC "TopicHelloWorld"

using namespace unitree::robot;
using namespace unitree::common;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
      std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
      exit(-1);
    }
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
    //argv [1]  is network interface of the robot

    /*
     * New ChannelPublisherPtr
     */
    ChannelPublisherPtr<HelloWorldData::Msg> publisher = ChannelPublisherPtr<HelloWorldData::Msg>(new ChannelPublisher<HelloWorldData::Msg>(TOPIC));

    /*
     * Init channel
     */
    publisher->InitChannel();

    while (true)
    {
        /*
         * Send message
         */
        HelloWorldData::Msg msg(unitree::common::GetCurrentTimeMillisecond(), "HelloWorld.");
        publisher->Write(msg);
        sleep(1);
    }   

    return 0;
}
```

Routine path: `unitree_sdk2/example/helloworld/subscriber.cpp`

```C++
#include <unitree/robot/channel/channel_subscriber.hpp>
#include "HelloWorldData.hpp"

#define TOPIC "TopicHelloWorld"

using namespace unitree::robot;
using namespace unitree::common;

void Handler(const void* msg)
{
    const HelloWorldData::Msg* pm = (const HelloWorldData::Msg*)msg;

    std::cout << "userID:" << pm->userID() << ", message:" << pm->message() << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
      std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
      exit(-1);
    }
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
    //argv [1]  is network interface of the robot
  
    /*
     * New ChannelSubscriberPtr
     */
    ChannelSubscriberPtr<HelloWorldData::Msg> subscriber = ChannelSubscriberPtr<HelloWorldData::Msg>(new ChannelSubscriber<HelloWorldData::Msg>(TOPIC));

    /*
     * Init channel
     */
    subscriber->InitChannel(std::bind(Handler, std::placeholders::_1), 1);

    sleep(5);
  
    /*
     * Close channel
     */
    subscriber->CloseChannel();

    std::cout << "reseted. sleep 3" << std::endl;

    sleep(3);

    /*
     * Init channel use last input parameter.
     */
    subscriber->InitChannel();

    /*
     * Loop wait message.
     */
    while (true)
    {
        sleep(10);
    }

    return 0;
}
```

Routine path: `unitree_sdk2/example/client/sport_client_example.cpp`

```C++
#include <unitree/robot/go2/sport/sport_client.hpp>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
      std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
      exit(-1);
    }
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
    //argv [1]  is network interface of the robot
  
    unitree::robot::go2::SportClient sc;

    /*
     * Set request timeout 1.0s
     */
    sc.SetTimeout(1.0f);
    sc.Init();

    //Test Api

    while (true)
    {
        int32_t ret = sc.Move(0.5, 0.0, 0.0);

        std::cout << "Call sc.Move ret:" << ret << std::endl;

        usleep(1000);
    }

    return 0;
}
```
