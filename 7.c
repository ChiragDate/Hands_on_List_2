/*
============================================================================
Name : 7.c
Author : Chirag Date 
Description : Write a simple program to print the created thread ids.
Date: 9th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>

void* func(){
  printf("Running in thread with thread ID %lu \n",pthread_self());
}

void main(){
  
  pthread_t id;
  
  
  for(int i=0;i<3;i++){
  
    int val = pthread_create(&id,NULL,func,NULL);
  
    if(val != 0){
      perror("Error while creating thread \n");
    }  
    pthread_exit(NULL);
  }

}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 7.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Running in thread with thread ID 140262032537280 


============================================================================
*/

