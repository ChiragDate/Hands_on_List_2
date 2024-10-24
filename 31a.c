/*
============================================================================
Name : 31a.c
Author : Chirag Date 
Description : Write a program to create a semaphore and initialize value to the semaphore - Create a binary semaphore.
Date: 20th Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h> 

void main(){
    union semun {
        int val;
    }sem;
    
    int segKey, semid;

    segKey = ftok(".", 'b'); 
    semid = semget(segKey, 1, IPC_CREAT|0744);
    sem.val = 1;
    semctl(semid, 0, SETVAL, sem);
    
    printf("Binary semaphore created successfully!\n");

    return;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 31a.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Binary semaphore created successfully!
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x0103b567 0          chirag-dat 777        1         
0x6203b567 1          chirag-dat 744        1         

============================================================================
*/

