#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/tcp.h>

/*
int createTCPIpV4() {
    return socket(AF_INET, SOCK_STREAM, 0);
}

struct sockaddr_in * createServerAddress(char *ip, int port) {
    struct sockaddr_in *serverAddress = malloc(sizeof(struct sockaddr_in));
    serverAddress->sin_family = AF_INET; // AF_INET is the address family that is used for the socket (IPv4)
    serverAddress->sin_port = htons(80); // Port 80; htons() is needed to convert a number to network byte order
    inet_pton (AF_INET, ip, &serverAddress->sin_addr); // Convert IP to binary
    return serverAddress;
}

int main() {
    int socketFD = createTCPIpV4(); // Create a socket
    struct sockaddr_in *serverAddress = createServerAddress("", 2000); // Create a server address
    bind (socketFD, (struct sockaddr *) serverAddress, sizeof(*serverAddress)); // Bind the socket to the server address
    int optval = 1;
    setsockopt(socketFD, IPPROTO_TCP, SO_REUSEADDR, &optval, sizeof(optval)); // Disable Nagle's algorithm
    listen(socketFD, 10); // Listen for incoming connections
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLength = sizeof(clientAddress);
    int clientSocketFD = accept(socketFD, (struct sockaddr *) &clientAddress, &clientAddressLength); // Accept the connection

    // Receive the response
    char response[4096];
    while (1) {
        ssize_t receivedlen = recv(clientSocketFD, &response, sizeof(response), 0);
        response[receivedlen] = '\0';
        printf("%s", response);
    }
    close(clientSocketFD);
    close(socketFD);
}
*/

int createTCPIpV4() {
    return socket(AF_INET, SOCK_STREAM, 0);
}

struct sockaddr_in* createServerAddress(const char *ip, int port) {
    struct sockaddr_in *address = (struct sockaddr_in *) malloc(sizeof(struct sockaddr_in));
    address->sin_family = AF_INET;
    address->sin_port = htons(port);
    address->sin_addr.s_addr = ip[0] ? inet_addr(ip) : INADDR_ANY;
    return address;
}

int main() {
    int socketFD = createTCPIpV4();
    struct sockaddr_in *serverAddress = createServerAddress("", 2000);
    bind(socketFD, (struct sockaddr *) serverAddress, sizeof(*serverAddress));
    int optval = 1;
    setsockopt(socketFD, IPPROTO_TCP, TCP_NODELAY, &optval, sizeof(optval)); // Disable Nagle's algorithm
    listen(socketFD, 10);

    while (1) {
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);
        int clientSocketFD = accept(socketFD, (struct sockaddr *) &clientAddress, &clientAddressLength);

        if (clientSocketFD < 0) {
            perror("Failed to accept connection");
            continue;
        }

        char response[4096];
        ssize_t receivedlen;
        while ((receivedlen = recv(clientSocketFD, response, sizeof(response) - 1, 0)) > 0) {
            response[receivedlen] = '\0';
            printf("%s", response);
        }
        close(clientSocketFD);
    }

    close(socketFD);
    free(serverAddress);
    return 0;
}
