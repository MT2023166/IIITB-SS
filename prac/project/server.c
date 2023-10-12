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
#include<stdlib.h>
#include <fcntl.h>     
//#define INITIAL_PROMPT "{1.Admin ,2.Professor,3.Student}"


#include "structure.h"
#include "constant.h"
void connection_handler(int connFD); // Handles the communication with the client
void addStudent(int connFD);
void addFaculty(int connFD);

void main(){

	int socketFileDescriptor, socketBindStatus, socketListenStatus, connectionFileDescriptor;
    struct sockaddr_in serverAddress, clientAddress;

    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1)
    {
        perror("Error while creating server socket!");
        _exit(0);
    }

    serverAddress.sin_family = AF_INET;                // IPv4
    serverAddress.sin_port = htons(8081);              // Server will listen to port 8080
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); // Binds the socket to all interfaces

    socketBindStatus = bind(socketFileDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    if (socketBindStatus == -1)
    {
        perror("Error while binding to server socket!");
        _exit(0);
    }

    socketListenStatus = listen(socketFileDescriptor, 10);
    if (socketListenStatus == -1)
    {
        perror("Error while listening for connections on the server socket!");
        close(socketFileDescriptor);
        _exit(0);
    }

    int clientSize;
    while (1)
    {
        clientSize = (int)sizeof(clientAddress);
        connectionFileDescriptor = accept(socketFileDescriptor, (struct sockaddr *)&clientAddress, &clientSize);
        if (connectionFileDescriptor == -1)
        {
            perror("Error while connecting to client!");
            close(socketFileDescriptor);
        }
        else
        {
            if (!fork())
            {
                // Child will enter this branch
                connection_handler(connectionFileDescriptor);
                close(connectionFileDescriptor);
                _exit(0);
            }
        }
    }

    close(socketFileDescriptor);
}

void connection_handler(int connectionFileDescriptor)
{
    printf("Client has connected to the server!\n");

    char readBuffer[1000], writeBuffer[1000];
    ssize_t readBytes, writeBytes;
    int userChoice;

    // char *cred = "{1.Admin ,2.Professor,3.Student}";
    writeBytes = write(connectionFileDescriptor, INITIAL_PROMPT, strlen(INITIAL_PROMPT));
    if (writeBytes == -1)
        perror("Error while sending first prompt to the user!");
    else
    {
         bzero(readBuffer, sizeof(readBuffer));
        readBytes = read(connectionFileDescriptor, readBuffer, sizeof(readBuffer));
        if (readBytes == -1)
            perror("Error while reading from client");
        else if (readBytes == 0)
            printf("No data was sent by the client");
        else
        {
            userChoice = atoi(readBuffer);
            switch (userChoice)
            {
            case 1:
                // Admin
                //admin_function(connectionFileDescriptor);
                addStudent(connectionFileDescriptor);
                // addFaculty(connectionFileDescriptor);
                printf("%s",readBuffer);
                break;
            case 2:
                // Professor
                // faculty_function(connectionFileDescriptor);
                printf("%s",readBuffer);
                break;
            case 3:
                //Student
                //student_function(connectionFileDescriptor);
                // Exit
            default:
                //Exit
                break;
            }
        }
    }

     printf("Terminating connection to client!\n");
}

