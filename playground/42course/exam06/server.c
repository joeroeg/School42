#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#define BUFF 4242
// #define MSG_NOSIGNAL 0

int sockfd, maxfd;
struct sockaddr_in servaddr;

int ids[FD_SETSIZE];
int count = 0;

fd_set read_fd, current_fd;

char serverBuf[100];
char clientBuf[BUFF];

void ft_error(char *str){
	char *msg = str ? str : "Fatal error\n";
	write(2, msg, strlen(msg));
	exit(1);
}

void broadCast(int client, char *msg, int len){
	for (int fd = 0;fd <= maxfd; fd++)
		if (client != fd)
			send(fd, msg, len, MSG_NOSIGNAL);
}

void handleConnection(int client, int opt){
	memset(serverBuf, 0, 100);
	sprintf(serverBuf, "server: client %d just %s\n", ids[client], !opt ? "arrived" : "left");
	broadCast(client, serverBuf, strlen(serverBuf));
}

void sendMsg(int client, int len){
	memset(serverBuf, 0, 100);
	sprintf(serverBuf, "client %d: ", ids[client]);
	broadCast(client, serverBuf, strlen(serverBuf));

	char send[2] = {};

	for (int i = 0; i < len; i++){
		send[0] = clientBuf[i];
		broadCast(client, send, strlen(send));

		if (i + 1 < len && send[0] == '\n')
			broadCast(client, serverBuf, strlen(serverBuf));

		if (i + 1 == len && len == BUFF){
			memset(clientBuf, 0, BUFF);
			len = recv(client, clientBuf, BUFF, 0);
			i = -1;
		}
	}
}

int main(int ac, char **av) {
	if (ac != 2)
		ft_error("Wrong number of arguments\n");

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		ft_error(0);
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		ft_error(0);
	if (listen(sockfd, 10) != 0)
		ft_error(0);

	// Initialisation
	FD_ZERO(&current_fd);									// FD_ZERO is a macro that clears (or "zeros") a set of file descriptors.
	FD_SET(sockfd, &current_fd);							// FD_SET is a macro that adds a file descriptor (sockfd) to a set of file descriptors (&current_fd).
	maxfd = sockfd;											// maxfd is the maximum file descriptor number that select should check.

	// Main loop
	while(42) {
		// Copy the current file descriptors to the read file descriptors
		read_fd = current_fd;								// read_fd is a set of file descriptors that will be used by select to determine which file descriptors are ready for reading.

		if (select(maxfd + 1, &read_fd, 0,0,0) < 0)			// select is a system call that monitors file descriptors for reading, writing, or exceptions.
			continue;

		// Check all file descriptors
		for (int fd = 0; fd <= maxfd; fd++) {
			if (!(FD_ISSET(fd, &read_fd)))					// FD_ISSET is a macro that checks if a file descriptor is part of a set of file descriptors.
				continue;

			if (sockfd == fd) {							// if sockfd = fd, then a new client is trying to connect to the server.
				int clientfd = accept(sockfd, 0, 0); 		// accept is a system call that extracts the first connection request on the queue of pending connections for the listening socket, sockfd, creates a new connected socket, and returns a new file descriptor referring to that socket.
				if (clientfd > 0) {						// if clientfd > 0, then the connection was successful.
					if (clientfd > maxfd)				// if clientfd > maxfd, then the new client's file descriptor is greater than the current maxfd.
						maxfd = clientfd;					// maxfd is updated to the new client's file descriptor.
					ids[clientfd] = count++;
					FD_SET(clientfd, &current_fd);			// FD_SET is a macro that adds a file descriptor (clientfd) to a set of file descriptors (&current_fd).
					handleConnection(clientfd, 0);			// handleConnection is a function that sends a message to all clients that a new client has connected.
				}
			} else {									// if sockfd != fd, then a client is trying to send a message to the server.
				memset(clientBuf, 0, BUFF);					// memset is a function that fills a block of memory with a particular value.
				int len = recv(fd, clientBuf, BUFF, 0);		// recv is a system call that receives a message from a socket.
				if (len > 0)							// if len > 0, then the message was received successfully.
					sendMsg(fd, len);						// sendMsg is a function that sends a message to all clients.
				else {									// if len <= 0, then the client has disconnected.
					handleConnection(fd, 1);				// handleConnection is a function that sends a message to all clients that a client has disconnected.
					FD_CLR(fd, &current_fd);				// FD_CLR is a macro that removes a file descriptor (fd) from a set of file descriptors (&current_fd).
					close(fd);								// close is a system call that closes a file descriptor.
				}
			}
		}
	}
}
