/*
============================================================================
Name : 6.c
Author : sumit singh
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 10 september, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
	char buf[1024];
	read(0,&buf,sizeof(buf));
	write(1,&buf,sizeof(buf));
	return 0;
}
