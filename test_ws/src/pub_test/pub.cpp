#include "ros/ros.h"
#include "sensor_msgs/Image.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "pub");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<sensor_msgs::Image>("/img_test", 1);
  ros::Rate loop_rate(10);
  int count = 0;
  while (ros::ok()) {
/* tmp */ boost::shared_ptr<sensor_msgs::Image> _psfm_msg(new sensor_msgs::Image());
    sensor_msgs::Image & msg(*_psfm_msg);
    msg.header.stamp = ros::Time::now();
    msg.width = 1920;
    msg.height = 1080;
    msg.data.resize(1920 * 1080 * 3);

    pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
  return 0;
}

