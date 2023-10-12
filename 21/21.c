/*
============================================================================
Name : 21.c
Author : sumit singh
Description : Write a program, call fork and print the parent and child process id.
Date: 10 september, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
	int cpid;

	printf("Parent PID %d\n",getpid());

	cpid = fork();

	if(cpid!=0)
	{
		printf("Child PID :%d",cpid);
	}

	return 0;
}
