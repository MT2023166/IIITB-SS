#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main(){
int retval;
char *p;
void *shared_memory;
char buff[100];
int shmid;
shmid=shmget((key_t)1122,1024,0666|IPC_CREAT);
printf("key of shared memory is %d\n", shmid);
shared_memory=shmat(shmid,NULL, SHM_RDONLY);
read(0,buff,100);
strcpy(shared_memory,buff);

printf("process attached at %p\n", shared_memory);
printf("datais recieved shared is %s\n", (char *)shared_memory);
//read(0,buff,100);
//strcpy(shared_memory,buff);

p=(char *)shared_memory;
retval=shmdt(p);
if(retval<0){
printf("error");
return 0;}
retval=shmctl(shmid,IPC_RMID,NULL);
return 0;

}

