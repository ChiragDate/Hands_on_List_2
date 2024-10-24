/*
============================================================================
Name : 14.c
Author : Chirag Date 
Description :Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(int argc,char *argv[]){

  if(argc !=2){
    perror("Enter data to write in the pipe");
    exit(1);
  }
  int pipefd[2];
  char *writeBuff = argv[1];
  char *readBuff;
  int status;
  int readBytes,writeBytes;
  
  status = pipe(pipefd);
  
  if(status == -1){
    perror("Error while creating pipe\n");
    exit(1);
  }
  else{
    printf("Writing to the pipe\n");
    
    writeBytes = write(pipefd[1],&writeBuff,sizeof(writeBuff));
    if(writeBytes == -1){
      perror("Error while writing to pipe\n");
      exit(1);
    }
    else{
        printf("Now reading from the pipe\n");
        readBytes = read(pipefd[0],&readBuff,writeBytes);
        
        if(readBytes == -1){
          perror("Error while reading from the pipe\n");
          exit(1);
        }
        else{
          printf("Data from pipe : %s\n",readBuff);
        }
    }
    
  }
  
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 14.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out Hello
Writing to the pipe
Now reading from the pipe
Data from pipe : Hello

============================================================================
*/

