#include<ros/ros.h>
#include<std_msgs/String.h>
#include<sstream>
#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<string>
using namespace std;

string user;
int main(int argc, char **argv)
{
cout<<"Enter Publisher name :";
getline(cin,user);
ros::init(argc,argv,user+"Publisher"); //node name has to be unique
ros::NodeHandle n; //creates the connections between nodes and topics, has properties to advertise/subscribe
string datas;
cout<<"Enter topic : ";
getline(cin,datas); // datas is the topic name
ros::Publisher pub =n.advertise<std_msgs::String>(datas,1000); //1000 is the publishing queue size
ros::Rate loop_rate(10); //an object to control speed of loop
cout<<"Node has been initialised\n";
while(ros::ok()){
	std_msgs::String msg;
	string message;
	cout<<"Ready to take input\n";
	getline(cin,message);
	cout<<"\" "<<message<<" \""<<" will be sent to topic\n";
	msg.data = message;
	pub.publish(msg); //msg has to be of type std_msgs/String as defined by nodehandle
	ros::spinOnce();	//to check for callbacks
	loop_rate.sleep();
}
return 0;
}	
