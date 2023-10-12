/*
============================================================================
Name : 29.c
Author : sumit singh
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 10 september, 2023.
============================================================================
*/
#include<sched.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	int currsched;
	int pid;
	pid = getpid();
	currsched = sched_getscheduler(pid);

	struct sched_param sched;
	
	switch(currsched)
	{
		case SCHED_FIFO:
			printf("current policy is FIFO\n");
			sched_setscheduler(pid,SCHED_RR,&sched);
			currsched = sched_getscheduler(pid);
			printf("current policy is%d\n",currsched);
			break;
		case SCHED_RR:
			printf("current policy is RR\n");
			sched_setscheduler(pid,SCHED_FIFO,&sched);
			currsched = sched_getscheduler(pid);
			printf("current policy is%d\n",currsched);
			break;
		case SCHED_OTHER:
			printf("current policy is OTHER\n");
			sched_setscheduler(pid,SCHED_RR,&sched);
			currsched = sched_getscheduler(pid);
			printf("current policy is%d\n",currsched);
			break;
		default:
		        perror("Error while getting current policy\n");
		        
	  }
          return 0;
}
			

				
