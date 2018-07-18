#include "ros/ros.h"
#include "std_msgs/String.h"
#include "message_protocol/info.h"

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{

  ros::init(argc, argv, "emitter_node"); //Inicializa nodo
  ros::NodeHandle node; // Objeto nodo

  // Advertir tipo de mensage
  ros::Publisher chatter_pub = node.advertise<message_protocol::info>("info_topic",0);

  // frecuencia de transmisión 1/s
  ros::Rate loop_rate(1);

  // Se ejecuta hasta recibir Ctrl+C
  int count = 0;
  while (ros::ok())
  {
    message_protocol::info msgToSend; // Inicialización del mensaje a enviar

    msgToSend.xPos = (int64_t)count; // Asignación del mensaje a enviar
    msgToSend.yPos = (int64_t)count+1;
    msgToSend.mat.resize(3);
    msgToSend.mat[0] = count;
    msgToSend.mat[1] = count+2;
    msgToSend.mat[2] = count+1;
    ROS_INFO("Pos %d   %d  ", (int)msgToSend.xPos, (int)msgToSend.yPos);
    ROS_INFO("Mat %d   %d  %d", (int)msgToSend.mat[0], (int)msgToSend.mat[1], (int)msgToSend.mat[2]);
    chatter_pub.publish(msgToSend); // Se envía el mensaje

    ros::spinOnce();

    loop_rate.sleep(); // duerme el nodo por un tiempo
    count++;
  }


  return 0;
}
