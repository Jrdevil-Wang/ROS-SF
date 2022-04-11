# ROS-SF Generator

Code to generate corresponding serialization-free messages for ROS. It can generate corresponding SFM class header files from the original ROS message description file  (`.msg`).



## Requirements

Install ROS: (Recommended: Ubuntu 20.04 & ROS Noetic)

http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment



## Generate ROS-SF message

```
cd scripts
python generate.py -msg sensor_msgs/msg/Image.msg -l 6222720
```

+ `-msg` : to specify the relative location of the original ROS `.msg` file, which could be found under `/opt/ros/$ROS_VERSION$/include/` after installing ROS. 

+ `-l` : to specify the maximum length of the serialization-free message

Corresponding `.h` file will be generated under the folder `./include` . You can find two generated examples under it. They should be placed back to `/opt/ros/$ROS_VERSION$/include/`  to support ROS-SF (remember to backup the original ROS version!).
