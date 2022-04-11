# ROS-SF

A Transparent and Efficient ROS Middleware using Serialization-Free Message

To be presented in Middleware 2022 (https://middleware-conf.github.io/2022/)

This work consists of three components, and we also share a test workspace:

1. **SFM Generator**

Under the /sfm_gen directory. It can generate a SFM class header file from ROS message description (.msg) file.

2. **ROS-SF Library**

Under the /sfm_lib directory. It needs to be compiled along with an application project using ROS-SF.

3. **ROS-SF Convertor**

Under the /sfm_conv directory. It can automatically convert ROS application project code to meet the needs of our ROS-SF framework.

See the README.md in each directory for further information.

4. **Test workspace**

A test workspace is placed under the /test_ws directory.
It is designed based on a [tutorial of ROS](http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29).

The "pub.cpp" generates an executable "pub", the "sub.cpp" generates "sub", and the "trans.cpp" generates "trans".

The evaluation experiment in Section 5.1 of our paper uses "pub" and "sub".
The evaluation experiment in Section 5.2 of our paper uses "pub", "trans", and a remapped "sub" (to subscribe to the second topic).

Note that they are all converted with our ROS-SF Convertor, but they can be directly used as a ROS application project as well.
The main difference between the ROS version and the ROS-SF version is the header files used during compilation.
If the original ROS headers are used, compilation will generate the ROS version executable; otherwise, if the headers generated by SFM Generator are used, compilation will generate the ROS-SF version executable, and performance improvements can be observed.
