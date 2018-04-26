#include "ros/ros.h"
#include "key_to_vel_pkg/VelSrv.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "trigger");

  ros::NodeHandle n;
  ros::ServiceClient client_trigger = n.serviceClient<key_to_vel_pkg::VelSrv>("v_trigger");
  key_to_vel_pkg::VelSrv vel_srv;
  vel_srv.request.vel_linear = 1.012;
  vel_srv.request.vel_angular = 2.451;

  ROS_INFO("Robot status requested by sending vel_linear and vel_angular [%.3f %.3f]", vel_srv.request.vel_linear, vel_srv.request.vel_angular);

  if (client_trigger.call(vel_srv))
  {
    ROS_INFO("Robot status received : %d", vel_srv.response.is_vel_received);
  }
  else
  {
    ROS_ERROR("Failed to call service robot status");
    return 1;
  }

  return 0;
}
