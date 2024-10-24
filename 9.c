/*
============================================================================
Name : 9.c
Author : Chirag Date 
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 9th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>


void signal_handler(int sig){
  
  printf("SIGINT ignored \n");
}

void main(){

  signal(SIGINT,SIG_IGN);
  printf("SIGINT will now be ignored\n"); 

  sleep(5); //for 5 second sigint wont have effect

  signal(SIGINT,SIG_DFL);
  printf("\n");
  printf("SIGINT reset to default\n");
  
  while(1){
    sleep(1);
  }
  
  
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 9.c -o 9.out
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./9.out
SIGINT will now be ignored
^C
^C
^C
^C

SIGINT reset to default
^C




============================================================================
*/

