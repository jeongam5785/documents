// Author: (AuTURBO) Leon Ryuwoon Jung 

#include "ros/ros.h" 
#include "std_msgs/Int32.h"

class NumberAccumulator
{
 public:
  NumberAccumulator()
  {
    sub_number = n.subscribe("/number", 1, &NumberAccumulator::cbGetNumber, this);
  }

  void cbGetNumber(const std_msgs::Int32 msg_num)
  {
    int number = msg_num.data;

    fnAccumulate(number);
  }

  void fnAccumulate(int number)
  {
    i = i + number;

    ROS_INFO("accumulated number : %d", i);
  }

 private:
  ros::NodeHandle n;

  ros::Subscriber sub_number;

  int i = 0;
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "number_accumulator");

  NumberAccumulator numberAccumulator;

  ros::spin();

  return 0;
}