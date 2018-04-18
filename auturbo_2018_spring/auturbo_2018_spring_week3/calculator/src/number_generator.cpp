// Author: (AuTURBO) Leon Ryuwoon Jung 

#include "ros/ros.h" 
#include "std_msgs/Int32.h"

class NumberGenerator
{
 public:
  NumberGenerator()
  {
    pub_number = n.advertise<std_msgs::Int32>("/number", 1);

    ros::Rate loop_rate(10);
    while (ros::ok())
    { 
      fnPubNumber();

      ros::spinOnce();
      loop_rate.sleep();
    }
  }

  void fnPubNumber()
  {
    std_msgs::Int32 num_for_pub;

    i = i + 1;

    num_for_pub.data = i;

    ROS_INFO("generated number : %d", i);

    pub_number.publish(num_for_pub);
  }

 private:
  ros::NodeHandle n;

  ros::Publisher pub_number;

  int i = 0;
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "number_generator");

  NumberGenerator numberGenerator;

  ros::spin();

  return 0;
}