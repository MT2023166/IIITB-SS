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