void addStudent(int connectionfd)
{
    struct Student std ;
    char readBuffer[1000], writeBuffer[1000];
    ssize_t readBytes, writeBytes;

    writeBytes = write(connectionfd,ADMIN_ADD_NAME,strlen(ADMIN_ADD_NAME));

    if (writeBytes == -1)
    {
        perror("Error writing ADMIN_ADD_NAME message to client!");
        
    }
    bzero(readBuffer, sizeof(readBuffer));
    readBytes = read(connectionfd,readBuffer,sizeof(readBuffer));

    if (readBytes == -1)
    {
        perror("Error reading Student name response from client!");
        
    }

    strcpy(std.name, readBuffer);



    writeBytes = write(connectionfd,ADMIN_ADD_ROLL,strlen(ADMIN_ADD_ROLL));
    if (writeBytes == -1)
    {
        perror("Error writing ADMIN_ADD_ROLL message to client!");
        
    }
    bzero(readBuffer, sizeof(readBuffer));
    readBytes = read(connectionfd,readBuffer,sizeof(readBuffer));

    if (readBytes == -1)
    {
        perror("Error reading Student ROLL response from client!");
        
    }

    strcpy(std.rollno, readBuffer);


    writeBytes = write(connectionfd,ADMIN_ADD_EMAIL,strlen(ADMIN_ADD_EMAIL));
    if (writeBytes == -1)
    {
        perror("Error writing ADMIN_ADD_EMAIL message to client!");
        
    }
    bzero(readBuffer, sizeof(readBuffer));
    readBytes = read(connectionfd,readBuffer,sizeof(readBuffer));

    if (readBytes == -1)
    {
        perror("Error reading Student EMAIL ID response from client!");
        
    }

    strcpy(std.emailId, readBuffer);


    writeBytes = write(connectionfd,ADMIN_ADD_PASS,strlen(ADMIN_ADD_PASS));
    if (writeBytes == -1)
    {
        perror("Error writing ADMIN_ADD_PASS message to client!");
        
    }
    bzero(readBuffer, sizeof(readBuffer));
    readBytes = read(connectionfd,readBuffer,sizeof(readBuffer));

    if (readBytes == -1)
    {
        perror("Error reading Student PASS response from client!");
        
    }

    strcpy(std.password, readBuffer);


   ///
   writeBytes = write(connectionfd,ADMIN_ADD_STATUS,strlen(ADMIN_ADD_STATUS));
    if (writeBytes == -1)
    {
        perror("Error writing ADMIN_ADD_STATUS message to client!");
        
    }
    bzero(readBuffer, sizeof(readBuffer));
    readBytes = read(connectionfd,readBuffer,sizeof(readBuffer));

    if (readBytes == -1)
    {
        perror("Error reading Student STATUS response from client!");
        
    }

    std.status, atoi(readBuffer);


    ///File handling

    int studentfd = open("students.txt", O_CREAT | O_APPEND | O_WRONLY,0777);

    if (studentfd== -1)
    {
        perror("Error while creating / opening student file!");
        
    }
    writeBytes = write(studentfd, &std, sizeof(std));
    if (writeBytes == -1)
    {
        perror("Error while writing Student record to file!");
        
    }

    close(studentfd);
    
}


void addFaculty(int connectionfd)
{
    struct Faculty fac;
    char readBuffer[1000], writeBuffer[1000];
    ssize_t readBytes, writeBytes;

    writeBytes = write(connectionfd,ADMIN_FADD_NAME,strlen(ADMIN_FADD_NAME));

    if (writeBytes == -1)
    {
        perror("Error writing ADMIN_FADD_NAME message to client!");
        
    }
    bzero(readBuffer, sizeof(readBuffer));
    readBytes = read(connectionfd,readBuffer,sizeof(readBuffer));

    if (readBytes == -1)
    {
        perror("Error reading FACULTY name response from client!");
        
    }

    strcpy(fac.name, readBuffer);



    writeBytes = write(connectionfd,ADMIN_FADD_UID,strlen(ADMIN_FADD_UID));
    if (writeBytes == -1)
    {
        perror("Error writing ADMIN_FADD_UID message to client!");
        
    }
    bzero(readBuffer, sizeof(readBuffer));
    readBytes = read(connectionfd,readBuffer,sizeof(readBuffer));

    if (readBytes == -1)
    {
        perror("Error reading FACULTY UID response from client!");
        
    }

    strcpy(fac.facultyUID, readBuffer);


    writeBytes = write(connectionfd,ADMIN_FADD_EMAIL,strlen(ADMIN_FADD_EMAIL));
    if (writeBytes == -1)
    {
        perror("Error writing ADMIN_FADD_EMAIL message to client!");
        
    }
    bzero(readBuffer, sizeof(readBuffer));
    readBytes = read(connectionfd,readBuffer,sizeof(readBuffer));

    if (readBytes == -1)
    {
        perror("Error reading FACULTY EMAIL ID response from client!");
        
    }

    strcpy(fac.emailId, readBuffer);


    writeBytes = write(connectionfd,ADMIN_FADD_PASS,strlen(ADMIN_FADD_PASS));
    if (writeBytes == -1)
    {
        perror("Error writing ADMIN_FADD_PASS message to client!");
        
    }
    bzero(readBuffer, sizeof(readBuffer));
    readBytes = read(connectionfd,readBuffer,sizeof(readBuffer));

    if (readBytes == -1)
    {
        perror("Error reading FACULTY PASS response from client!");
        
    }

    strcpy(fac.password, readBuffer);


   ///
   


    ///File handling

    int facultyfd = open("faculty.txt", O_CREAT | O_APPEND | O_WRONLY);

    if (facultyfd== -1)
    {
        perror("Error while creating / opening FACULTY file!");
        
    }
    writeBytes = write(facultyfd, &fac, sizeof(fac));
    if (writeBytes == -1)
    {
        perror("Error while writing FACULTY record to file!");
        
    }

    close(facultyfd);
}
