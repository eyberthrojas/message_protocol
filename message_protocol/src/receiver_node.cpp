#include "ros/ros.h"
#include "std_msgs/String.h"
#include "message_protocol/info.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const message_protocol::info::ConstPtr& msg)
{
  int x = (int)msg->xPos;
  int y = (int)msg->yPos;
  int mat[3];
  ROS_INFO("Pos Recibida:  x = [%d]  y = [%d]", x, y);
  for (int j = 0; j < 3; j++)
     mat[j] = msg->mat[j];
  ROS_INFO("Mat Recibida: [%d %d %d]", mat[0], mat[1], mat[2]);
}

int main(int argc, char **argv)
{
  // Inicializa nodo receptor
  ros::init(argc, argv, "receiver_node");

  ros::NodeHandle node; // Objeto Nodo

  // se suscribe el nodo al topic
  ros::Subscriber sub = node.subscribe("info_topic", 0, chatterCallback);

  //Loop infinito
  ros::spin();

  return 0;
}

