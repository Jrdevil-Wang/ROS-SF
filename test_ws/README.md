# Test workspace

A test workspace is placed under the folder `./test_ws`. It is designed based on a [tutorial of ROS](http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29).

## Compilation

```
catkin_make
```


`pub.cpp` , `sub.cpp`  and `trans.cpp` generate executables `pub`,  `sub`, and `trans` respectively. 

## Performance Test

### One-to-One Communication Test

The following steps are for the experiment in Section 5.1.

+ Open a terminal and run the sub:

  ```
  rosrun pub_test sub
  ```

+ Open another terminal and run the pub:

  ```
  rosrun pub_test pub
  ```

+ The terminal running the sub should show the one-to-one latency.

+ Follow the instructions of `./sfm_gen/README.md` and `./sfm_lib/README.md` to replace ROS header files with the ROS-SF generated message header file and ROS-SF library.

+ Re-compile the workspace

  ```
  catkin_make clean; catkin_make
  ```

+ Repeat the above test and enjoy the improved one-to-one latency.

+ To recover to the ROS environment, replace the ROS-SF header files with the backup ROS header files.

### Ping-Pong Test

The following steps are for the experiment in Section 5.2.

+ Open a terminal (on machine A) and run the sub (with remapped topic):

  ```
  rosrun pub_test sub /img_test:=/img_rtt
  ```

+ Open another terminal (on machine B) and run the trans:

  ```
  rosrun pub_test trans
  ```

+ Open another terminal (on machine A) and run the pub:

  ```
  rosrun pub_test pub
  ```

+ The terminal running the sub should show the ping-pong latency.

+ Follow the instructions of `./sfm_gen/README.md` and `./sfm_lib/README.md` to replace ROS headers with the ROS-SF generated message header and ROS-SF library.

+ Re-compile the workspace

  ```
  catkin_make clean; catkin_make
  ```

+ Repeat the above test and enjoy the improved ping-pong latency.

+ To recover to the ROS environment, replace the ROS-SF header files with the backup ROS header files.

