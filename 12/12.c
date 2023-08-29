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
