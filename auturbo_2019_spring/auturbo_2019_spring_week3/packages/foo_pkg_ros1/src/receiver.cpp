#include "ros/ros.h" 
#include "foo_pkg_ros1/Baz.h"



void callback_function(const foo_pkg_ros1::Baz msg_num)
{
  ROS_INFO("Received : %d", msg_num.data);
}

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "receiver");
  ros::NodeHandle n;
  ros::Subscriber sub_number = n.subscribe<foo_pkg_ros1::Baz>
                                                    ("/number", 1, callback_function);
  ros::spin();
  ros::shutdown();

  


  return 0;
}