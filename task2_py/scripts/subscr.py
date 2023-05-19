import rospy
from std_msgs.msg import String

def callback(data):
    #rospy.loginfo('I heard %s', data.data)
    print(data.data)

def listener(topic_name):

    rospy.init_node('listener', anonymous=True) # anonymous=True will ensure the node name is unique
    rospy.Subscriber(topic_name, String, callback) #topic_name is inputted from main()
    rospy.spin() # spin() simply keeps python from exiting until this node is stopped

if __name__ == '__main__':
    listener(input("Enter topic to Subscribe "))