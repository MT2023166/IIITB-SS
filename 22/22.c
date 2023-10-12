/*
============================================================================
Name : 22.c
Author : sumit singh
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 10 september, 2023.
============================================================================
*/
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int cpid,fd;
	fd = open("temp.txt",O_RDWR|O_CREAT|O_APPEND,0777);

	cpid = fork();

	if(cpid>0)
	{
		write(fd,"parent is writing",17);
	}
	else
	{
		write(fd,"child is writing",16);
	}
	close(fd);
	return 0;

}

