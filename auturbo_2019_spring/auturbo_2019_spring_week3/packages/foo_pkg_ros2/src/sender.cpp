#include "rclcpp/rclcpp.hpp"
#include "foo_pkg_ros2/msg/baz.hpp"

#include <iostream>
#include <chrono>
using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("sender");
  auto pub_number = node->create_publisher<foo_pkg_ros2::msg::Baz>("/number", 1);
  auto msg_num = std::make_shared<foo_pkg_ros2::msg::Baz>();
  auto publish_count = 0;
  rclcpp::WallRate loop_rate(10ms);

  while (rclcpp::ok())
  {
    publish_count++;
    msg_num->data = publish_count;
    RCLCPP_INFO(node->get_logger(), "Publishing number : %d", msg_num->data);
    pub_number->publish(msg_num);
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }

  rclcpp::shutdown();
  
  return 0;
}