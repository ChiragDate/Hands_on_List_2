/*
============================================================================
Name : 8b.c
Author : Chirag Date 
Description : Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
Date: 9th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int sig){
  printf("Caught signal %d: SIGINT . Exiting... \n",sig);
  exit(1);
}

int main(){
  
  signal(SIGINT,signal_handler);

  printf("Program is running. Press CTRL + C to trigger signal \n");
  
  while(1);
  
  return 0;
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 8b.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Program is running. Press CTRL + C to trigger signal 
^CCaught signal 2: SIGINT . Exiting... 

============================================================================
*/

