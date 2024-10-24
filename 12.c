/*
============================================================================
Name : 12.c
Author : Chirag Date 
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 9th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void parent_process() {
    printf("Parent PID: %d\n", getpid());
    sleep(1);  
    printf("Parent is exiting...\n");
    exit(0); 
}

void child_process(pid_t parent_pid) {
    printf("Child PID: %d, Parent PID: %d\n", getpid(), parent_pid);
    
    sleep(2);
    
    printf("Child sending SIGKILL to Parent...\n");
    kill(parent_pid, SIGKILL);

    sleep(1);  
    printf("Child is now an orphan, Parent is gone.\n");
    printf("Parent PID: %d\n", getppid());

    exit(0);
}

void main(){
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid > 0) {
        parent_process();
    } else {
        child_process(getppid());
    }
          
    return;
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 12.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Parent PID: 19336
Child PID: 19337, Parent PID: 19336
Parent is exiting...
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ Child sending SIGKILL to Parent...
Child is now an orphan, Parent is gone.
Parent PID: 15291
^C
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ps 15291
    PID TTY      STAT   TIME COMMAND
  15291 ?        Ss     0:00 /lib/systemd/systemd --user

============================================================================
*/

