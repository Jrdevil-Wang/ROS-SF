# ROS-SF

A Transparent and Efficient ROS Middleware using Serialization-Free Message

To be presented in Middleware 2022 (https://middleware-conf.github.io/2022/)

This work consists of three components:

1. **SFM Generator**

Under the /sfm_gen directory. It can generate a SFM class header file from ROS message description (.msg) file.

2. **ROS-SF Library**

Under the /sfm_lib directory. It needs to be compiled along with an application project using ROS-SF.

3. **ROS-SF Convertor**

Under the /sfm_conv directory. It can automatically convert ROS application project code to meet the needs of our ROS-SF framework.

See the README.md in each directory for further information.
