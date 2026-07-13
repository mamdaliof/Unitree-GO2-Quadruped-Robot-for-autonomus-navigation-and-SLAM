# RL Control Routine

This document will provide a simple example of reinforcement learning control for Go2. The following will explain how to use **isaac_gym** simulation platform trains the Go2 control algorithm.

# Hardware preparation

Due to isaac_gym simulation platform requires `CUDA`, and this article suggests configuring NVIDIA graphics cards (graphics memory>8GB, RTX series graphics cards) for hardware and installing corresponding graphics card drivers. It is recommended that the system use `ubuntu18/20`, graphics card driver version 525.
<center>

![](https://doc-cdn.unitree.com/static/2023/9/11/3ab2cbb2083b489da41f7aecc6a8a299_715x448.png)

</center>

# Environmental configuration
   
   It is recommended to configure the virtual environment `conda`.
   1. Create a virtual environment
```bash
      conda create -n rl-go2 python=3.8
```

   2. Activate virtual environment
```bash
        conda activate rl-go2
```

   3. Install `CUDA`， `pytorch`
```bash
   pip3 install torch==1.10.0+cu113 torchvision==0.11.1+cu113 torchaudio==0.10.0+cu113 -f https://download.pytorch.org/whl/cu113/torch_stable.html
```
> Please note that the numpy library version should not be too high. It is recommended to install version 1.23.5.

4. Download [Isaac Gym Preview 4](https://developer.nvidia.com/isaac-gym) Simulate the platform, unzip it and enter the `python` directory to install using `pip`.

```bash
# current directory: isaacgym/python
pip install -e .
```

   Run the routine in the `Python/examples` directory to verify if the installation was successful.
```bash
# current directory: isaacgym/python/examples
python 1080_balls_of_solitude.py
```
If the installation is successful, you can see the following window.
  

  ![](https://doc-cdn.unitree.com/static/2023/9/11/3abb56841d1d49c5bf6cc11b43148bb6_1600x937.png)
 6. Install rsl_rl library (use v1.0.2)
 ```bash
git clone https://github.com/leggedrobotics/rsl_rl
cd rsl_rl
git checkout v1.0.2
pip install -e .
``` 

# Model training usage
   1. Download the official example code of Unitree
```bash
   git clone https://github.com/unitreerobotics/unitree_rl_gym.git
```
   2. Modify the `sys.path.append("/home/unitree/go2/legged_gym")` in `legged_gym/scripts/train.py`,  `legged_gym/scripts/play.py`  to its own path.
4. Activate reinforcement learning virtual environment

```bash
   conda activate rl-go2
```

   4. Execute training instructions and start training.
```bash
   python3  train.py --task=go2
```
Modify the `args.headless` parameter in the train.py file to turn on or off the visualization interface.

   isaac_gym appears on the following interface, then the training begins.
   ![](https://doc-cdn.unitree.com/static/2023/9/11/3c21ad393e5345d181ecb2d9896b5041_1848x1053.png)
   The terminal output window is as follows:
<center>
   
   ![](https://doc-cdn.unitree.com/static/2023/9/11/09da58438faf451cbb0c6a1ac62f0c75_838x527.png)
</center>
  
After 1500 training sessions, run the test instructions.
```c++
python play.py --task=go2
```
# Effect demonstration
<video src="https://doc-cdn.unitree.com/static/2023/9/12/37a70cf8c0d34f97b40ae35a4a26ecd1.mp4" autoplay loop="loop" style="width: 100%" controls></video>
