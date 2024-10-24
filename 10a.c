/*
============================================================================
Name : 10a.c
Author : Chirag Date 
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Date: 9th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int sig){
  printf("Caught signal %d: Segmentation fault \n",sig);
  exit(1);
}

int main(){
  struct sigaction sa;
  
  sa.sa_handler = signal_handler;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);
  // no other signals should block
  
  int val = sigaction(SIGSEGV,&sa,NULL);
  if(val == -1){
    perror("Sigaction");
    exit(1);
  }
  
  int *ptr = NULL;
  *ptr = 42;

  
  return 0;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 10a.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Caught signal 11: Segmentation fault 

============================================================================
*/

