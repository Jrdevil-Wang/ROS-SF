# ROS-SF Library

To use ROS-SF framework, ROS-SF library needs to be compiled along with the application project. The ROS-SF Library consists of two kinds of files. 

- `subscription_callback_helper.h`

  `subscription_callback_helper.h` should be placed at `/opt/ros/$ROS_VERSION$/include/`. Remember to backup the original file before replace it! The only modification is that a `buf` field is added to the `SubscriptionCallbackHelperDeserializeParams` struct. Detail can be found at:
  https://github.com/Jrdevil-Wang/ROS-SF/blob/49fb93d3a7315bb88fc8515f26c2609b808608f6/sfm_lib/subscription_callback_helper.h#L57

- `*.h` 

  All other  `.h` files are included by the  header files generated by the SFM Generator. Therefore, they should be placed at `/opt/ros/$ROS_VERSION$/include/sensor_msgs/`.

- `MemoryManager.cpp`

  `MemoryManager.cpp` should be compiled with the ROS application project. See `./test_ws` for an example.

