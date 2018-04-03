cmake_minimum_required(VERSION 2.8.3)
project(key_to_vel_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  genmsg
)

add_message_files(DIRECTORY msg
  FILES
  VelMsg.msg
)

add_service_files(DIRECTORY srv
  FILES
  VelSrv.srv
)

generate_messages(
  DEPENDENCIES
)

catkin_package(
# INCLUDE_DIRS include
# LIBRARIES key_to_vel_pkg
# CATKIN_DEPENDS roscpp rospy
# DEPENDS system_lib
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(key_to_vel src/key_to_vel.cpp)
target_link_libraries(key_to_vel ${catkin_LIBRARIES})
add_dependencies(key_to_vel key_to_vel_pkg_generate_messages_cpp)

add_executable(viewer src/viewer.cpp)
target_link_libraries(viewer ${catkin_LIBRARIES})
add_dependencies(viewer key_to_vel_pkg_generate_messages_cpp)

add_executable(robot src/robot.cpp)
target_link_libraries(robot ${catkin_LIBRARIES})
add_dependencies(robot key_to_vel_pkg_generate_messages_cpp)

add_executable(trigger src/trigger.cpp)
target_link_libraries(trigger ${catkin_LIBRARIES})
add_dependencies(trigger key_to_vel_pkg_generate_messages_cpp)
