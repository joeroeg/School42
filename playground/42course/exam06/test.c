/*
- Check arguments [X]
- Create socket and check for errors [X]
- Assign ip and port to servaddr [X]
- Bind the socket to the ip and port [X]
- Listen for incoming connections [X]
- Initialize the file descriptor set [X]
    a. Clear the set of file descriptors (FD_ZERO)
    b. Add the server file descriptor to the set (FD_SET)
    c. Set the maximum file descriptor number to the server file descriptor (maxfd)
- Start the main event loop [X]
- Copy the current file descriptor set (current_fd) to the read file descriptor set (read_fd)
- Check if any file descriptors are ready for reading
- Check all file descriptors
- If a new client is trying to connect(accept)
- If the connection was successful, update maxfd and add the client file descriptor to the set
- Send a message to all clients that a new client has connected
- If a client is trying to send a message
- Receive the message
- If the message was received successfully, send the message to all clients
- If the client has disconnected
- Send a message to all clients that a client has disconnected
- Remove the client file descriptor from the set
- Close the file descriptor
- End of main loop
*/

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int sockfd, maxfd;
struct sockaddr_in servaddr;
fd_set current_fd, read_fd;

void error_message(char *message) {
    write(2, message, strlen(message));
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 2)
        error_message("Wrong number of arguments\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error_message("Fatal error\n");

    bzero(&servaddr, sizeof(servaddr)); // clean servaddr
    servaddr.sin_family = AF_INET; // AF_INET is the address family used for IPv4 addresses
	servaddr.sin_addr.s_addr = htonl(2130706433); // htonl converts the unsigned integer hostlong from host byte order to network byte order.
	servaddr.sin_port = htons(atoi(argv[1])); // htons converts the unsigned short integer hostshort from host byte order to network byte order.

    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) // bind(sockfd, addr, addrlen) assigns the address specified by addr to the socket referred to by the file descriptor sockfd.
        error_message("Fatal error\n");

    if (listen(sockfd, 10) != 0) // listen(sockfd, backlog) marks the socket referred to by sockfd as a passive socket, that is, as a socket that will be used to accept incoming connection requests using accept.
        error_message("Fatal error\n");

    FD_ZERO(&current_fd); // FD_ZERO is a macro that clears (or "zeros") a set of file descriptors.
    FD_SET(sockfd, &current_fd); // FD_SET is a macro that adds a file descriptor (sockfd) to a set of file descriptors (&current_fd).

    while (1) {
        read_fd = current_fd; // Copy the current file descriptor set to the read file descriptor set (read_fd)
        if (select(maxfd + 1, &read_fd, NULL, NULL, NULL) < 0) // select(fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout)
            continue; // The continue statement is used here to handle the case where select returns an error. This could happen for various reasons, such as a signal interrupting the select call. By using continue, the program avoids performing any further operations for this iteration and immediately starts the next iteration of the loop. This helps maintain the non-blocking behavior of the server, ensuring it doesn't get stuck on a failed select call.
        
    }
}
