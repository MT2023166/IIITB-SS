#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include<errno.h>
#include<sys/wait.h>
#include <unistd.h>
int main(){    
    int a[2];
  pipe(a);
   if(!fork())
    {
           close(2);
             dup(a[1]);
           close(a[0]);
           execlp("ls","ls","-l",NULL);
    }
    else
    {
         close(0);
          dup(a[0]);
           close(a[1]);
           execlp("wc","wc",NULL);
    }
}
