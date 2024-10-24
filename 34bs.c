/*
============================================================================
Name : 34bs.c
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
#include<pthread.h>
#include<netinet/in.h>

void* handle_client(void* arg) {
    int client_socket = *((int*)arg);
    char buffer[1024];
    int bytes_read;

    free(arg);

    while ((bytes_read = read(client_socket, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the received data
        printf("Received: %s", buffer);
        write(client_socket, buffer, bytes_read);
    }

    printf("Client disconnected.\n");
    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    int PORT = 8080;
    int BUFFER_SIZE = 1024;

    // Create a TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to all interfaces
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, 5) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept a new client connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Accepting connection failed");
            continue;
        }

        printf("Accepted connection from client.\n");

        // Allocate memory for the client socket
        int* new_sock = malloc(sizeof(int));
        *new_sock = client_socket;

        // Create a new thread to handle the client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, new_sock) != 0) {
            perror("Thread creation failed");
            free(new_sock);
        }

        // Detach the thread so it can clean up after itself
        pthread_detach(thread_id);
    }

    close(server_socket);
    return 0;
}

/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 34bs.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Server is listening on port 8080
Accepted connection from client.
Received: Hello server, accept my connection
Accepted connection from client.
Received: Hello I am second client
Client disconnected.
Client disconnected.

============================================================================
*/

