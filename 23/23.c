/*
============================================================================
Name : 23.c
Author : sumit singh
Description : Write a program to create a Zombie state of the running program.
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

	if(cpid>0)
	{
		printf("Parent is executing\n");
		sleep(30);
	}
	else
	{
		printf("child is executing\n");
		printf("child PID : %d",getpid());
		exit(0);
	}

	return 0;
}
