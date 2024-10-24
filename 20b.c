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
    int file_desc  = open("fifo", O_RDONLY);
    if(file_desc==-1){
	    printf("error while opening file\n");
    }
    
    read(file_desc, buffer, 100);
    printf("The text from the FIFO : %s\n", buffer);
    
    close(file_desc); 
    return;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 20b.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
The text from the FIFO : Hello

============================================================================
*/

