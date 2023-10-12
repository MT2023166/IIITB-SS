/*
============================================================================
Name : 12.c
Author : sumit singh
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 10 september, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
	int fd = open("12.txt",O_RDWR|O_APPEND);
	int flag = fcntl(fd,F_GETFL);
	if(flag==-1)
		exit(1);
	printf("file descriptor flag (F_GETFD) %d\n",flag);
	return 0;
}
