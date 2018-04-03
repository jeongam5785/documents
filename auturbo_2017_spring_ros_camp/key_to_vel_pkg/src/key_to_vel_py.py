#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Example Python node to listen on a specific topic.
"""

# Import required Python code.
import rospy

# Import custom message data.
from key_to_vel_pkg.msg import VelMsg

def callback(vel_msg):
    '''
    Callback function for the subscriber.
    '''
    # Simply print out values in our custom message.
    #rospy.loginfo(rospy.get_name() + " I heard %.3f %.3f" % (vel_msg.vel_linear + vel_msg.vel_angular))

def key_to_vel():
    '''
    Main function.
    '''
    # Create a subscriber with appropriate topic, custom message and name of
    # callback function.
    rospy.Subscriber('k_v_vel', VelMsg, callback)
    # Wait for messages on topic, go to callback function when new messages
    # arrive.
    rospy.spin()

# Main function.
if __name__ == '__main__':
    # Initialize the node and name it.
    rospy.init_node('key_to_vel_py')
    # Go to the main loop.
    key_to_vel()
