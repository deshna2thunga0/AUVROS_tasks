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
ros::init(argc,argv,user+"Publisher");
ros::NodeHandle n;
string datas;
cout<<"Enter topic : "<<endl;
getline(cin,datas);
ros::Publisher pub =n.advertise<std_msgs::String>(datas,1000);
ros::Rate loop_rate(10);
cout<<"Node has been initialised\n";
while(ros::ok()){
	std_msgs::String msg;
	string message;
	cout<<"Ready to take input\n";
	getline(cin,message);
	cout<<"\" "<<message<<" \""<<" will be sent to topic\n";
	msg.data = message;
	pub.publish(msg);
	ros::spinOnce();
	loop_rate.sleep();
}
return 0;
}	
