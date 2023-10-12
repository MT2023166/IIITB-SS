/*
============================================================================
Name : 15.c
Author : sumit singh
Description : Write a program to display the environmental variable of the user (use environ).
Date: 10 september, 2023.
============================================================================
*/
#include<stdio.h>

extern char **environ;

void main() {
  for(size_t i=0; environ[i]!=NULL; i++)
    printf("%s\n", environ[i]);
}
