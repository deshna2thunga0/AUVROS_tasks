#include<ros/ros.h>
#include<std_msgs/String.h>
#include<sstream>
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

void cb(const std_msgs::String::ConstPtr& msg){
    cout<<(msg->data.c_str())<<endl;
}
int main(int argc , char ** argv){
    string sub1;
    cout<<"Enter subscriber name : ";
    getline(cin,sub1);
    ros::init(argc,argv,sub1); //this name has to be different
    ros::NodeHandle nr;
    string datas;
    cout<<"Enter data stream : ";
    getline(cin,datas);
    ros::Subscriber sub = nr.subscribe(datas,1000,cb); //cb callback function
    ros::spin(); //listens for interrupts doesnt exit until kill signal ctrl c comes
    return 0;
}
