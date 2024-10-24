/*
============================================================================
Name : 11.c
Author : Chirag Date 
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 9th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>


void ignore(int sig){

}

void reset_signal(int sig){
  printf("Caught signal %d: SIGINT interrupt signal \n",sig);
  
  struct sigaction siga;
  siga.sa_handler = SIG_DFL;
  siga.sa_flags = 0;
  sigemptyset(&siga.sa_mask);
  
  int val = sigaction(SIGINT,&siga,NULL);
  
  if(val == -1){
    perror("Sigaction");
    exit(1);
  }
  
  exit(0);
  
}

int main(){

  struct sigaction si;
  
  si.sa_handler = ignore;
  si.sa_flags = 0;
  sigemptyset(&si.sa_mask);
  
  int val = sigaction(SIGINT,&si,NULL);
  
  if(val == -1){
    perror("Sigaction");
    exit(1);
  }
  
  printf("SIGINT is ignored. Press CTRL + C to test\n");
  
  while(1){
    sleep(2);
    static int count = 0;
    count++;
    
    if(count == 5){
      printf("Changing back to default handler\n");
      si.sa_handler = reset_signal;
      val = sigaction(SIGINT,&si,NULL);
      if(val == -1){
        perror("Sigaction");
        exit(1);
      }
    }
    
  }
  
  return 0;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 11.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
SIGINT is ignored. Press CTRL + C to test
^C
^C
^C
^C
^CChanging back to default handler
^CCaught signal 2: SIGINT interrupt signal 

============================================================================
*/

