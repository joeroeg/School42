#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_EVENTS 10
#define PORT 8080
#define BACKLOG 5

int server_fd;  // Global server socket file descriptor

// Function to initialize and set up the server socket
void server_init(int port) {
    struct sockaddr_in server_addr;

    // Create Socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0); // Creates a new IPv4 TCP socket.
    if (server_fd == -1) { // Check if socket creation was successful
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Prepare Server Address
    memset(&server_addr, 0, sizeof(server_addr)); // Zeros out the server_addr structure.
    server_addr.sin_family = AF_INET;             // Sets the address family to IPv4 (AF_INET).
    server_addr.sin_addr.s_addr = INADDR_ANY;     // Accepts connections from any network interface.
    server_addr.sin_port = htons(port);           // Converts the port number to network byte order and stores it.

    // Bind Socket
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)); // Allow reuse of local addresses

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) { // Associates the socket with the address and port.
        perror("Error binding");
        exit(EXIT_FAILURE);
    }

    // Listen for Connections
    if (listen(server_fd, BACKLOG) < 0) { // Sets the socket to listen for incoming connections.
        perror("Error listening");
        exit(EXIT_FAILURE);
    }
}


// Function to handle client communication
void handle_client(int client_fd) {
    char buffer[256];
    ssize_t bytes_read = recv(client_fd, buffer, sizeof(buffer), 0);
    if (bytes_read <= 0) {
        close(client_fd); // Connection closed or error
    } else {
        printf("Received from client: %s", buffer);

        // Echo the data back to the client (optional)
        send(client_fd, buffer, bytes_read, 0);
    }
}

int main() {
    struct sockaddr_in client_addr;
    socklen_t addrlen = sizeof(client_addr);
    struct pollfd fds[MAX_EVENTS];
    int nfds = 1;
    int timeout = -1;

    server_init(PORT); // Initialize and set up server

    // Set up poll structure for server socket
    memset(fds, 0 , sizeof(fds)); // Initialize the pollfd array to 0
    fds[0].fd = server_fd;        // Add the server socket to the pollfd array
    fds[0].events = POLLIN;       // Monitor the server socket for incoming connections

    // Event loop
    while (1) {
        int poll_count = poll(fds, nfds, timeout); // Polls the fds array for events (new connections or data to read) with an infinite timeout
        if (poll_count == -1) {
            perror("poll");
            exit(EXIT_FAILURE);
        }

        // Check server socket for new connection
        if (fds[0].revents & POLLIN) { // If the server socket is ready to be read from (meaning a new client is trying to connect)
            int new_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen); // Accept the incoming connection
            if (new_fd == -1) {
                perror("Accept");
                continue; // Skip to the next iteration if there's an error accepting
            }

            printf("Client connected\n");
            fds[nfds].fd = new_fd;    // Add the new client socket to the pollfd array
            fds[nfds].events = POLLIN; // Monitor the client socket for incoming data
            nfds++; // Increment the number of file descriptors being monitored
        }

        // Check for events on client sockets (fds[1] onwards)
        for (int i = 1; i < nfds; i++) {
            if (fds[i].revents & POLLIN) { // If a client socket has data available for reading
                handle_client(fds[i].fd); // Call the handle_client function to handle the client's data
            }
        }
    }

    return 0; // The loop will never end in this example
}
