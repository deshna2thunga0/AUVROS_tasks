#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from Custom.msg import Custom

def callback(data):
    print("[",data.name,"] :",data.data)

def listener(username):
    rospy.init_node(username) 
    rospy.Subscriber("chat", Custom, callback) #topic_name is inputted from main()
    rospy.spin() # spin() simply keeps python from exiting until this node is stopped

username=input()
pub = rospy.Publisher("chat", Custom, queue_size=10)
rospy.init_node(username) 
while not rospy.is_shutdown():
    data =input()
    msg=Custom()
    msg.name=username
    msg.data=data
    pub.publish(msg)
listener()