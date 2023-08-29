#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int fd;
	fd = open("11.txt",O_RDWR|O_APPEND);
	if(fd == -1)
		printf("Error\n");
	write(fd,"This is 11 question of hands1\n",strlen("This is 11 question of hands1\n"));
	int fcntl_dup = fcntl(fd,F_DUPFD);
	write(fcntl_dup,"This is duplicate from fcntl_dup\n",strlen("This is duplicate from fcntl_dup\n"));
	return 0;
}
