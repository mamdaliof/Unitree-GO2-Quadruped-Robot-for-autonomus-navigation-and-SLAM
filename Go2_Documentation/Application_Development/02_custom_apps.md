# Creating Custom Applications & SDK APIs

This document details how to write, compile, and run custom C++ applications utilizing the high-level `SportClient` API.

---

## 1. Reference Links to Archive Sources
If this documentation lacks detail or you need to inspect raw header files, refer to the original files:
* [Raw Creating Customer Application Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Application_Development/Creating_Customer_Application.md)

---

## 2. The `SportClient` API Class Reference

The `SportClient` handles high-level locomotion, posture, and gaits. It is located at `unitree_sdk2/include/unitree/robot/go2/sport/sport_client.hpp`.

### Stance & Motion Command List

| API Function | Parameters | Description |
| :--- | :--- | :--- |
| **`Damp()`** | None | Switches joints to damping mode (Limp). Highest priority for emergency stop. |
| **`StandUp()`** | None | Stiffens joints to stand upright at default height (`0.33` meters). |
| **`StandDown()`** | None | Moves the robot to a lying-down posture. |
| **`RecoveryStand()`** | None | Rotates and stands the robot up from a rolled-over state. |
| **`BalanceStand()`** | None | Stance control that dynamically adapts to ground slope. |
| **`Euler(roll, pitch, yaw)`** | `float` (rad) | Adjusts static orientation angles (roll/pitch/yaw). |
| **`Move(vx, vy, vyaw)`** | `float` (m/s, rad/s) | Commands linear velocity in x/y, and rotational velocity. |
| **`Sit()` / `RiseSit()`** | None | Sit down or recover to balanced stand from sitting posture. |
| **`SpeedLevel(level)`** | `int` | Sets velocity gear limits (`-1` = slow, `0` = normal, `1` = fast). |
| **`SwitchJoystick(flag)`** | `bool` | Set `false` to prevent the hand remote controller from overriding script inputs. |
| **`StaticWalk()` / `TrotRun()`**| None | Switch Locomotion gait type. |
| **`SwitchAvoidMode()`** | None | Toggle onboard obstacle avoidance sensors. |

---

## 3. Developing a Custom C++ Application (`app_height.cpp`)

This section demonstrates how to create a high-level routine where the robot stands up, sits, stands, and then moves forward.

### Step 1: Create the Source File
Inside your workspace, create a source file `app_height.cpp`:
```cpp
#include <unitree/robot/client/client.hpp>
#include <unitree/robot/go2/sport/sport_client.hpp>
#include <chrono>
#include <thread>

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    return -1;
  }

  // Initialize the channel connection using the network card name (e.g., enp3s0)
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
  
  // Instantiate and initialize sport client
  unitree::robot::go2::SportClient sport_client;
  sport_client.SetTimeout(10.0f);
  sport_client.Init();
  sport_client.WaitLeaseApplied(); // Lease control ensures priority ownership

  std::cout << "Executing movement sequences..." << std::endl;

  sport_client.RecoveryStand();    // Recover standing posture
  std::this_thread::sleep_for(std::chrono::seconds(3));

  sport_client.Sit();             // Sit down
  std::this_thread::sleep_for(std::chrono::seconds(3));

  sport_client.RiseSit();         // Recover standing stance
  std::this_thread::sleep_for(std::chrono::seconds(1));

  // Move forward at 0.2 m/s for 2 seconds
  sport_client.Move(0.2, 0.0, 0.0);
  std::this_thread::sleep_for(std::chrono::seconds(2));

  // Stop locomotion
  sport_client.Move(0.0, 0.0, 0.0);

  return 0;
}
```

---

## 4. Compilation Configuration (CMake)

Add the executable to the bottom of the `unitree_go2_sdk/CMakeLists.txt` file:
```cmake
add_executable(app_height example/user/app_height.cpp)
target_link_libraries(app_height unitree_sdk2)
```

Compile the workspace:
```bash
cd ~/unitree_go2_sdk/
mkdir build && cd build
cmake ..
make
```

---

## 5. Execution Workflow

> [!IMPORTANT]
> The custom application routes commands through the robot's main motion control service. Ensure the onboard motion control services (`mcf` or `sport_mode`) are **running normally** before executing the custom program.

```bash
cd ~/unitree_go2_sdk/build
sudo ./app_height enxf8e43b808e06  # Pass your network interface name
```

---

## 6. Project Relevance

* **Custom Nodes:** This pattern will be used to implement our high-level state machine or ROS 2 locomotion adapter node (`go2_control_node`), using the lease system to override controller inputs safely.
