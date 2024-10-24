/*
============================================================================
Name : 15.c
Author : Chirag Date 
Description : Write a simple program to send some data from parent to the child process.
Date: 20th Sept, 2024.
============================================================================
*/


#include <unistd.h>   
#include <sys/types.h> 
#include <stdio.h>     

void main()
{
    int childPid;
    int pipefd[2];       
    int status;          
    int readBytes, writeBytes;

    char *writeBuffer = "Hello child! It's mom!", *readBuffer;

    status = pipe(pipefd);

    if (status == -1)
        perror("Error while creating pipe!");
    else
    {
        printf("Pipe created successfully\n");
        childPid = fork();
        
        if (childPid == -1)
            perror("Error whiling forking new child!");
            
        else if (childPid == 0)
        {
            readBytes = read(pipefd[0], &readBuffer, sizeof(writeBuffer));
            
            if (readBytes == -1)
                perror("Error while reading from pipe!\n");
                
            else
                printf("Data from parent: %s\n", readBuffer);
        }
        else
        {
        
            writeBytes = write(pipefd[1], &writeBuffer, sizeof(writeBuffer));
            
            if (writeBytes == -1)
                perror("Error while writing to pipe!");
        }
    }
}



/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 15.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Pipe created successfully
Data from parent: Hello child! It's mom!

============================================================================
*/
