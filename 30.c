/*
============================================================================
Name : 30.c
Author : Chirag Date 
Description : Write a program to create a shared memory. 
    1. Write some data to the shared memory
    2. Attach with `O_RDONLY` and check whether you are able to overwrite. 
    3. Detach the shared memory 
    4. Remove the shared memory
Date: 20th Sept, 2024.
============================================================================
*/


#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>  
#include<signal.h>

/*
void signal_handler(int signum) {
    printf("Caught segmentation fault : Due to try write in read-only memory.\n");
    return;
}
*/

void main(){
    char *shmPointer, *rdOnlyShmPointer;
    int shmKey, shmid;
    
    // signal(SIGSEGV, signal_handler);
    
    shmKey = ftok(".", 'b');
    
    shmid = shmget(shmKey, 1024, IPC_CREAT|0744);
    shmPointer = shmat(shmid, 0, 0);
    
    printf("Enter the text: ");
    scanf("%[^\n]", shmPointer);
    
    shmPointer = shmat(shmid, 0, 0);
    printf("Text from shared memory: %s\n", shmPointer);
    getchar();
    

    shmdt(shmPointer);      
    printf("Detach pointer to Shared Memory successfully!\n");
    
    shmctl(shmid, IPC_RMID, NULL);
    printf("remove the shared memory successfully!\n");

    return;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 30.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Enter the text: Hello
Text from shared memory: Hello
Detach pointer to Shared Memory successfully!
remove the shared memory successfully!

============================================================================
*/

