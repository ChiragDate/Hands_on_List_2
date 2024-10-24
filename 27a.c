/*
============================================================================
Name : 27a.c
Author : Chirag Date 
Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date: 20th Sept, 2024.
============================================================================
*/


#include<stdio.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/msg.h>
#include<stdlib.h>

void main(){
    struct msg {
      long int m_type;
      char message[80];
    } myq;
    
    int key = ftok(".", 'a');
    int mqid = msgget(key, 0);
    //int mqid = 1;
    
    printf("Enter message type: ");
    scanf("%ld", &myq.m_type);
    
    int ret = msgrcv(mqid, &myq, sizeof(myq), myq.m_type, 0);
    
    printf("Message type: %ld\n", myq.m_type);
    printf("Message: %s\n", myq.message);
    
    return;
}

/*
============================================================================

============================================================================
*/

