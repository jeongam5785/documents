#include "rclcpp/rclcpp.hpp"
#include "foo_pkg_ros2/msg/baz.hpp"

rclcpp::Node::SharedPtr node = nullptr;

void callback_function(const foo_pkg_ros2::msg::Baz::SharedPtr msg_num)
{
  RCLCPP_INFO(node->get_logger(), "Received : %d", msg_num->data);
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  node = rclcpp::Node::make_shared("receiver");

  rmw_qos_profile_t custom_qos_profile = rmw_qos_profile_default;
  custom_qos_profile.depth = 1;
  auto sub_number = node->create_subscription<foo_pkg_ros2::msg::Baz>
                                  ("/number", callback_function, custom_qos_profile);
  rclcpp::spin(node);
  rclcpp::shutdown();

  sub_number = nullptr;
  node = nullptr;
  return 0;
}