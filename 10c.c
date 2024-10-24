/*
============================================================================
Name : 10c.c
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
  printf("Caught signal %d: SIGFPE Floating exception \n",sig);
  exit(0);
}

int main(){
  struct sigaction siga;
  
  siga.sa_handler = signal_handler;
  siga.sa_flags = 0;
  sigemptyset(&siga.sa_mask); // no other signals should block
  
  int val = sigaction(SIGFPE,&siga,NULL);
  if(val == -1){
    perror("Sigaction");
    exit(1);
  }
  printf("Triggering SIGFPE now..\n");
  
  int a = 1;
  int b = 0;
  int res = a/b;
  
  printf("This won't execute\n");
  
  return 0;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 10c.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Triggering SIGFPE now..
Caught signal 8: SIGFPE Floating exception 

============================================================================
*/

