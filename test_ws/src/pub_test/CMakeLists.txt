cmake_minimum_required(VERSION 2.8.3)
project(pub_test)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs sensor_msgs genmsg)

## Declare ROS messages and services
#add_message_files(DIRECTORY msg FILES Num.msg)
#add_service_files(DIRECTORY srv FILES AddTwoInts.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs sensor_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(pub MemoryManager.cpp pub.cpp)
target_link_libraries(pub ${catkin_LIBRARIES})

add_executable(trans MemoryManager.cpp trans.cpp)
target_link_libraries(trans ${catkin_LIBRARIES})

add_executable(sub MemoryManager.cpp sub.cpp)
target_link_libraries(sub ${catkin_LIBRARIES})

