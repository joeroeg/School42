#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define SERVER_ADDR "127.0.0.1" // Replace with actual server IP if not localhost

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    struct pollfd fds[1];
    int timeout = -1; // Infinite timeout
    char buffer[256];

    // 1. Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // 2. Prepare server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, SERVER_ADDR, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    // 3. Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    // 4. Set up poll structure
    fds[0].fd = sockfd;
    fds[0].events = POLLIN | POLLOUT; // Monitor for both read and write events

    // 5. Send a message to the server
    const char *message = "Hello from client!\n";
    send(sockfd, message, strlen(message), 0);

    // 6. Use poll() to wait for server's response
    while (1) {
        int poll_count = poll(fds, 1, timeout);
        if (poll_count == -1) {
            perror("poll");
            exit(EXIT_FAILURE);
        }

        if (fds[0].revents & POLLIN) { // Data from server
            memset(buffer, 0, sizeof(buffer));
            recv(sockfd, buffer, sizeof(buffer) - 1, 0);
            printf("Received from server: %s", buffer);
            break; // Exit after receiving one message
        }
    }

    close(sockfd);
    return 0;
}
