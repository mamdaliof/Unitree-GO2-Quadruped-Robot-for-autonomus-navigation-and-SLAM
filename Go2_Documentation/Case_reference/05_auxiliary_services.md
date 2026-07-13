# Auxiliary Services: LED Control & Reinforcement Learning

This document covers configuring headlight LED brightness settings and launching reinforcement learning control training pipelines in simulation.

---

## 1. Reference Links to Archive Sources
For original code examples and simulator setup steps, refer to the archived guides:
* [[Go2_Documentation/archive/Case_reference/Light_Control|Raw Light Control Guide]]
* [[Go2_Documentation/archive/Case_reference/RL_Control_Routine|Raw RL Control Routine Guide]]

---

## 2. White LED Strobe & Brightness Control (`VuiClient`)

The Go2 Edu headlight LED brightness can be adjusted programmatically (from `0` for off to `10` for maximum brightness) using the `VuiClient` class.

### SDK C++ Example (`go2_vui_client.cpp`)
```cpp
#include <unitree/robot/go2/vui/vui_client.hpp>

int main(int32_t argc, const char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
        return -1;
    }

    // Initialize Factory
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);

    unitree::robot::go2::VuiClient vc;
    vc.SetTimeout(1.0f);
    vc.Init();

    int level = 0;
    int value = 0;

    // Loop to oscillate brightness: off -> dim -> bright -> off
    while (true) {
        vc.SetBrightness(level);
        std::cout << "Headlight brightness set to: " << level << std::endl;
        
        ++level %= 11; // Level ranges 0 to 10
        sleep(1);

        vc.GetBrightness(value);
        std::cout << "Current reported brightness: " << value << std::endl;
        sleep(1);
    }
    return 0;
}
```

### API Function Prototypes
* **`int32_t SetBrightness(int level)`**
  * *Parameters:* `level` `[0 ~ 10]`
  * *Return:* `0` on success.
* **`int32_t GetBrightness(int& value)`**
  * *Parameters:* Integer reference.
  * *Return:* `0` on success.

---

## 3. Simulation Reinforcement Learning (`Isaac Gym`)

Reinforcement learning (RL) models are trained offline in simulation before deployment to the physical Go2 joints.

### Hardware Prerequisites
* **Processor:** Dedicated NVIDIA graphics card (VRAM > 8GB, RTX series).
* **Software drivers:** NVIDIA CUDA drivers (version `525` recommended) on Ubuntu 18.04/20.04.

### Virtual Environment Setup
It is recommended to deploy dependencies inside a Conda virtual environment:
```bash
# Create and activate environment
conda create -n rl-go2 python=3.8
conda activate rl-go2

# Install PyTorch with CUDA 11.3 support
pip3 install torch==1.10.0+cu113 torchvision==0.11.1+cu113 torchaudio==0.10.0+cu113 -f https://download.pytorch.org/whl/cu113/torch_stable.html

# Note: NumPy version must be capped
pip install numpy==1.23.5
```

### Simulator & Legged Robotics Library Installation
1. Download **[Isaac Gym Preview 4](https://developer.nvidia.com/isaac-gym)**.
2. Extract the package, enter `python/` and install:
   ```bash
   cd isaacgym/python
   pip install -e .
   ```
3. Install the **`rsl_rl`** reinforcement learning library:
   ```bash
   git clone https://github.com/leggedrobotics/rsl_rl
   cd rsl_rl
   git checkout v1.0.2
   pip install -e .
   ```

### Training the locomotion Model
1. Clone the Unitree RL training examples:
   ```bash
   git clone https://github.com/unitreerobotics/unitree_rl_gym.git
   ```
2. Open `train.py` and `play.py` and modify the system path appends to reference your local installation directory:
   `sys.path.append("/your/path/to/unitree_rl_gym/legged_gym")`
3. Launch the training script:
   ```bash
   conda activate rl-go2
   python3 train.py --task=go2
   ```
   *Note: Modify the `args.headless` flag inside `train.py` to disable/enable visual GUI output during training.*
4. Play back the trained model weights:
   ```bash
   python play.py --task=go2
   ```

---

## 4. Project Relevance
* **Visual Inspection:** High-intensity headlight control (`VuiClient`) is critical when the robot enters dark pipelines, undercarriages, or warehouses to ensure inspection cameras capture clear images.
* **RL Locomotion:** Training custom gait networks in Isaac Gym allows us to optimize stair climbing trajectories and slippery terrain recovery strategies before testing them on the physical Go2 Edu.
