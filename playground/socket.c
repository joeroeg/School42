#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Zero out the server address structure
    memset(&servaddr, 0, sizeof(servaddr));

    // Set the address family to IPv4
    servaddr.sin_family = AF_INET;

    // Google's IP address (IPv4)
    const char *google_ip = "142.250.72.238";  // One of Google's IP addresses

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, google_ip, &servaddr.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Set the port number to 80 (HTTP)
    servaddr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to Google at %s\n", google_ip);

    // Close the socket
    close(sockfd);

    return 0;
}
