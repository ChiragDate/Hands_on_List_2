/*
============================================================================
Name : 8e.c
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
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int sig){
  printf("Time expired\n");
}

void main(){
  struct itimerval time;
  
  signal(SIGALRM,signal_handler); // when timer expire signal_handler will be called
  
  time.it_value.tv_sec = 10;
  time.it_value.tv_usec = 0;
  
  time.it_interval.tv_sec = 0; // interval of recurrent timers. 0 means not repeat 
  time.it_interval.tv_sec = 0;
  
  int val = setitimer(ITIMER_REAL,&time,NULL);
  // when setitimer expires kernel signs a SIGALRM to process.
  
  if(val == -1){
    perror("Error while setting timer for 10 seconds\n");
    _exit(1);
  }
  
  pause(); //waiting for the timer to expire and trigger the SIGALRM signal
  
  // after first timer expires next timer is set
  time.it_value.tv_sec = 0;
  time.it_value.tv_usec = 10;
  
  time.it_interval.tv_sec = 0;
  time.it_interval.tv_sec = 0;
  
  int val2 = setitimer(ITIMER_REAL,&time,NULL);
  
  if(val2 == -1){
    perror("Error while setting timer for 10 seconds\n");
    _exit(1);
  }
  
  pause(); 
  
  _exit(0);
  
  
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 8e.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Time expired
Time expired


============================================================================
*/

