/*
============================================================================
Name : 25.c
Author : Chirag Date 
Description :  Write a program to print a message queue's (use `msqid_ds` and `ipc_perm` structures)
    1. Access permission 
    2. `uid`, `gid` 
    3. Time of last message sent and received 
    4. Time of last change in the message queue
    5. Size of the queue 
    6. Number of messages in the queue
    7. Maximum number of bytes allowed
    8. PID of the `msgsnd` and `msgrcv`
Date: 19th Sept, 2024.
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
    struct msqid_ds messageQueueInfo; 
    int msgctlStatus;           

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);
    if (queueIdentifier == -1)
    {
        perror("Error while creating Message Queue!");
        _exit(0);
    }

    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n\n", queueIdentifier);

    msgctlStatus = msgctl(queueIdentifier, IPC_STAT, &messageQueueInfo);

    if (msgctlStatus == -1)
    {
        perror("Error while getting Message Queue info!");
        _exit(0);
    }

    printf("Access Permission: %od\n", messageQueueInfo.msg_perm.mode);
    printf("UID: %d\n", messageQueueInfo.msg_perm.uid);
    printf("GID: %d\n", messageQueueInfo.msg_perm.gid);
    printf("Time of last message sent: %ld\n", messageQueueInfo.msg_stime);
    printf("Time of last message received: %ld\n", messageQueueInfo.msg_rtime);
    printf("Size of queue: %ld\n", messageQueueInfo.__msg_cbytes);
    printf("Number of messages in the queue: %ld\n", messageQueueInfo.msg_qnum);
    printf("Maximum number of bytes allowed in the queue: %ld\n", messageQueueInfo.msg_qbytes);
    printf("PID of last sent message: %d\n", messageQueueInfo.msg_lspid);
    printf("PID of last received message: %d\n", messageQueueInfo.msg_lrpid);
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 25.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Key: 17020263
Message Queue Identifier: 2

Access Permission: 700d
UID: 1000
GID: 1000
Time of last message sent: 0
Time of last message received: 0
Size of queue: 0
Number of messages in the queue: 0
Maximum number of bytes allowed in the queue: 16384
PID of last sent message: 0
PID of last received message: 0

============================================================================
*/

