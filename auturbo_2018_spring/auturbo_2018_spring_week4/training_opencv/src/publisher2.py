#!/usr/bin/env python
import rospy
import cv2
import numpy as np
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
from sensor_msgs.msg import CompressedImage


class Publisher():
    def __init__(self):
        self.selecting_sub_image = "raw"

        if self.selecting_sub_image == "compressed":
            self._sub = rospy.Subscriber('/usb_cam/image_raw/compressed', CompressedImage, self.callback, queue_size=1)
        else:
            self._sub = rospy.Subscriber('/usb_cam/image_raw', Image, self.callback, queue_size=1)


        self._pub2 = rospy.Publisher('camera/image_raw', Image, queue_size=1)

        self.bridge = CvBridge()

    def callback(self, image_msg):
        #cv_image = cv2.imread('index.jpeg',1)
        #publishing raw image
        #cv2.imshow('cv_image', cv_image), cv2.waitKey(1)

        self._pub2.publish(image_msg)


    def main(self):
        rospy.spin()

if __name__ == '__main__':
    rospy.init_node('publisher')
    node = Publisher()
    node.main()
