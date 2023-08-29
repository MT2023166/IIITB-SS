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
                printf("ERROR!\n");
        }
       
	char* buff=(char*)calloc(100,sizeof(char));
        read(fd,buff,5);
	printf("%s\n",buff);
	printf("%d\n",SEEK_CUR);
        int seek = lseek(fd,5,SEEK_CUR);
        read(fd,buff,5);
	printf("%s\n",buff);
        return 0;
}
