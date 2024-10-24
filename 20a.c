/*
============================================================================
Name : 20a.c
Author : Chirag Date 
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 19th Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h> 


void main(){
    char buffer[100]; 
    int file_desc  = open("fifo", O_CREAT | O_WRONLY);
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

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ mkfifo fifo
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 20a.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Enter the text :Hello

============================================================================
*/




