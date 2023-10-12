/*
============================================================================
Name : 14.c
Author : sumit singh
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 10 september, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
	if(argc !=2){
		printf("usage: %s <filename>\n", argv[0]);
		return 1;
	}

	const char* file_name=argv[1];

	struct stat file_stat;
	if(stat(file_name, &file_stat)==-1){
		perror("ERROR No Information available");
		return 1;
	}

	if(S_ISREG(file_stat.st_mode)){
		printf("%s is a regular file. \n", file_name);
	}
	else if (S_ISDIR(file_stat.st_mode)){
		printf("%s is a directory.\n", file_name);
	}
	else if(S_ISLNK(file_stat.st_mode)){
		printf("%s is a symbolic link.\n", file_name);
	}
	else if(S_ISFIFO(file_stat.st_mode)){
		printf("%s is a FIFO/pipe.\n", file_name);
	}
	else if(S_ISSOCK(file_stat.st_mode)){
		printf("%s is a socket.\n", file_name);
	}
	else if(S_ISBLK(file_stat.st_mode)){
		printf("%s is a block special file.\n" , file_name);
	}
	else if(S_ISCHR(file_stat.st_mode)){
		printf("%s is a charcter special file.\n" , file_name);
	}
	else{
		printf("%s is of an unknown type.\n" , file_name);
	}
	return 0;
}
