/*
============================================================================
Name : 9.c
Author : sumit singh
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modificati
Date: 10 september, 2023.
============================================================================
*/
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

void sfile(char const fileName[]);
char *formatdata(char * str , time_t val);
int main()
{
	ssize_t read;
	char* buffer = 0;
	size_t buf_size = 0;

	printf("name of a file: \n");
	read = getline(&buffer,&buf_size,stdin);

	if(read <=0 ){
		printf("getline failed\n");
		exit(1);
	}

	if(buffer[read-1] == '\n'){
		buffer[read-1] = 0;
	}

	int s = open(buffer,O_RDONLY);
	if(s==-1){
		printf("File doesn't exist\n");
		exit(1);
	}
	else
	{
		sfile(buffer);
	}
	free(buffer);
	return 0;


}

char * formatdata(char *str, time_t val){
	strftime(str,36,"%d.%m.%Y %H:%M:%S",localtime(&val));
	return str;
}

void sfile(char const fileName[]){
	struct stat sfile;
	if(stat(fileName,&sfile)==-1){
		printf("Error Occured\n");
	}

	char date[36];
	printf("\nFile inode number : %d",sfile.st_ino);
	printf("\nNumber of hard links: %d",(unsigned int)sfile.st_nlink);
	printf("\nUser ID : %d",sfile.st_uid);
	printf("\nGoup ID : %d",sfile.st_gid);
	printf("\nSize : %d",sfile.st_size);
	printf("\nBlock size : %d",sfile.st_blksize);
	printf("\nNumber of blocks : %d",sfile.st_blocks);
	printf("\nTime of last modification : %s",formatdata(date,sfile.st_ctime)); 
	printf("\nTime of last change : %s",formatdata(date,sfile.st_mtime));
	printf("\n");
}
