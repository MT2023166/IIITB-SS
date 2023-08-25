#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
  int fd;
  int i = 12345;
  fd = open("ticket.txt", O_WRONLY);
  if (fd < 0) {
    perror("open");
    exit(1);
  }
  write(fd, &i, sizeof(int));
  close(fd);

  return 0;
}
