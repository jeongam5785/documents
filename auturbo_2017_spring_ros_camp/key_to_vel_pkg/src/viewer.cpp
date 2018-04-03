#include "ros/ros.h" 
#include "key_to_vel_pkg/VelMsg.h"

void callbackfunc(const key_to_vel_pkg::VelMsg vel_msg)
{
  ROS_INFO("Message [vel_linear vel_angular] was subscribed as: [%.3f %.3f]", vel_msg.vel_linear, vel_msg.vel_angular);
}

int main(int argc, char **argv) 
{
  ros::init(argc, argv, "viewer"); 
  ros::NodeHandle n;
  ros::Subscriber sub_vel = n.subscribe("k_v_vel", 1000, callbackfunc); 
  ros::spin();
  return 0;
}

