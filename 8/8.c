/*
============================================================================
Name : 8.c
Author : sumit singh
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 10 september, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd_read = open("8.txt",O_RDONLY);
	if(fd_read == -1)
	{
		printf("File doesn't exist\n");
		return 0;
	}

	while(1)
	{
		char ch;
		int read_data = read(fd_read,&ch,1);
		if(read_data == 0)
			break;
		if(ch == "\n")
			printf("\n");
	}
	int fd_close = close(fd_read);
	return 0;
}
