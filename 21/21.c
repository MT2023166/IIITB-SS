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
