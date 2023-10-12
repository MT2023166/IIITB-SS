/*
============================================================================
Name : 17.c
Author : sumit singh
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 10 september, 2023.
============================================================================
*/
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
	struct flock wlock;
	
	wlock.l_type = F_UNLCK;
	wlock.l_whence = SEEK_SET;
	wlock.l_start = 0;
	wlock.l_len = 0;
	int fd;

	fd = open("ticket.txt",O_RDWR);
	if(fd<0)
	{
		printf("error");
		exit(1);
	}
	printf("press any key to accquired lock");
	wlock.l_type = F_WRLCK;
	getchar();
	
	int ret = fcntl(fd,F_SETLKW,&wlock);
	if(ret<0)
	{
		printf("error");
		exit(1);
	}
	printf("Inside the critical ");
	char buff;

	read(fd,&buff,sizeof(char));
	printf("Ticket no.%d",(int)buff);
	buff = buff+1;
	lseek(fd,-sizeof(char),SEEK_CUR);
	write(fd,&buff,sizeof(char));
	printf("updated ticket no. %d",(int)buff);
	printf("Press any key to unlock");
	getchar();
	wlock.l_type = F_UNLCK;

	ret = fcntl(fd,F_SETLKW,&wlock);
	if(ret<0)
	{
		printf("Error");
		exit(1);
	}
	close(fd);
	printf("File unlocked");

	

	return 0;
}
