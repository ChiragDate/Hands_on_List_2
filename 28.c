/*
============================================================================
Name : 28.c
Author : Chirag Date 
Description : Write a program to change the exiting message queue permission. (Use `msqid_ds` structure)
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
    
    msgctlStatus = msgctl(msgid, IPC_STAT, &messageQueueInfo);
    printf("Press enter to change the permissions!\n");
    getchar();

    messageQueueInfo.msg_perm.mode = 0777;
    msgctlStatus = msgctl(msgid, IPC_SET, &messageQueueInfo);
    
    if(msgctlStatus == -1){
        perror("Error while changing permission of Message Queue");
    }
    printf("Permissions change successfully!\n");

    return;
}



/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ 
 gcc 28.c -o 28
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ 
./28
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ 
 ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x61077d1e 0          chirag-dat     744        0            0           
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ 
 ./28
key = 0x61077d1e
Message queue Id = -1
Press enter to change the permissions!

Permissions change successfully!
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ 
 ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x61077d1e 1          chirag-dat     777        0            0                  

============================================================================
*/ 
