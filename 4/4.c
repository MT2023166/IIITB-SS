#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd;
	fd = open("4.txt",O_CREAT|O_EXCL,0777);
	printf("File descriptor: %d\n",fd);
	if(fd == -1)
		printf("File not exist\n");
	else
		printf("File exist\n");
}
