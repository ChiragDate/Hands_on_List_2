/*
============================================================================
Name : 3.c
Author : Chirag Date 
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 9th Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/resource.h>

void main(){
    struct rlimit resourceLimits; 

    // RLIMIT_CORE -> Max size of a core file
    int limit = getrlimit(RLIMIT_CORE, &resourceLimits);

    printf("Before setting soft and hard limit\n");
    printf("Max size of a core file : SoftLimit = %lu, Hardimit = %lu %s\n", (unsigned long)resourceLimits.rlim_cur, (unsigned long)resourceLimits.rlim_max, "bytes");
    
    resourceLimits.rlim_cur = 0;
    resourceLimits.rlim_max = 100*1024; // 100KB
    printf("After setting soft and hard limit\n");
    printf("Max size of a core file : SoftLimit = %lu, Hardimit = %lu %s\n", (unsigned long)resourceLimits.rlim_cur, (unsigned long)resourceLimits.rlim_max, "bytes");
    
    return;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 3.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out 
Before setting soft and hard limit
Max size of a core file : SoftLimit = 0, Hardimit = 18446744073709551615 bytes
After setting soft and hard limit
Max size of a core file : SoftLimit = 0, Hardimit = 102400 bytes


============================================================================
*/

