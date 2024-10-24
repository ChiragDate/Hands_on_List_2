/*
============================================================================
Name : 21b.c
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
    int file_desc_1  = open("fifo1", O_RDONLY);
    int file_desc_2  = open("fifo2", O_WRONLY);
    
    if(file_desc_1==-1 || file_desc_2==-1 ){
	    printf("error while opening file\n");
    }
    
    read(file_desc_1, buffer1, 50);
    printf("The text from the FIFO : %s\n", buffer1);
    
    printf("Enter the text :");
    scanf(" %[^\n]", buffer2);
    write(file_desc_2, buffer2, 50);
    
    return;
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 21b.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
The text from the FIFO : Hi
Enter the text :Hello

============================================================================
*/

