#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<errno.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/wait.h>

void connection_handler(int sockFD); // Handles the read & write operations to the server
void main()
{
    int socketFileDescriptor, connectStatus;
    struct sockaddr_in serverAddress;
    struct sockaddr server;

    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1)
    {
        perror("Error while creating server socket!");
        _exit(0);
    }

    serverAddress.sin_family = AF_INET;                // IPv4
    serverAddress.sin_port = htons(8081);              // Server will listen to port 8080
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); // Binds the socket to all interfaces

    connectStatus = connect(socketFileDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    if (connectStatus == -1)
    {
        perror("Error while connecting to server!");
        close(socketFileDescriptor);
        _exit(0);
    }
    printf("------------------------Welcome Back to Academia : Course registration------------------------------------");
    connection_handler(socketFileDescriptor);

    close(socketFileDescriptor);
}


// Handles the read & write operations w the server
void connection_handler(int sockFD)
{
    char readBuffer[1000], writeBuffer[1000]; // A buffer used for reading from / writting to the server
    ssize_t readBytes, writeBytes;            // Number of bytes read from / written to the socket

    char tempBuffer[1000];

    bzero(readBuffer, sizeof(readBuffer)); 

    readBytes = read(sockFD, readBuffer, sizeof(readBuffer));
    if(readBytes==-1)
    {
        perror("Error while reading from client socket!");
    }
    printf("%s",readBuffer);
    scanf("%s",writeBuffer);
    writeBytes = write(sockFD,writeBuffer,strlen(writeBuffer));
    for(int i=0;i<4;i++)
    {
        bzero(readBuffer, sizeof(readBuffer)); 
        readBytes = read(sockFD, readBuffer, sizeof(readBuffer));
        printf("%s",readBuffer);
        bzero(writeBuffer, sizeof(writeBuffer)); 
        scanf("%s",writeBuffer);
        writeBytes = write(sockFD,writeBuffer,strlen(writeBuffer));
    }

}