#include "ros/ros.h"
#include "sensor_msgs/Image.h"

void chatterCallback(const sensor_msgs::Image::ConstPtr & msg) {
  ros::Duration dur = ros::Time::now() - msg->header.stamp; 
  ROS_INFO("I heard: [%d x %d], delay = %06f ", msg->width, msg->height, dur.toSec() * 1000.0);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "sub");
  ros::NodeHandle n;
  // process
  ros::Subscriber sub = n.subscribe("/img_test", 2, chatterCallback);

  // multi-machines 
  // ros::Subscriber sub = n.subscribe("/img_rtt", 2, chatterCallback);

  ros::spin();
  return 0;
}
