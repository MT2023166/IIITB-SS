/*
============================================================================
Name : 5.c
Author : sumit singh
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 10 september, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2,fd3,fd4,fd5; 
	fd1 = creat("1.txt",0777);
	fd2 = creat("2.txt",0777);
	fd3 = creat("3.txt",0777);
	fd4 = creat("4.txt",0777);
	fd5 = creat("5.txt",0777);

	while(1)
	{}

	return 0;
}
