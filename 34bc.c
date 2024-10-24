/*
============================================================================
Name : 34bc.c
Author : Chirag Date 
Description : Write a program to create a concurrent server.
a. use fork
b. use pthread_create
Date: 20th Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int PORT = 8080;

    // Create a TCP socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server. Type messages to send:\n");

    while (1) {
        printf("> ");
        fgets(buffer, sizeof(buffer), stdin);

        // Exit if user types "exit"
        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }

        // Send message to the server
        write(sock, buffer, strlen(buffer));

        // Read response from the server
        int bytes_read = read(sock, buffer, sizeof(buffer) - 1);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0'; // Null-terminate the received data
            printf("Server replied: %s", buffer);
        }
    }

    close(sock);
    printf("Disconnected from server.\n");
    return 0;
}


/*
============================================================================

Client 1:- 

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 34bc.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Connected to server. Type messages to send:
> Hello server I am client 1
Server replied: Hello server I am client 1
> ^C



Client 2:- 

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Connected to server. Type messages to send:
> hello server i am client 2
Server replied: hello server i am client 2
> ^C


============================================================================
*/

