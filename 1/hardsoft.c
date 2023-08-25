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
