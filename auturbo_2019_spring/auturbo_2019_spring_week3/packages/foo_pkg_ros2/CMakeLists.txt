cmake_minimum_required(VERSION 3.5)
project(foo_pkg_ros2)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED) 
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rmw REQUIRED)

include_directories(
)

rosidl_generate_interfaces(foo_pkg_ros2 "msg/Baz.msg" DEPENDENCIES std_msgs)

ament_package()

add_executable(sender src/sender.cpp)

get_available_rmw_implementations(rmw_implementations2)
foreach(rmw_implementation ${rmw_implementations2})
  find_package("${rmw_implementation}" REQUIRED)
  get_rmw_typesupport(typesupport_impls "${rmw_implementation}" LANGUAGE "cpp")
  foreach(typesupport_impl ${typesupport_impls})
    rosidl_target_interfaces(sender
      foo_pkg_ros2 ${typesupport_impl}
    )
  endforeach()
endforeach()

ament_target_dependencies(sender "std_msgs" "rclcpp")

install(TARGETS sender DESTINATION lib/${PROJECT_NAME})

add_executable(receiver src/receiver.cpp)

get_available_rmw_implementations(rmw_implementations2)
foreach(rmw_implementation ${rmw_implementations2})
  find_package("${rmw_implementation}" REQUIRED)
  get_rmw_typesupport(typesupport_impls "${rmw_implementation}" LANGUAGE "cpp")
  foreach(typesupport_impl ${typesupport_impls})
    rosidl_target_interfaces(receiver
      foo_pkg_ros2 ${typesupport_impl}
    )
  endforeach()
endforeach()

ament_target_dependencies(receiver "std_msgs" "rclcpp")

install(TARGETS receiver DESTINATION lib/${PROJECT_NAME})
