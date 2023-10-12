/*
============================================================================
Name : 11.c
Author : sumit singh
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 10 september, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int fd;
	fd = open("11.txt",O_RDWR|O_APPEND);
	if(fd == -1)
		printf("Error\n");
	write(fd,"This is 11 question of hands1\n",strlen("This is 11 question of hands1\n"));
	int fcntl_dup = fcntl(fd,F_DUPFD);
	write(fcntl_dup,"This is duplicate from fcntl_dup\n",strlen("This is duplicate from fcntl_dup\n"));
	return 0;
}
