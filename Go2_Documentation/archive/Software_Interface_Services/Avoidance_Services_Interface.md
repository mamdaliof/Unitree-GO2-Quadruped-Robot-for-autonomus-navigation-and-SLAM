# Avoidance Services Interface

## ObstaclesAvoidClient Class

ObstaclesAvoidClient is the client provided by the Go2 obstacle avoidance service. Through ObstaclesAvoidClient, you can use the RPC method to enable/disable and get the status of the Go2 obstacle avoidance function.

### Interface Error Code List:

This Client does not have a specific error list. For the general list, please refer to: [List of some general error codes](https://support.unitree.com/home/en/developer/DDS_services#heading-7)

### Class and Interface Description:

|  **Class Name**  |  **Constructor and Destructor**  |
| :---: | :--- |
|  ObstaclesAvoidClient  |  explicit ObstaclesAvoidClient(); \~ObstaclesAvoidClient();  |

|  **Function Name**  |  **SwitchSet**  |
| :---: | :--- |
|  **Function Prototype**  |  int32\_t SwitchSet(bool enable)  |
|  **Function Summary**  |  Sets the obstacle avoidance function to be enabled or disabled.  |
|  **Parameters**  |  **enable**: Set to true to enable, false to disable.  |
|  **Return Value**  |  Returns 0 on success, otherwise returns the relevant error code.  |
|  **Notes**  |   |

|  **Function Name**  |  **SwitchGet**  |
| :---: | :--- |
|  **Function Prototype**  |  int32\_t SwitchGet(bool& enable);  |
|  **Function Summary**  |  Gets whether the obstacle avoidance function is enabled.  |
|  **Parameters**  |  **enable**: Return value, true for enabled, false for disabled.  |
|  **Return Value**  |  Returns 0 on success, otherwise returns the relevant error code.  |
|  **Notes**  |   |

|  **Function Name**  |  **UseRemoteCommandFromApi**  |
| :---: | :--- |
|  **Function Prototype**  |  int32\_t UseRemoteCommandFromApi(bool isRemoteCommandsFromApi)  |
|  **Function Summary**  |  Takes over the speed command control from the remote controller.  |
|  **Parameters**  |  **isRemoteCommandsFromApi**: Set to true to enable takeover, false to disable takeover.  |
|  **Return Value**  |  Returns 0 on success, otherwise returns the relevant error code.  |
|  **Notes**  |  `isRemoteCommandsFromApi` must be set to true to control dog obstacle avoidance via API. |

|  **Function Name**  |  **Move**  |
| :---: | :--- |
|  **Function Prototype**  |  int32\_t Move(float x, float y, float yaw);  |
|  **Function Summary**  |  Movement control in obstacle avoidance mode.  |
|  **Parameters**  |  **x**: Body x-direction velocity command, limited to -1.5\~+1.5(m/s); **y**: Body y-direction velocity command, limited to -1\~+1(m/s); **yaw**: Body yaw angular velocity command, limited to -1.57\~+1.57(rad/s).  |
|  **Return Value**  |  Returns 0 on success, otherwise returns the relevant error code.  |
|  **Notes**  | `isRemoteCommandsFromApi` must be set to true to control dog obstacle avoidance via the Move function.  |

|  **Function Name**  |  **MoveToIncrementPosition**  |
| :---: | :--- |
|  **Function Prototype**  |  int32\_t MoveToIncrementPosition(float x, float y, float yaw);  |
|  **Function Summary**  |  Movement control in obstacle avoidance mode.  |
|  **Parameters**  |  **x**: Incremental position in the body's x-direction, limited to -2.0\~+2.0(m); **y**: Incremental position in the body's y-direction, limited to -2.0\~+2.0(m); **yaw**: Incremental yaw angle, limited to -1.57\~+1.57(rad).  |
|  **Return Value**  |  Returns 0 on success, otherwise returns the relevant error code.  |
|  **Notes**  | `isRemoteCommandsFromApi` must be set to true to control dog obstacle avoidance via the MoveToIncrementPosition function.  |

|  **Function Name**  |  **MoveToAbsolutePosition**  |
| :---: | :--- |
|  **Function Prototype**  |  int32\_t MoveToAbsolutePosition(float x, float y, float yaw);  |
|  **Function Summary**  |  Movement control in obstacle avoidance mode.  |
|  **Parameters**  |  **x**: Absolute position in the world coordinate system x-direction; **y**: Absolute position in the world coordinate system y-direction; **yaw**: Yaw angle in the world coordinate system.  |
|  **Return Value**  |  Returns 0 on success, otherwise returns the relevant error code.  |
|  **Notes**  | `isRemoteCommandsFromApi` must be set to true to control dog obstacle avoidance via the MoveToAbsolutePosition function.  |

Example:

```c++
#include <unitree/robot/go2/obstacles_avoid/obstacles_avoid_client.hpp>

using namespace unitree::common;
using namespace unitree::robot;
using namespace unitree::robot::go2;

int main()
{
    unitree::robot::ChannelFactory::Instance()->Init(0, "enx00e04c36141b");//enx00e04c36141b is the network port number, users should modify it according to their situation
    unitree::robot::go2::ObstaclesAvoidClient sc;
    sc.SetTimeout(5.0f);
    sc.Init();
    sc.SwitchSet(true);//Enable obstacle avoidance
    usleep(1000000);
    sc.UseRemoteCommandFromApi(true);//Take over speed control from the remote controller
    sc.Move(1.0,0.0,0.0);//Move along the body's x-direction at 1m/s, automatically avoiding obstacles when encountered
    int tem = 0;
    while (true)
    {
      usleep(1000000);
      if(tem<=5)
      {
        tem++;
      }
      else
      {
        sc.UseRemoteCommandFromApi(false);//Disable after 5 seconds
        sc.SwitchSet(false);//Disable after 5 seconds
      }
    }
    return 0;
}

```
