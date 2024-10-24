/*
============================================================================
Name : 32d.c
Author : Chirag Date 
Description : Write a program to implement semaphore to protect any critical section - Remove the created semaphore
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
    
    int segKey, semid, delsemstat;

    segKey = ftok(".", 'b'); 
    semid = semget(segKey, 1, IPC_CREAT|0744);
    
    if (semid == -1)
    {
        perror("Error while creating semaphore!");
    }
    
    delsemstat = semctl(semid, 0, IPC_RMID);
    
    if (delsemstat == -1)
    {
        perror("failed to delete semaphore!");
    }
    
    printf("Semaphore deleted successfully!\n");

    return;
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 32d.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Semaphore deleted successfully!

============================================================================
*/

