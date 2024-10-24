/*
============================================================================
Name : 32a.c
Author : Chirag Date 
Description : Write a program to implement semaphore to protect any critical section - Rewrite the ticket number creation program using semaphore
Date: 20th Sept, 2024.
============================================================================
*/


#include <sys/ipc.h>   
#include <sys/sem.h>   
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>    
#include <unistd.h>   
#include <stdio.h>  

void main()
{
    char *ticketFile = "./ticket-file.txt"; 

    int fileDescriptor;           
    ssize_t readBytes, writeBytes; 
    off_t lseekOffset;
    int data; 

    key_t semKey;     
    int semIdentifier; 
    int semctlStatus;  
    int semopStatus;  

    fileDescriptor = open(ticketFile, O_CREAT | O_RDWR, S_IRWXU);
    if (fileDescriptor == -1)
    {
        perror("Error while creating / opening the ticket file!");
        _exit(0);
    }

    union semun
    {
        int val;               
        struct semid_ds *buf;  
        unsigned short *array; 
        struct seminfo *__buf; 
    } semSet;

    semKey = ftok(".", 331);
    if (semKey == -1)
    {
        perror("Error while computing key!");
        _exit(1);
    }

    semIdentifier = semget(semKey, 1, 0); 
    if (semIdentifier == -1)
    {
        semIdentifier = semget(semKey, 1, IPC_CREAT | 0700); 
        if (semIdentifier == -1)
        {
            perror("Error while creating semaphore!");
            _exit(1);
        }

        semSet.val = 1; 
        semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);
        if (semctlStatus == -1)
        {
            perror("Error while initializing a binary sempahore!");
            _exit(1);
        }
    }

    struct sembuf semOp; 
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    printf("Press enter to obtain lock on the critical section\n");
    getchar();
    
    semOp.sem_op = -1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }
    
    printf("Obtained lock on critical section!\n");
    printf("Now entering critical section!\n");
    
    // =========== Start of Critical Section ===========

    readBytes = read(fileDescriptor, &data, sizeof(data));
    if (readBytes == -1)
    {
        perror("Error while reading from ticket file!");
        _exit(0);
    }
    else if (readBytes == 0) 
        data = 1;
    else
    {
        data += 1;
        lseekOffset = lseek(fileDescriptor, 0, SEEK_SET);
        if (lseekOffset == -1)
        {
            perror("Error while seeking!");
            _exit(0);
        }
    }

    writeBytes = write(fileDescriptor, &data, sizeof(data));
    if (writeBytes == -1)
    {
        perror("Error while writing to ticket file!");
        _exit(1);
    }

    printf("Your ticker number is - %d\n", data);

    printf("Press enter to exit from critical section!\n");
    getchar();

    // =========== End of Critical Section =============


    semOp.sem_op = 1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }
    close(fileDescriptor);
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ touch ticket-file.txt
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 32a.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Press enter to obtain lock on the critical section

Obtained lock on critical section!
Now entering critical section!
Your ticker number is - 1
Press enter to exit from critical section!

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Press enter to obtain lock on the critical section

Obtained lock on critical section!
Now entering critical section!
Your ticker number is - 2
Press enter to exit from critical section!

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$

============================================================================
*/

