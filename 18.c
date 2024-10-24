/*
============================================================================
Name : 18.c
Author : Chirag Date 
Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 19th Sept, 2024
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

void main(){
    int fd1[2], fd2[2];               
    int pipe_status_1, pipe_status_2;           
    
    pipe_status_1 = pipe(fd1); 
    pipe_status_2 = pipe(fd2); 
  
    int pid = fork();
    if (pid==0) {
        dup2(fd1[1], 1); 
        close(fd1[0]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("ls", "ls", "-Rl",NULL);
    }
    else {
        int pid = fork();
        if (pid==0) {
            dup2(fd1[0], 0);
            dup2(fd2[1], 1);
            close(fd1[1]);
            close(fd2[0]);
            execlp("grep", "grep", "^d",NULL);
            }
        else {
            dup2(fd2[0], 0); 
            close(fd2[1]);
            close(fd1[0]);
            close(fd1[1]);
            execlp("wc", "wc",NULL);
        }
    } 
    return;
}



/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 18.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ls -l | grep ^d
drwxrwxr-x 1 chirag-date chirag-date     0 Sep 21 20:42 18example
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
      1       9      66

============================================================================
*/

