#!/usr/bin/env python
import rospy
import cv2
import numpy as np
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
from sensor_msgs.msg import CompressedImage


def callback(x):
    pass

class Calibration():
    def __init__(self):
        self.selecting_sub_image = "raw"

        if self.selecting_sub_image == "compressed":
            self._sub = rospy.Subscriber('/usb_cam/image_raw/compressed', CompressedImage, self.callback, queue_size=1)
        else:
            self._sub = rospy.Subscriber('/usb_cam/image_raw', Image, self.callback, queue_size=1)

        self.bridge = CvBridge()

    def callback(self, image_msg):
        if self.selecting_sub_image == "compressed":
            #converting compressed image to opencv image
            np_arr = np.fromstring(image_msg.data, np.uint8)
            cv_image = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
        elif self.selecting_sub_image == "raw":
            cv_image = self.bridge.imgmsg_to_cv2(image_msg, "bgr8")

        #calibration variables
        fx = 412.939491
        fy = 411.722476
        cx = 309.638220
        cy = 237.289666

        k1 = -0.431252
        k2 = 0.138689
        p1 = -0.009537
        p2 = 0.001562

        # camera calibration process
        camera_matrix = np.array([[fx,0,cx],[0,fy,cy],[0,0,1]])
        distortion_matrix = np.array([k1,k2,p1,p2,0])
        cv_image_calibrated = cv2.undistort(cv_image, camera_matrix, distortion_matrix)

        cv2.imshow('cv_image', cv_image), cv2.waitKey(1)
        cv2.imshow('calibrated_image', cv_image_calibrated), cv2.waitKey(1)

    def main(self):
        rospy.spin()

if __name__ == '__main__':
    rospy.init_node('calibration')
    node = Calibration()
    node.main()
