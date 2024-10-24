/*
============================================================================
Name : 23.c
Author : Chirag Date 
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 19th Sept, 2024.
============================================================================
*/

#include <sys/types.h> 
#include <sys/stat.h>   
#include <unistd.h>    
#include <stdio.h> 

void main(){
  
  int status;
  long maxFiles;
  long sizeOfPipe;
  
  char *fifoName = "23fifo";
  
  status = mkfifo(fifoName,S_IRWXU);
  
  if(status == -1){
    perror("Error while creating fifo file\n");
  }
  else{
    maxFiles = sysconf(_SC_OPEN_MAX);
    
    if(maxFiles == -1){
      perror("Error while getting max files from sysconf\n");
    }
    else{
      printf("Maximum number of files that can be opened %ld\n",maxFiles);
    }
    
    sizeOfPipe = pathconf(fifoName,_PC_PIPE_BUF);
    
    if(sizeOfPipe == -1){
      perror("Error while getting max size of pipe from pathconfig\n");
    }
    else{
      printf("Maximum size of pipe: %ld\n",maxFiles);
    }
    
  }
  
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 23.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Maximum number of files that can be opened 1024
Maximum size of pipe: 1024

============================================================================
*/

