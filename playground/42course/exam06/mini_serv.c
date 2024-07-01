#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <stdio.h>

#define BUFF 2048

int sockfd, maxfd;
struct sockaddr_in servaddr;

fd_set readfd, currentfd;

int ids[FD_SETSIZE];
int client_counter = 0;

char serverBuf[2048];
char clientBuf[2048];

void error_message(char *msg) {
    write(2, msg, strlen(msg));
    exit(1);
}

void broadCast(int client, char *msg, int len) {
    for (int fd = 0; fd <= maxfd; fd++) {
        if (client != fd && FD_ISSET(fd, &currentfd)) {
            send(fd, msg, len, SO_NOSIGPIPE);
        }
    }
}

// void sendMsg(int client, int len) {
// 	memset(serverBuf, 0, 100);
// 	sprintf(serverBuf, "client %d: ", ids[client]);
// 	broadCast(client, serverBuf, strlen(serverBuf));

// 	char send[2] = {};

// 	for (int i = 0; i < len; i++){
// 		send[0] = clientBuf[i];
// 		broadCast(client, send, strlen(send));

// 		if (i + 1 < len && send[0] == '\n')
// 			broadCast(client, serverBuf, strlen(serverBuf));

// 		if (i + 1 == len && len == BUFF){
// 			memset(clientBuf, 0, BUFF);
// 			len = recv(client, clientBuf, BUFF, 0);
// 			i = -1;
// 		}
// 	}
// }

void sendMsg(int client, int len) {
    // Prepare the prefix
    char prefix[100];
    memset(prefix, 0, 100);
    sprintf(prefix, "client %d: ", ids[client]);

    // Send the prefix to all other clients
    broadCast(client, prefix, strlen(prefix));

    // Broadcast the client's message
    broadCast(client, clientBuf, len);

    // Ensure new messages start with the client prefix
    if (clientBuf[len - 1] != '\n') {
        broadCast(client, "\n", 1);
        broadCast(client, prefix, strlen(prefix));
    }
}


int main(int argc, char **argv) {
    if (argc != 2)
        error_message("Wrong number of arguments\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
            error_message("Fatal error\n");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));

    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        error_message("Fatal error\n");

    if (listen(sockfd, 10) != 0)
        error_message("Fatal error\n");

    FD_ZERO(&readfd);
    FD_ZERO(&currentfd);
    FD_SET(sockfd, &currentfd);
    maxfd = sockfd;

    while(1) {
        readfd = currentfd;

        if (select(maxfd + 1, &readfd, 0, 0, 0) < 0)
            continue;

        for (int fd = 0; fd <= maxfd; fd++) {
            if (!(FD_ISSET(fd, &readfd)))
                continue;

            if (sockfd == fd)
            {
                int clientfd = accept(sockfd, 0, 0);
                if (clientfd > maxfd)
                    maxfd = clientfd; // important to update a limit of possible clients for a broadcast function
                ids[clientfd] = client_counter++; // important to have unique ID for each client so that we use client counter to assign a new ID
                FD_SET(clientfd, &currentfd); // Why do we need to add currentfd and not readfd for example?
                sprintf(serverBuf, "server: client %d just arrived\n", ids[clientfd]);
                broadCast(clientfd, serverBuf, strlen(serverBuf));
            }
            else
            {
                int len = recv(fd, clientBuf, 2048, 0);
                if (len > 0)
                {
                    sendMsg(fd, len);
                }
                else
                {
                    sprintf(serverBuf, "server: client %d just left\n", ids[fd]);
                    broadCast(fd, serverBuf, strlen(serverBuf));
                    FD_CLR(fd, &currentfd);
                    close(fd);
                }
            }
        }
    }
}
