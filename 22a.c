/*
============================================================================
Name : 22a.c
Author : Chirag Date 
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 19th Sept, 2024.
============================================================================
*/

#include<stdio.h> 
#include<fcntl.h>
#include<unistd.h> 
#include<sys/time.h>  
#include<sys/types.h> 

void main()
{
    char buffer[100]; 
    fd_set readFDSet;
    struct timeval time;
    
    int file_desc  = open("fifo", O_RDONLY);
 
    FD_ZERO(&readFDSet);
    FD_SET(file_desc, &readFDSet);

    time.tv_sec = 10;
    time.tv_usec = 0;

    int returnVal = select(file_desc+ 1, &readFDSet, NULL, NULL, &time);

    if (returnVal == -1){
        printf("ERROR");
    }
    else if (returnVal){
        printf("The data is now available\n");
    }
    else{
        printf("No data was given for 10 seconds\n");
        _exit(0);
    }
    
    read(file_desc, buffer, 100);
    printf("The text from the FIFO : %s\n", buffer);

    close(file_desc); 
    return;
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 22a.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
The data is now available
The text from the FIFO : Hello

============================================================================
*/

