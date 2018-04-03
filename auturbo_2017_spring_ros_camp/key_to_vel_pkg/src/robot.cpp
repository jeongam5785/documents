#include "ros/ros.h"
#include "key_to_vel_pkg/VelSrv.h"

bool pulltrigger(key_to_vel_pkg::VelSrv::Request &req_vel, key_to_vel_pkg::VelSrv::Response &res_status)
{
  res_status.is_vel_received = true;

  ROS_INFO("vel_linear and vel_angular was received as : [%.3f %.3f]", req_vel.vel_linear, req_vel.vel_angular);
  ROS_INFO("sending back status: [%d]", res_status.is_vel_received);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "robot");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("v_trigger", pulltrigger);
  ROS_INFO("Ready to get vel_linear and vel_angular.");
  ros::spin();

  return 0;
}
