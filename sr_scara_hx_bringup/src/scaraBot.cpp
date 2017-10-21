#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include "scaraBot.h"
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
*/
using namespace std;
/*
void error(const char *msg) {
    perror(msg);
    exit(1);
}
*/  

int main(int argc, char** argv)
{
    ros::init(argc, argv, "scaraBot");
    ros::NodeHandle nh;
    
    scaraBot robot;
    controller_manager::ControllerManager cm(&robot,nh);
    /*
    int sockfd, newsockfd, portno,varSend;          //Socket file descriptors and port number
    socklen_t clilen; 					            //object clilen of type socklen_t
    char buffer[256]; 					            //buffer array of size 256
    struct sockaddr_in serv_addr, cli_addr; 		//two objects to store client and server address
    //std_msgs::String message;
    //std::stringstream ss;
    //int n;
    
    if (argc < 2) {
     fprintf(stderr,"ERROR, no port provided\n");
     exit(1);
     }
    portno = atoi(argv[1]);
    //cout << "Hello there! This node is listening on port " << portno << " for incoming connections" << endl;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
       error("ERROR opening socket");
    int enable = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
        error("setsockopt(SO_REUSEADDR) failed");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
            sizeof(serv_addr)) < 0)
            error("ERROR on binding");
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd,
              (struct sockaddr *) &cli_addr,
              &clilen);
    if (newsockfd < 0)
       error("ERROR on accept");
    */
    //  ros::AsyncSpinner spinner(1);
    //  spinner.start();
    
    // The Control Loop
    ros::Time last_time = ros::Time::now();
    ros::Rate rate_loop(0.2);
    
    while (ros::ok())
    {
        ros::Time current_time = ros::Time::now();
        ros::Duration elapsed_time = current_time - last_time;
        last_time = current_time;
        //bzero(buffer,256);
        //varSend = read(newsockfd,buffer,255);
        robot.read();
        cm.update(current_time, elapsed_time);
        robot.write();
        //varSend = write(newsockfd,c_output,length());
        rate_loop.sleep();
    }
    
    //  spinner.stop();
    
    return 0;
}
