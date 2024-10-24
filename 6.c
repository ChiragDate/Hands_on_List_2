/*
============================================================================
Name : 6.c
Author : Chirag Date 
Description : Write a simple program to create three threads.
Date: 9th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void *func(void *data)
{
    printf("Running in thread: %lu\n", pthread_self());
}

int main(){
  pthread_t thread[3];
  int thread_id[3];
  int i;

  for(i = 0 ; i < 3 ; i++){
    thread_id[i] = i+1;
    int val = pthread_create(&thread[i],NULL,func,&thread_id[i]);
    printf("Thread %d is created\n",thread_id[i]);
    if(val !=0){
    perror("Failed while creating thread \n");
    }
  }
  
  for (i = 0; i < 3; i++) {
      pthread_join(thread[i], NULL);
  }
  
  printf("Threads have completed execution \n");
  
  return 0;
}
 

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 6.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Thread 1 is created
Thread 2 is created
Running in thread: 140532118451904
Thread 3 is created
Running in thread: 140532101666496
Running in thread: 140532110059200
Threads have completed execution 

============================================================================
*/

