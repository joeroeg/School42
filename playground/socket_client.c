#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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

int ifexit(char * message, int socketFD) {
    if (strcmp(message, "exit\n") == 0) {
        exit(0);
		close(socketFD);
    }
    return 0;
}

int main() {
    int socketFD = createTCPIpV4();
    char *ip = "127.0.0.1";
    struct sockaddr_in *serverAddress = createServerAddress(ip, 2000);
    int result = connect(socketFD, (struct sockaddr *) serverAddress, sizeof(*serverAddress));

    char *message = NULL;
    size_t readlen = 0;
    while (1) {
        size_t readlen = getline(&message, &readlen, stdin);
        ifexit(message, socketFD);
        size_t sentlen = send(socketFD, message, readlen, 0);
        free(message);
        message = NULL;
    }
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
    address->sin_addr.s_addr = inet_addr(ip);
    return address;
}

void ifexit(char *message) {
    if (strncmp(message, "exit", 4) == 0) {
        printf("Exiting...\n");
        exit(0);
    }
}

int main() {
    char *ip = "127.0.0.1";
    struct sockaddr_in *serverAddress = createServerAddress(ip, 2000);

    while (1) {
        int socketFD = createTCPIpV4();
        if (connect(socketFD, (struct sockaddr *) serverAddress, sizeof(*serverAddress)) < 0) {
            perror("Failed to connect to server");
            close(socketFD);
            sleep(1); // Wait before trying to reconnect
            continue;
        }

        char *message = NULL;
        size_t readlen = 0;
        while (1) {
            ssize_t len = getline(&message, &readlen, stdin);
            ifexit(message);
            if (send(socketFD, message, len, 0) < 0) {
                perror("Failed to send message");
                break;
            }
        }
        free(message);
        close(socketFD);
    }

    free(serverAddress);
    return 0;
}
