/*
============================================================================
Name : 1.c
Author : Chirag Date 
Description : Write a program to implement semaphore to protect any critical section - Protect multiple pseudo resources (may be two) using counting semaphore 
Date: 20th Sept, 2024.
============================================================================
*/

#include<sys/ipc.h>   
#include<sys/sem.h>   
#include<sys/types.h> 
#include<sys/shm.h>   
#include<unistd.h>    
#include<stdio.h>    
#include<fcntl.h> 

void main()
{
    char *filename = "32c.txt"; 
    int fd;   
    ssize_t readBytes;
    off_t lseekOffset;
    char data[1000]; // Sample data

    key_t semKey;   
    int semid;
    int semctlStatus;  
    int semopStatus; 

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error while creating / opening the ticket file!");
        _exit(0);
    }

    // Defines a semaphore's structure
    union semun
    {
        int val;            
    } semSet;

    semKey = ftok(".", 'a');
    if (semKey == -1)
    {
        perror("Error while computing key!");
        _exit(1);
    }

    semid = semget(semKey, 1, 0); 
    if (semid == -1)
    {
        semid = semget(semKey, 1, IPC_CREAT | 0700); 
        if (semid == -1)
        {
            perror("Error while creating semaphore!");
            _exit(1);
        }

        semSet.val = 2; // Set a counting semaphore
        semctlStatus = semctl(semid, 0, SETVAL, semSet);
        if (semctlStatus == -1)
        {
            perror("Error while initializing a binary sempahore!");
            _exit(1);
        }
    }

    struct sembuf semOp; 
    semOp.sem_num = 0;
    semOp.sem_flg = IPC_NOWAIT;

    printf("Press enter to obtain lock for the critical section!\n");
    getchar();

    // Use semaphore to lock the critical section
    semOp.sem_op = -1;
    semopStatus = semop(semid, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }

    printf("Obtained lock on critical section!\n");

    printf("Now entering critical section!\n");

    readBytes = read(fd, &data, 1000);
    if (readBytes == -1)
    {
        perror("Error while reading from sample file!");
        _exit(0);
    }
    else if (readBytes == 0)
        printf("No data exists!\n");
    else
        printf("Sample data: \n %s", data);

    printf("Press enter key to exit critical section!\n");
    getchar();


    // Use semaphore to unlock the critical section
    semOp.sem_op = 1;
    semopStatus = semop(semid, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }

    close(fd);
    
    return ;
}

/*
============================================================================

Process 1
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 32c.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Press enter to obtain lock for the critical section!

Obtained lock on critical section!
Now entering critical section!
No data exists!
Press enter key to exit critical section!

Process 2
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Press enter to obtain lock for the critical section!

Obtained lock on critical section!
Now entering critical section!
No data exists!
Press enter key to exit critical section!

Process 3
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Press enter to obtain lock for the critical section!

Error while operating on semaphore!: Resource temporarily unavailable



============================================================================
*/

