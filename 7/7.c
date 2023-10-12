/*
============================================================================
Name : 7.c
Author : sumit singh
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 10 september, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc , char* argv[]) {
	
	if(argc != 3)
	{
		printf("You are useless");
		return 0;	
	}
	int fd_read = open(argv[1],O_RDONLY);
	int fd_write = open(argv[2],O_WRONLY|O_CREAT);
	if(fd_read == -1 || fd_write == -1)
		printf("Useless\n");

	while(1)
	{
		char buff;
		int char_read = read(fd_read,&buff,sizeof(buff));
		if(char_read == 0)
			break;
		int char_writtern = write(fd_write,&buff,1);
	}
	int fd_read_close = close(fd_read);
	int fd_write_close = close(fd_write);
	if(fd_read_close == -1 || fd_write_close == -1)
		printf("Not able to close");
	return 0;
}
