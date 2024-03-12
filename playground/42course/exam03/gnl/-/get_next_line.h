#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h> // malloc, free
#include <unistd.h> // read
#include <fcntl.h> // open
#include <stdio.h> // printf
#include <string.h> // str functions

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

char *get_next_line(int fd);

#endif
