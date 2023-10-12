/*
============================================================================
Name : 24.c
Author : sumit singh
Description : Write a program to create an orphan process.
Date: 10 september, 2023.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int cpid;

	cpid = fork();

	if(cpid!=0)
	{
		printf("Parent PID:%d\n",getpid());
		

		exit(0);

	}
	else
	{
		printf("Child PID: %d\n",getpid());
		sleep(100);
	}

	return 0;
}
