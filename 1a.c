/*
============================================================================
Name : 1a.c
Author : Chirag Date 
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
Date: 6th Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/time.h>
#include<signal.h>
#include<stdlib.h>

void timer_handler(int signum) {
    printf("Timer Expired\n");
    printf("Signal Received\n");
    exit(1);
}

void main(int argc, char *argv[]){
    int timerStatus; 
    struct itimerval time;
    
    signal(SIGALRM, timer_handler); // signum = 14
    
    if (argv[1][0] == '1')
    {
        time.it_interval.tv_sec = 0;
        time.it_interval.tv_usec = 0;
        time.it_value.tv_sec = 10;
        time.it_value.tv_usec = 0;
    }
    else if (argv[1][0] == '2')
    {
        time.it_interval.tv_sec = 0;
        time.it_interval.tv_usec = 0;
        time.it_value.tv_sec = 0;
        time.it_value.tv_usec = 10000;
    }
    
    setitimer(ITIMER_REAL, &time, NULL);
      
    while(1);
    
    return;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 1a.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out 1
Timer Expired
Signal Received
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out 2
Timer Expired
Signal Received


============================================================================
*/

