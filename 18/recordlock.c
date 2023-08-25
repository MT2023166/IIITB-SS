#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

struct employee{
  int eid;
  char name[20];
  int salary;
};

int main() {
  struct flock lock;
  int fd=open("employee.txt", O_CREAT | O_RDWR, 0744);
  struct employee emp1, emp2, emp3;
  emp1.eid=1;
  emp2.eid=2;
  emp3.eid=3;
  strcpy(emp1.name, "Ram");
  strcpy(emp2.name, "Shyam");
  strcpy(emp3.name, "Ishu");
  emp1.salary=18000;
  emp2.salary=16000;
  emp3.salary=90000;
  write(fd, &emp1, sizeof(struct employee));
  lock.l_type=F_WRLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 8;
  lock.l_len = 8;
  lock.l_pid = getpid();
  fcntl(fd,F_SETLKW , &lock);
  printf("Entered critical section...\n");
  printf("Press return to unlock...\n");
  getchar();
  printf("Write lock unset...\n");
  lock.l_type=F_RDLCK;
  lock.l_start=0;
  lock.l_len=8;
  fcntl(fd, F_SETLKW, &lock);
  printf("Read lock set...\n");
  lock.l_type=F_UNLCK;
  lock.l_start=8;
  lock.l_len=8;
  fcntl(fd, F_SETLKW, &lock);
  printf("Press return to exit...\n");
  getchar();
  printf("Read lock unset...\n");
  close(fd);

  return 0;
}
