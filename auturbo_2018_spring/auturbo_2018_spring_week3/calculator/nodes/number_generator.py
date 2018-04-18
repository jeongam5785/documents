#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Author: (AuTURBO) Leon Ryuwoon Jung 

import rospy
from std_msgs.msg import Int32

class NumberGenerator():
    def __init__(self):
        self.pub_number = rospy.Publisher('/number', Int32, queue_size = 1)

        self.i = 0

        loop_rate = rospy.Rate(10)
        while not rospy.is_shutdown():
            self.fnPubNumber()
            loop_rate.sleep()

    def fnPubNumber(self):
        num_for_pub = Int32()

        self.i = self.i + 1

        num_for_pub.data = self.i

        rospy.loginfo('generated number : %d', self.i)

        self.pub_number.publish(num_for_pub)

    def main(self):
        rospy.spin()

if __name__ == '__main__':
    rospy.init_node('number_generator')
    node = NumberGenerator()
    node.main()