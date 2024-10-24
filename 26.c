/*
============================================================================
Name : 26.c
Author : Chirag Date 
Description :Write a program to send messages to the message queue. Check `ipcs -q`
Date: 20th Sept, 2024.
============================================================================
*/

#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>    
#include <unistd.h>   

void main()
{
    key_t queueKey;      
    int queueIdentifier;  
    int messageSendStatus; 

    struct msgbuf
    {
        long mtype;    
        int someNumber; 
    } data;

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);

    if (queueIdentifier == -1)
    {
        perror("Error while creating message queue!");
        _exit(0);
    }

    data.mtype = 1;
    data.someNumber = 100;

    messageSendStatus = msgsnd(queueIdentifier, &data, sizeof(data), 0);

    if (messageSendStatus == -1)
    {
        perror("Error while sending message via Message Queue!");
        _exit(0);
    }

    printf("Message sent! Check using `ipcs -q`\n");
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 26.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Message sent! Check using `ipcs -q`
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x0103b567 2          chirag-dat 700        16           1           


============================================================================
*/

