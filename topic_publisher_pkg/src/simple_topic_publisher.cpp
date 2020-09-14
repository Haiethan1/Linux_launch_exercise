#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <std_msgs/Int32.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "topic_publisher");
  ros::NodeHandle nh;

  ros::Publisher pub = nh.advertise<std_msgs::Int32>("counter", 1000);
  ros::Publisher pub1 = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
  ros::Rate loop_rate(2);
  geometry_msgs::Twist var;

  std_msgs::Int32 count;
  count.data = 0;

  while (ros::ok()) {
    pub.publish(count);
    ros::spinOnce();
    var.linear.x = 1;
    var.linear.y = .5;
    pub1.publish(var);
    loop_rate.sleep();
    ++count.data;
  }

  return 0;
}