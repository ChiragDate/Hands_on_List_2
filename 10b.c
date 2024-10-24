/*
============================================================================
Name : 10b.c
Author : Chirag Date 
Description :Write a separate program using sigaction system call to catch the following signals.
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
  printf("Caught signal %d: SIGINT interrupt signal \n",sig);
  
}

int main(){
  struct sigaction siga;
  
  siga.sa_handler = signal_handler;
  siga.sa_flags = 0;
  sigemptyset(&siga.sa_mask); // no other signals should block
  
  int val = sigaction(SIGINT,&siga,NULL);
  if(val == -1){
    perror("Sigaction");
    exit(1);
  }
  printf("Press CTRL+C to trigger SIGINT\n");
  
  pause();
  
  return 0;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 10b.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Press CTRL+C to trigger SIGINT
^CCaught signal 2: SIGINT interrupt signal 

============================================================================
*/

