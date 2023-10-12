/*
============================================================================
Name : 20.c
Author : sumit singh
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 10 september, 2023.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/resource.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int pr,npr;
	if(argc!=2)
	{
		printf("please pass the correct no.of argument");
	}
	else
	{
		npr = atoi(argv[1]);
		pr = getpriority(PRIO_PROCESS,getpid());
		printf("Current priority %d",pr);

		pr = nice(npr);

		printf("New priority %d",pr);
	}

	return 0;

}

			


