#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 80  // HTTP port
#define HOST "jsonplaceholder.typicode.com"
#define PATH "/posts"

// Function to send POST request
int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char request[1024];
    char response[4096];

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    // Get the server IP address
    server = gethostbyname(HOST);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host: %s\n", HOST);
        return 1;
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Define the HTTP POST request
    const char *body = "{\"title\": \"foo\", \"body\": \"bar\", \"userId\": 1}";
    snprintf(request, sizeof(request),
             "POST %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Content-Type: application/json\r\n"
             "Content-Length: %zu\r\n"
             "Connection: close\r\n"
             "\r\n"
             "%s", PATH, HOST, strlen(body), body);

    // Send the HTTP request
    if (write(sockfd, request, strlen(request)) < 0) {
        perror("Error writing to socket");
        return 1;
    }

    // Read the response
    int bytes_received = 0;
    while ((bytes_received = read(sockfd, response, sizeof(response) - 1)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response);          // Print the response
    }

    // Check if there was an error reading
    if (bytes_received < 0) {
        perror("Error reading from socket");
    }

    // Close the socket
    close(sockfd);

    return 0;
}
