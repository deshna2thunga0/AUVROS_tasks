#include<ros/ros.h>
#include<std_msgs/String.h>
#include<sstream>
#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<string>
#include<task2_cpp/custom.h>
using namespace std;
string pers_ID;

bool getline_async(string& str, char delim = '\n') {

    static std::string lineSoFar;
    char inChar;
    int charsRead = 0;
    bool lineRead = false;
    str = "";

    do {
        charsRead =cin.readsome(&inChar, 1);
        if (charsRead >= 1) {
            // if the delimiter is read then return the string so far
            if (inChar == delim) {
                str = lineSoFar;
                lineSoFar = "";
                lineRead = true;
            } else {  // otherwise add it to the string so far
                lineSoFar.append(1, inChar);
            }
        }
    } while (charsRead !=0 && !lineRead);

    return lineRead;
}
void cb(const task2_cpp::custom::ConstPtr& ptr){
if(ptr->name != pers_ID)
cout<<(ptr->name.c_str())<<":"<<(ptr->data.c_str())<<endl;
}

int main(int argc, char **argv)
{
ios_base::sync_with_stdio(false);
cout<<"Enter username:";
getline(cin,pers_ID);
ros::init(argc,argv,pers_ID+"Publisher");
ros::NodeHandle nh;
ros::Publisher pub = nh.advertise<task2_cpp::custom>("data",1000);
ros::Rate loop_rate(10);
//cout<<"Node has been initialised\n";

//ros::init(argc,argv,pers_ID+"Subscriber");
ros::Subscriber sub = nh.subscribe("data",1000,cb);
//ros::spin();
//cout<<"-->";
while(ros::ok())
{
task2_cpp::custom msg;
string message;
bool k=getline_async(message);
if (k == true){
//cout<<"-->";
//cout<<"\" "<<message<<" \""<<" will be sent\n";
msg.name=pers_ID;
msg.data = message;
pub.publish(msg);
}
ros::spinOnce();
loop_rate.sleep();
}
return 0;
}
