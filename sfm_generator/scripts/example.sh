#!/bin/sh

ROS_PATH=/opt/ros/noetic/share

python3 gen_header.py ${ROS_PATH}/sensor_msgs/msg/Image.msg \
  -Istd_msgs:${ROS_PATH}/std_msgs/msg \
  -p sensor_msgs -o ../include -e ../templates/
