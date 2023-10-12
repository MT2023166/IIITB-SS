/*
============================================================================
Name : 10.c
Author : sumit singh
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data
Date: 10 september, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd;
	fd = open("10.txt",O_RDWR);
	if(fd == -1)
	{
		printf("File doesn't exist!!\n");
	}
	int w;
	write(fd,"abcdefghij",strlen("abcdefghij"));
	int seek = lseek(fd,10,SEEK_CUR);
	write(fd,"klmnopqrst",strlen("klmnopqrst"));

	printf("\nPointer after lseek : %d\n",seek);
	system("od -c 10101010101010101010.txt");
	return 0;
}
