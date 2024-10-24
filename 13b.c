/*
============================================================================
Name : 13b.c
Author : Chirag Date 
Description :Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 19th Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include<signal.h>  
#include<unistd.h>
#include <stdlib.h>

void main(int argc, char *argv[]){

    pid_t pid;
    pid = atoi(argv[1]);

    int killStatus = kill(pid, SIGSTOP);
    printf("Successfully sent SIGSTOP signal to process (%d)\n", pid);

    return;
}x


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 13b.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 13b.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out 19563
Successfully sent SIGSTOP signal to process (19563)

============================================================================
*/

