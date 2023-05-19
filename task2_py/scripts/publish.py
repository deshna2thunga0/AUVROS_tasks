#!/usr/bin/env python
import rospy
from std_msgs.msg import String

pub = rospy.Publisher(input("Enter topic to Publish : "), String, queue_size=10)
rospy.init_node('talker', anonymous=True) # anonymous=True will ensure the node name is unique
while not rospy.is_shutdown():
    hello_str =input()
    pub.publish(hello_str)
