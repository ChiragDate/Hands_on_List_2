/*
============================================================================
Name : 22b.c
Author : Chirag Date 
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 19th Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h> 

void main(){
    char buffer[100]; 
    int file_desc  = open("fifo", O_WRONLY);
    if(file_desc==-1){
	    printf("error while source file\n");
    }
    
    printf("Enter the text :");
    scanf(" %[^\n]", buffer);
    write(file_desc, buffer, 100);
    
    close(file_desc);
    return;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 22b.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Enter the text :Hello

============================================================================
*/

