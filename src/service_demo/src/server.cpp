#include<ros/ros.h>
#include<service_demo/Greeting.h>

bool handle_function(service_demo::Greeting::Request &req,service_demo::Greeting::Response &res){
	ROS_INFO("Request from %s with age %d",req.name.c_str(),req.age);
	res.feedback="Hi"+req.name+",I'm server!";
	return true;	
}




int main(int argc,char** argv)
{
	ros::init(argc,argv,"greetings_server");
	ros::NodeHandle nh;
	ros::ServiceServer service=nh.advertiseService("greetings",handle_function);
	ros::spin();
	return 0;
}



