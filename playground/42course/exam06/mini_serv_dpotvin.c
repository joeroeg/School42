#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/select.h>
#include <stdio.h>
#define MAX_USER_COUNT  1024
#define BUFFER_SIZE     4096          // real men use real buffer, never forget this one

// David

typedef enum _broadcast_type {
    USER_JOINED,
    USER_LEFT,
    USER_DATA
} broadcast_type;
typedef struct _data {
    int     id;
    char*   str;
} data;
data*   getData() {
    static data T[MAX_USER_COUNT];
    static int init;
    if (!init) {
        for (int i = 0; i < MAX_USER_COUNT; i++) {
            T[i].id = -1;
        }
        init = 1;
    }
    return T;
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int     CurrentUserCount = 0;
int     ListenFD;
int     MaxFD;
char    BUFFER[BUFFER_SIZE];
fd_set read_fds, write_fds, server_fds;
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void    free_all() {
    close(ListenFD);
    for (int i = 0; i < MAX_USER_COUNT; i++) {
        if (getData()[i].id != -1)  close(getData()[i].id);
        if (getData()[i].str) {
            bzero(getData()[i].str, strlen(getData()[i].str));
            free(getData()[i].str);
        }
        getData()[i].str = 0;
    }
}
void    error_msg(const char *str) {
    write(2, str, strlen(str));
    free_all();
    exit(1);
}
void    broadcast(char *str, int fromFD, broadcast_type flag) {
    if (flag == USER_JOINED) {
        char buffer[150];
        sprintf(buffer, "server: client %i just arrived\n", getData()[fromFD].id);
        for (int i = 0; i < MaxFD + 1; i++) {
            if (getData()[i].id != -1 && i != fromFD && FD_ISSET(i, &write_fds)) {
                send(i, buffer, strlen(buffer), 0);
            }
        }
    }
    else if (flag == USER_LEFT) {
        char buffer[150];
        sprintf(buffer, "server: client %i just left\n", getData()[fromFD].id);
        for (int i = 0; i < MaxFD + 1; i++) {
            if (getData()[i].id != -1 && i != fromFD && FD_ISSET(i, &write_fds)) {
                send(i, buffer, strlen(buffer), 0);
            }
        }
    }
    else if (flag == USER_DATA) {
        char *T = (char*)malloc(strlen(str) + 50);
        if (!T)                                                                         { error_msg("Fatal error\n");  }
        sprintf(T, "client %i: %s\n", getData()[fromFD].id, str);
        int len = strlen(T);
        for (int i = 0; i < MaxFD + 1; i++) {
            if (getData()[i].id != -1 && i != fromFD && FD_ISSET(i, &write_fds)) {
                send(i, T, len, 0);
            }
        }
        bzero(T, len);
        free(T);
    }
}
int main(int argc, char **args) {
    if (argc != 2)                                                                      { error_msg("Fatal error\n"); }
	ListenFD = socket(AF_INET, SOCK_STREAM, 0);
	if (ListenFD == -1)                                                                 { error_msg("Fatal error\n"); }
    struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(args[1]));
	if ((bind(ListenFD, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)    { error_msg("Fatal error\n"); }
	if (listen(ListenFD, MAX_USER_COUNT) != 0)                                          { error_msg("Fatal error\n");  }
    MaxFD = ListenFD;
    FD_ZERO(&server_fds);
    FD_SET(ListenFD, &server_fds);
    int Events;
    while (1) {
        read_fds = write_fds = server_fds;
        Events = select(MaxFD + 1, &read_fds, &write_fds, 0, 0);
        if (Events <= 0) continue;
        for (int i = 0; i < MaxFD + 1 && Events > 0; i++) {
            // Event on this FD
            if (FD_ISSET(i, &read_fds)) {
                // ListenFD Event -> New Client
                if (i == ListenFD) {
                    socklen_t len;
                    bzero(&len, sizeof(len));
                    struct sockaddr_in client;
                    int newClient = accept(i, (struct sockaddr *)&client, &len);
                    if (newClient > 0) {
                        if (MaxFD < newClient) MaxFD = newClient;
                        getData()[newClient].id = CurrentUserCount++;
                        FD_SET(newClient, &server_fds);
                        broadcast(0, newClient, USER_JOINED);
                    }
                    if (--Events == 0) break;
                }
                // User FD -> Receiving Stuff
                else {
                    int len = recv(i, BUFFER, BUFFER_SIZE - 1, 0);
                    // Client Disconnected
                    if (len <= 0) {
                        broadcast(0, i, USER_LEFT);
                        close(i);
                        FD_CLR(i, &server_fds);
                        getData()[i].id = -1;
                        if (getData()[i].str)
                            free(getData()[i].str);
                        getData()[i].str = 0;
                    }
                    // Data
                    else {
                        BUFFER[len] = 0;
                        // Null User Buffer -> Malloc
                        if (!getData()[i].str) {
                            getData()[i].str = (char*)malloc(len + 1);
                            if (!getData()[i].str)                                      { error_msg("Fatal error\n");  }
                            strcpy(getData()[i].str, BUFFER);
                        }
                        // User Buffer already has stuff -> Realloc + Append
                        else {
                            int old_len = strlen(getData()[i].str);
                            char *T = (char*)malloc(old_len + len + 1);
                            if (!T)                                                     { error_msg("Fatal error\n");  }
                            strcpy(T, getData()[i].str);
                            strcpy(&T[old_len], BUFFER);
                            bzero(getData()[i].str, old_len);
                            free(getData()[i].str);
                            getData()[i].str = T;
                        }
                        // Find Strings if at least one \n is found
                        for (int index = 0; getData()[i].str[index]; index++) {
                            if (getData()[i].str[index] == '\n') {
                                getData()[i].str[index] = 0;
                                broadcast(getData()[i].str, i, USER_DATA);
				// -------------> THIS DOESNT WORK PROPERLY, FIND A WAY TO KEEP THE REMAINDER <-----------------
				// i basically just made a malloc kept it in getData()[i].str
                                strcpy(getData()[i].str, getData()[i].str + index + 1);

                                index = -1;
                            }
                        }
                        // No data left in user buffer, free & set to null
                        if (getData()[i].str[0] == 0) {
                            free(getData()[i].str);
                            getData()[i].str = 0;
                        }
                    }
                    Events--;
                }
            }
        }
    }
    free_all();
    return 0;
}
