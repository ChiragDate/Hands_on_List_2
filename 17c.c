/*
============================================================================
Name : 17c.c
Author : Chirag Date 
Description : Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
Date: 20th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int pipeFd[2];
    int status;
    pid_t childPId;

    status = pipe(pipeFd);
    if (status == -1) {
        perror("Error while creating pipe");
        exit(1);
    }

    childPId = fork();
    if (childPId < 0) {
        perror("Error while creating child process");
        exit(1);
    }
    else if (childPId == 0) {
        close(STDIN_FILENO);
        if (fcntl(pipeFd[0], F_DUPFD, STDIN_FILENO) == -1) {
            perror("Error duplicating pipe read end");
            exit(1);
        }
        close(pipeFd[1]);
        execl("/usr/bin/wc", "wc", NULL);
        perror("Error executing wc");
        exit(1);
    }
    else {
        close(STDOUT_FILENO);
        if (fcntl(pipeFd[1], F_DUPFD, STDOUT_FILENO) == -1) {
            perror("Error duplicating pipe write end");
            exit(1);
        }
        close(pipeFd[0]);
        execl("/bin/ls", "ls", "-l", NULL);
        perror("Error executing ls");
        exit(1);
    }

    return 0;
}



/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 17c.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
     64     569    3887
     
============================================================================
*/

