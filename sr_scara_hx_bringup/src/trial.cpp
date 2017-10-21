#include <ros/ros.h>
#include <iostream>
#include <vector>
#include <control_msgs/FollowJointTrajectoryActionGoal.h>

using namespace std;

vector<control_msgs::FollowJointTrajectoryActionGoal::ConstPtr> trajectories;

void chatterCallback(const control_msgs::FollowJointTrajectoryActionGoal::ConstPtr& msg)
{
  ROS_INFO("callback: Trajectory received");
  trajectories.push_back(msg);
}

int main(int argc, char **argv)
{

ros::init(argc, argv, "listener");

ros::NodeHandle n;

ros::Subscriber sub = n.subscribe("/sr_scara_hx/sr_scara_hx_joint_controller/follow_joint_trajectory/goal",1000, chatterCallback);

ros::spin();

return 0;

}
