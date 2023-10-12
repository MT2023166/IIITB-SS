/*
============================================================================
Name : 25.c
Author : sumit singh
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 10 september, 2023.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
	int c1,c2,c3;
	int exch;
	int waitstatus;

	if((c1=fork())==0)
	{
		printf("child 1 is created");
		exit(0);
	}
	else
	{
		if((c2=fork())==0)
		{
			printf("child 2 is created");
			exit(0);
		}
		else
		{
			if((c3=fork())==0)
			{
				printf("child 3 is created");
				exit(0);
			}
			else
			{
				exch = waitpid(c3,&waitstatus,0);

				if(exch == c3)
				{
					if(waitstatus==0)
					{
						printf("child 3 has terminated with exit status =0\n");
					}
					else
					{
						printf("child 3 has exited with exit status = %d\n",waitstatus);
					}
				}
			}
		}
	}

	return 0;
}

