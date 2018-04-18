#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Author: (AuTURBO) Leon Ryuwoon Jung 

import rospy

from std_msgs.msg import Int32

class NumberAccumulator():
    def __init__(self):
        self.sub_number = rospy.Subscriber('/number', Int32, self.cbGetNumber, queue_size = 1)

        self.i = 0

    def cbGetNumber(self, msg_num):
        number = msg_num.data

        self.fnAccumulate(number)

    def fnAccumulate(self, number):
        self.i = self.i + number

        rospy.loginfo('accumulated number : %d', self.i)

    def main(self):
        rospy.spin()

if __name__ == '__main__':
    rospy.init_node('number_accumulator')
    node = NumberAccumulator()
    node.main()