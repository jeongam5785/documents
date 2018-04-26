#include "ros/ros.h" 
#include "key_to_vel_pkg/VelMsg.h"

int main(int argc, char **argv) 
{
  ros::init(argc, argv, "key_to_vel"); 
  ros::NodeHandle n;
  ros::Publisher pub_vel = n.advertise<key_to_vel_pkg::VelMsg>("k_v_vel", 1000); 
  ros::Rate loop_rate(10);

  while (ros::ok())
  { 
    key_to_vel_pkg::VelMsg vel_msg;

    vel_msg.vel_linear = 1.012;
    vel_msg.vel_angular = 2.451;

    ROS_INFO("Message [vel_linear vel_angular] was published as: [%.3f %.3f]", vel_msg.vel_linear, vel_msg.vel_angular);

    pub_vel.publish(vel_msg);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
} 
