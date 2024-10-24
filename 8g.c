/*
============================================================================
Name : 8g.c
Author : Chirag Date 
Description : Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
Date: 9th Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/time.h>
#include<signal.h>

void timer_handler(int signum) {
    printf("Signal Catch\n");
}

void main(){
    struct itimerval time;
    
    signal(SIGPROF, timer_handler);  // signum = 27
    
    time.it_value.tv_sec = 1;
    time.it_value.tv_usec = 0;
    
    setitimer(ITIMER_PROF, &time, NULL);
      
    while(1);
    
    return;
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ touch temp.c 4.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 8f.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Signal Catch
^C
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 8g.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Signal Catch
^C

============================================================================
*/

