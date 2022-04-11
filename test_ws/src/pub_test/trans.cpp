#include "ros/ros.h"
#include "sensor_msgs/Image.h"

ros::Publisher pub;

void chatterCallback(const sensor_msgs::Image::ConstPtr & msg) {
  //ros::Duration dur = ros::Time::now() - msg->header.stamp; 
  //ROS_INFO("I heard: [%d x %d], delay = %06f", msg->width, msg->height, dur.toSec() * 1000.0);
  
  boost::shared_ptr<sensor_msgs::Image> _psfm_msg(new sensor_msgs::Image());
  sensor_msgs::Image & img(*_psfm_msg);
 
  // sensor_msgs::Image img;
  img.header.stamp = (*msg).header.stamp;
  img.width = 256;
  img.height = 256;
  img.data.resize(256 * 256 * 3);
  pub.publish(img);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "trans");
  ros::NodeHandle n;
  pub = n.advertise<sensor_msgs::Image>("/img_rtt", 2);
  ros::Subscriber sub = n.subscribe("/img_test", 1, chatterCallback);
  ros::spin();
  return 0;
}
