#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
int res,n;
res=open("fifo1",O_WRONLY);
write(res,"murli sending the message", 26);
printf("sender pid is %d\n",getpid());
}
