/*
============================================================================
Name : 8c.c
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
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int sig){
  printf("Caught signal %d: SIGFPE. Division by zero \n",sig);
  exit(1);
}

int main(){
  
  signal(SIGFPE,signal_handler);

  printf("Program running...\n");
  
  int x = 14;
  int y = 0;
  int z = x/y;
  
  printf("Result z : %d\n",z);
  return 0;
}
/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 8c.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Program running...
Caught signal 8: SIGFPE. Division by zero 

============================================================================
*/

