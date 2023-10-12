/*
============================================================================
Name : 15.c
Author : Sumit singh
Description : Write a simple program to send some data from parent to the child process.
Date: 8 Oct, 2023.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
      int fd[2];
      char *wbuff="parent write this data";
      char *rbuff;
      
      pid_t p;
      pipe(fd);
      p=fork();

      if(p>0){//parent process
      printf("passing value to chlid\n");
      
      write(fd[1],&wbuff,sizeof(wbuff));
      }

      else{ //chlid process
            printf("chlid received data\n");
            read(fd[0],&rbuff,sizeof(wbuff));
            

            printf("Data that parents writes\n");
            printf("%s",rbuff);

      }

return 0;

}
