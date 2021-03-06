#include "rclcpp/rclcpp.hpp"
#include "foo_pkg_ros2/msg/baz.hpp"

#include <chrono>
using namespace std::chrono_literals;

class Sender : public rclcpp::Node
{
public:
  Sender() : Node("sender"), publish_count(0)
  {
    publisher_ = this->create_publisher
                               <foo_pkg_ros2::msg::Baz>("/number", 1);
    auto callback =
      [this]() -> void {
        auto msg_num = foo_pkg_ros2::msg::Baz();
        msg_num.data = publish_count++;
        this->publisher_->publish(msg_num);
      };
    timer_ = this->create_wall_timer(10ms, callback);
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<foo_pkg_ros2::msg::Baz>::SharedPtr publisher_;
  size_t publish_count;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Sender>());
  rclcpp::shutdown();
  return 0;
}