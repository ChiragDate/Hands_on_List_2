/*
============================================================================
Name : 13a.c
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

void customHandler()   
{
    printf("SIGSTOP signal received!\n");
    _exit(0);
}

void main(){

    pid_t pid = getpid();
    printf("Process ID: %d\n", pid);

    signal(SIGSTOP, customHandler); 

    printf("Putting the process to sleep for 15 s\n");
    sleep(15);
    
    printf("No stop signal received\n");

    return;
}



/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 13a.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Process ID: 19519
Putting the process to sleep for 15s
No stop signal received

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 13a.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Process ID: 19563
Putting the process to sleep for 15s

[1]+  Stopped                 ./a.out

============================================================================
*/

