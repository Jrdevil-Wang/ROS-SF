# ROS-SF Message Generator

Code to generate corresponding serialization-free messages for ROS.



## Requirements

Install ROS:

http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment

### 

## Generate ROS-SF message

```
cd scripts
python generate.py -msg sensor_msgs/msg/Image.msg -l 6222720
```

`-msg` : to specify the relative location of the original ROS `.msg` file

`-l` : to specify the maximum length of the serialization-free message

Corresponding `.h` file will be generated under folder `include`.
