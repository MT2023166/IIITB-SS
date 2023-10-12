/*
============================================================================
Name : hardsoft.c
Author : sumit singh
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 10 september, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int soft_link(const char* f1, const char* f2) {
  return symlink(f1, f2);
}

int hard_link(const char* f1, const char* f2) {
  return link(f1, f2);
}

void main() {
  const char* f1="new.txt";
  const char* f2="symlink.txt";
  printf("Softlink = %d\n", soft_link(f1, f2));
  const char* f3="hardlink.txt";
  printf("Hardlink = %d\n", hard_link(f1, f3));
}
