/*
============================================================================
Name : 29.c
Author : Chirag Date 
Description : Write a program to remove the message queue.
Date: 20th Sept, 2024.
============================================================================
*/


#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

void main(){
    int key = ftok(".", 'a');
    int msgid = msgget(key, IPC_CREAT|0744);
    printf("key = 0x%0x\n", key);
    printf("Message queue Id = %d\n", msgid);
    
    struct msqid_ds messageQueueInfo;
    int msgctlStatus;
    
    msgctlStatus = msgctl(msgid, IPC_RMID, NULL);
    
    if(msgctlStatus == -1){
        perror("Error while removing message queue");
    }
    printf("Message queue removed successfully!\n");

    return;
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 29.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
key = 0x6103b567
Message queue Id = 3
Message queue removed successfully!
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    


============================================================================
*/

