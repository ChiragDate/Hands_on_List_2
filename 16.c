/*
============================================================================
Name : 16.c
Author : Chirag Date 
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>

int main(int argc,char argv[]){

  int childToParentFd[2],parentToChildFd[2];
  int cpstatus,pcstatus;
  int readBytes,writeBytes;
  char parentMessage[100] = "Hi Child from parent"; // Buffer for parent's message (fixed size)
  char childMessage[100] = "Hello parent from child"; // Child's message
  char readBuff[100];
  int childPid;
  
  cpstatus = pipe(childToParentFd);
  pcstatus = pipe(parentToChildFd);
  
  if(cpstatus == -1 || pcstatus == -1){
    perror("Error while creating pipe\n");
  }
  else{
    childPid = fork();
    
    if(childPid == -1){
      perror("Error while creating child process\n");
    }
    else if(childPid == 0){
      close(parentToChildFd[1]); //closing write end to parent
      close(childToParentFd[0]); //closing read end to child
      
      writeBytes = write(childToParentFd[1],childMessage,sizeof(childMessage));
      if(writeBytes == -1){
        perror("Error while writing from child to parent pipe\n");
        exit(1);
      }
      
      readBytes = read(parentToChildFd[0],readBuff,sizeof(readBuff));
      if(readBytes == -1){
        perror("Error while reading from parent to child pipe\n");
        exit(1);
      }
      else{
        printf("The parent said :- %s\n",readBuff);
      }
      
        close(parentToChildFd[0]);
        close(childToParentFd[1]);
      
    }
    else{
      close(parentToChildFd[0]);
      close(childToParentFd[1]);
      
      writeBytes = write(parentToChildFd[1],parentMessage,sizeof(parentMessage));
      if(writeBytes == -1){
        perror("Error while writing to parent to child pipe \n");
        exit(1);
      }
      
      readBytes = read(childToParentFd[0],readBuff,sizeof(readBuff));
      if(readBytes == -1){
        perror("Error while reading from child to parent pipe\n");
        exit(1);
      }
      else{
        printf("The child said :- %s\n",readBuff);
      }
      
        close(parentToChildFd[1]);
        close(childToParentFd[0]);
      
    
    }
  
  }

  
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 16.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
The parent said :- Hi Child from parent
The child said :- Hello parent from child

============================================================================
*/

