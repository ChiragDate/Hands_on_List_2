/*
============================================================================
Name : 21a.c
Author : Chirag Date 
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 19th Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h> 

void main(){
    char buffer1[50], buffer2[50]; 
    int file_desc_1  = open("fifo1", O_WRONLY);
    int file_desc_2  = open("fifo2", O_RDONLY);
    
    if(file_desc_1==-1 || file_desc_2==-1 ){
	    printf("error while opening file\n");
    }
    
    printf("Enter the text :");
    scanf(" %[^\n]", buffer1);
    write(file_desc_1, buffer1, 50);
    
    read(file_desc_2, buffer2, 50);
    printf("The text from the FIFO : %s\n", buffer2);
    
    return;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ mkfifo fifo1
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ mkfifo fifo2
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 21a.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Enter the text :Hi
The text from the FIFO : Hello

============================================================================
*/

