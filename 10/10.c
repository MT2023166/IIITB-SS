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
