#include<stdio.h>
#include<unistd.h>

int main()
{
	char buf[1024];
	read(0,&buf,sizeof(buf));
	write(1,&buf,sizeof(buf));
	return 0;
}
