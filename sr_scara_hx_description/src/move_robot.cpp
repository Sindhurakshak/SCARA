#include <ros/ros.h>
#include <string.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "move_robot");
  ros::NodeHandle n;
  ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);
  tf::TransformBroadcaster broadcaster;
  ros::Rate loop_rate(30);



  geometry_msgs::TransformStamped odom_trans;
  sensor_msgs::JointState joint_state;

  double joint_one_angle = 1,joint_two_angle = 1,joint_three_angle = 1,joint_four_angle = 1;
  odom_trans.header.frame_id = "odom";
  odom_trans.child_frame_id = "base_link";

  while (ros::ok()) {
  //update joint_state
  joint_state.header.stamp = ros::Time::now();
  joint_state.name.resize(3);
  joint_state.position.resize(3);
  joint_state.name[0] ="joint1";
  joint_state.position[0] = joint_one_angle;
  //sleep(1);
  joint_state.name[1] ="joint2";
  joint_state.position[1] = joint_two_angle;
  //sleep(1);
  joint_state.name[2] ="joint3";
  joint_state.position[2] = joint_three_angle;
  //sleep(1);
  //joint_state.name[3] ="gripper_con";
  //joint_state.position[3] = joint_four_angle;

  joint_pub.publish(joint_state);
  broadcaster.sendTransform(odom_trans);

  joint_one_angle = joint_one_angle + 1;
  joint_two_angle = joint_two_angle + 1;
  joint_three_angle = joint_three_angle + 1;
  joint_four_angle = joint_four_angle + 1;
  sleep(5);
  loop_rate.sleep();
  }

  return 0;

}
