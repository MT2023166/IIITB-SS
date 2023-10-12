/*
============================================================================
Name : 14.c
Author : Sumit singh
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor
Date: 8 Oct, 2023.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
      int a[2];  
      char *rbuff; 

      int ps = pipe(a);
      if (ps == -1)  
      { 
            perror("pipe"); 
            exit(1); 
      } 
      char* wbuff = "writing to the pipe";
      // writing a string "code" in pipe 
      int wb = write(a[1], &wbuff, sizeof(wbuff));  
      
      
      // reading pipe now buff is equal to "code" 
      read(a[0], &rbuff, wb); 
      
      // it will print "code" 
      printf("%s", rbuff);  
      return 0;

}
