/*
============================================================================
Name : 16.c
Author : Sumit singh
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication
Date: 8 Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
int fd1[2],fd2[2],n,m;
char buffer[100];
pid_t p;
pipe(fd1);
pipe(fd2);
p=fork();

if(p>0){//parent process
	close(fd1[0]);
	close(fd2[1]);
	printf("passing value to chlid--> pipe1\n");
	write(fd1[1],"hello my chlid\n", 15);
	m=read(fd2[0],buffer,100);
	write(1,buffer,m);
	wait(NULL);
}
else{
close(fd1[1]);
close(fd2[0]);
n=read(fd1[0],buffer,n);
write(1,buffer,n);
printf("passing value to parent -->pipe2\n");
write(fd2[1],"hello my parent\n",15);
wait(NULL);
}


// 	pid_t pid;
//     int r;
//     char *ch=NULL;
//     char *ch1=NULL;
//     int pc[2];
//     int cp[2];
    
//     pipe(pc);
//     pipe(cp);
      

//     pid=fork();
    

//     if(pid==0)
//     { //CHILD PROCESS
//             close(pc[1]);               //parent can't send the data to the parent
//             close(cp[0]);               //child can't read the data 
//             ch1="CHILD IS SENDING";
//             write(cp[1],ch1,sizeof(ch1));
//             read(pc[0],ch,sizeof(ch));
//             printf("\n CHILD READ = %s",ch);
//             wait(NULL);
            
//     }
//     else
//     { //PARENT PROCESS
//             close(pc[0]);
//             close(cp[1]);
//             ch="HI!! YOU THERE";
//             write(pc[1],ch,sizeof(ch));
            
//             read(cp[0],ch1,sizeof(ch1));
//             printf("\nPARENT READ %s",ch1);
//             wait(NULL);
            
//     }
    return 0;


return 0;
}
