/*
============================================================================
Name : 17b.c
Author : Chirag Date 
Description : Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
  
  int pipeFd[2];
  int status;
  int childPId;
  
  status = pipe(pipeFd);
  
  if(status == -1){
    perror("Error while creating pipe\n");
  }
  else{
    
    childPId = fork();
    if(childPId < 0){
      perror("Error while creating child process\n");
    }
    else if(childPId == 0){
      
      close(STDIN_FILENO);
      dup2(pipeFd[0],STDIN_FILENO);
      close(pipeFd[1]);
      execl("/usr/bin/wc","wc",NULL);
      
    }
    else{
      
      close(STDOUT_FILENO);  
      dup2(pipeFd[1],STDOUT_FILENO);
      close(pipeFd[0]);
      execl("/bin/ls","ls","-l",NULL);
      
    }
  }
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 17b.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
     64     569    3887

============================================================================
*/

