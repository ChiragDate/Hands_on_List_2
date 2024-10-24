/*
============================================================================
Name : 24.c
Author : Chirag Date 
Description : Write a program to create a message queue and print the key and message queue id.
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
    key_t queueKey;
    int queueIdentifier;
    
    queueKey = ftok(".", 1);
    
    if(queueKey == -1){
      perror("Error while computing key\n");
      exit(0);
    }
    
    queueIdentifier = msgget(queueKey,IPC_CREAT | IPC_EXCL | 0700);
    
    if(queueIdentifier == -1){
      perror("Error while creating msg queue\n");
      exit(0);
    }

    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n", queueIdentifier);
  
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 24.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Key: 17020263
Message Queue Identifier: 2
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x0103b567 2          chirag-dat 700        0            0           


============================================================================
*/

