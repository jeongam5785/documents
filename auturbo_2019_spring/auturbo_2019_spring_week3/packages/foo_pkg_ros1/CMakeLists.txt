cmake_minimum_required(VERSION 2.8.3)
project(foo_pkg_ros1)






find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

add_message_files(DIRECTORY msg FILES Baz.msg)
generate_messages(DEPENDENCIES std_msgs)

catkin_package(CATKIN_DEPENDS std_msgs rclcpp message_runtime)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(sender src/sender.cpp)

target_link_libraries(sender ${catkin_LIBRARIES})
add_dependencies(sender foo_pkg_ros1_gencpp)

install(TARGETS sender
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

add_executable(receiver src/receiver.cpp)

target_link_libraries(receiver ${catkin_LIBRARIES})
add_dependencies(receiver foo_pkg_ros1_gencpp)

install(TARGETS receiver
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)