# ROS-SF Generator

Code to generate corresponding serialization-free messages for ROS.

## Requirements

Install ROS: (Recommended: Ubuntu 18.04 & ROS Noetic)

http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment

## Generate ROS-SF message

```
cd scripts
python generate.py -msg sensor_msgs/msg/Image.msg -l 6222720
```

`-msg` : to specify the relative location of the original ROS `.msg` file, which should be located under /opt/ros/$ROS_VERSION$/include/

`-l` : to specify the maximum length of the serialization-free message

Corresponding `.h` file will be generated under the folder `include`, where two generated examples can be found.
