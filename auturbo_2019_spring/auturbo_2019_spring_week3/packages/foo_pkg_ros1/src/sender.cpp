#include "ros/ros.h" 
#include "foo_pkg_ros1/Baz.h"





int main(int argc, char *argv[])
{
  ros::init(argc, argv, "sender");
  ros::NodeHandle n;
  ros::Publisher pub_number = n.advertise<foo_pkg_ros1::Baz>("/number", 1);
  foo_pkg_ros1::Baz msg_num;
  int publish_count = 0; 
  ros::Rate loop_rate(10);

  while (ros::ok())
  { 
    publish_count++;
    msg_num.data = publish_count;
    ROS_INFO("Publishing number : %d", msg_num.data);
    pub_number.publish(msg_num);
    ros::spinOnce();
    loop_rate.sleep();
  }

  ros::shutdown();

  return 0;
}