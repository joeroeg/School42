#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 1024

typedef struct s_client {
    int fd;
    int id;
    struct s_client *next;
} t_client;

int g_id = 0;
fd_set g_active_fds, g_read_fds, g_write_fds;
int g_fd_max = 0;
t_client *g_clients = NULL;

void fatal_error() {
    write(2, "Fatal error\n", 12);
    exit(1);
}

void add_client(int client_fd) {
    t_client *new_client = malloc(sizeof(t_client));
    if (!new_client)
        fatal_error();
    new_client->fd = client_fd;
    new_client->id = g_id++;
    new_client->next = g_clients;
    g_clients = new_client;
    FD_SET(client_fd, &g_active_fds);
    if (client_fd > g_fd_max)
        g_fd_max = client_fd;
}

void remove_client(int client_fd) {
    t_client *tmp = g_clients;
    t_client *prev = NULL;

    while (tmp && tmp->fd != client_fd) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp) {
        if (prev)
            prev->next = tmp->next;
        else
            g_clients = tmp->next;
        free(tmp);
        FD_CLR(client_fd, &g_active_fds);
        close(client_fd);
    }
}

void send_to_all(int sender_fd, char *message) {
    t_client *tmp = g_clients;
    while (tmp) {
        if (tmp->fd != sender_fd)
            send(tmp->fd, message, strlen(message), 0);
        tmp = tmp->next;
    }
}

void handle_new_connection(int server_fd) {
    int client_fd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0)
        fatal_error();

    add_client(client_fd);

    char msg[64];
    sprintf(msg, "server: client %d just arrived\n", g_clients->id);
    send_to_all(client_fd, msg);
}

void handle_client_message(int client_fd) {
    char buffer[1024];
    int bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received <= 0) {
        t_client *tmp = g_clients;
        while (tmp && tmp->fd != client_fd)
            tmp = tmp->next;
        if (tmp) {
            char msg[64];
            sprintf(msg, "server: client %d just left\n", tmp->id);
            send_to_all(client_fd, msg);
        }
        remove_client(client_fd);
    } else {
        buffer[bytes_received] = '\0';
        t_client *tmp = g_clients;
        while (tmp && tmp->fd != client_fd)
            tmp = tmp->next;
        if (tmp) {
            char msg[1088];
            sprintf(msg, "client %d: %s", tmp->id, buffer);
            send_to_all(client_fd, msg);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        write(2, "Wrong number of arguments\n", 26);
        exit(1);
    }

    int port = atoi(argv[1]);
    if (port <= 0)
        fatal_error();

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
        fatal_error();

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        fatal_error();

    if (listen(server_fd, 10) < 0)
        fatal_error();

    FD_ZERO(&g_active_fds);
    FD_SET(server_fd, &g_active_fds);
    g_fd_max = server_fd;

    while (1) {
        g_read_fds = g_active_fds;
        if (select(g_fd_max + 1, &g_read_fds, NULL, NULL, NULL) < 0)
            fatal_error();

        for (int i = 0; i <= g_fd_max; i++) {
            if (FD_ISSET(i, &g_read_fds)) {
                if (i == server_fd) {
                    handle_new_connection(server_fd);
                } else {
                    handle_client_message(i);
                }
            }
        }
    }
    return 0;
}
