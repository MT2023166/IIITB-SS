/*
============================================================================
Name : 3.c
Author : sumit singh
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 10 september, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd;
	fd = creat("3.txt",0777);
	printf("File Descriptor Value : %d.\n",fd);
	return 0;	
}
