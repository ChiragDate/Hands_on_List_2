/*  
============================================================================
Name : 4.c
Author : Chirag Date
Description : Write a program to measure how much time is taken to execute 100 getppid ( ) system call. Use time stamp counter.
Date: 9th Sep, 2024.
===========================================================================
*/

#include<stdio.h>
#include<unistd.h>

static __inline__ unsigned long long rdtsc(void){ 
    unsigned int dst;
    __asm__ __volatile__("rdtsc" : "=A" (dst));
    return dst;
}

void main(){
    int p_id, start, end;
    start = rdtsc();
    for(int i=0;i<100;i++){
        p_id = getppid();
    }
    end = rdtsc();
    
    int cpu_cycles = end - start;
    double cpu_frequency_ghz = 2.6; 
    double total_time_taken = (cpu_cycles / cpu_frequency_ghz);
    printf("PID : %d\n", p_id);
    printf("Total time to taken to execute 100 getppid() system call in ns: %0.2f\n", total_time_taken);
    
    return;
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 4.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out 
PID : 19036
Total time to taken to execute 100 getppid() system call in ns: 20934.62

============================================================================
*/
