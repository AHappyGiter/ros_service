#include<ros/ros.h>
#include<service_demo/Greeting.h>


int main(int argc,char** argv)
{
	ros::init(argc,argv,"greetings_client");
	ros::NodeHandle nh;
	ros::ServiceClient client=nh.serviceClient<service_demo::Greeting>("greetings");

	service_demo::Greeting srv;
	srv.request.name="Han";
	srv.request.age=20;
	
	if(client.call(srv)){
		ROS_INFO("Feedback from server:%s",srv.response.feedback);
}
	else{
		ROS_ERROR("Failed to call service greetings.");
		return 1;
}
	return 0;
}
