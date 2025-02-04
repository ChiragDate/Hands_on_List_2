/*
============================================================================
Name : 5.c
Author : Chirag Date 
Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 9th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>
#include <sys/vfs.h>

int main(){

struct rlimit rl;

if(getrlimit(RLIMIT_NPROC,&rl) == -1){
  perror("getrlimit");
  return 1;
}

printf("maximum length of the arguments to the exec family of functions : %ld bytes \n", (long)sysconf(_SC_ARG_MAX));
  
printf("maximum number of simultaneous process per user id : %ld \n",(long)rl.rlim_max);

printf("number of clock ticks (jiffy) per second. %ld \n",(long)sysconf(_SC_CLK_TCK));

if(getrlimit(RLIMIT_NOFILE, &rl) == -1) {
    perror("getrlimit");
    return 1;
}

printf("maximum number of open files %ld \n",(long)rl.rlim_max);

printf("size of a page %ld bytes \n",(long)sysconf(_SC_PAGESIZE));

printf("total number of pages in the physical memory: %ld \n", sysconf(_SC_PHYS_PAGES));
printf("number of currently available pages in the physical memory: %ld \n", sysconf(_SC_AVPHYS_PAGES));





return 0;
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 5.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
maximum length of the arguments to the exec family of functions : 2097152 bytes 
maximum number of simultaneous process per user id : 30398 
number of clock ticks (jiffy) per second. 100 
maximum number of open files 1048576 
size of a page 4096 bytes 
total number of pages in the physical memory: 1964250 
number of currently available pages in the physical memory: 846934 

============================================================================
*/

