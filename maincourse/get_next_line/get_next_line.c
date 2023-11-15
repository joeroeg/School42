/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: device <device@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:00:04 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/15 11:42:43 by device           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char *get_next_line(int fd)
{
    static char *static_buffer = NULL;
    char *buffer;
    char *line;
    ssize_t bytes_read;
    char *temp;

    buffer = malloc(BUFFER_SIZE + 1);
    line = NULL;
    if (fd < 0 || !buffer)
    {
        free(buffer);
        return (NULL);
    }

    while (1)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(buffer);
            free(static_buffer);
            static_buffer = NULL;
            return (NULL);
        }

        if (bytes_read > 0)
        {
            buffer[bytes_read] = '\0';
            temp = ft_strjoin(static_buffer, buffer);
            if (!temp)
            {
                free(buffer);
                free(static_buffer);
                static_buffer = NULL;
                return (NULL);
            }
            free(static_buffer);
            static_buffer = temp;
        }

        // Check for newline in static_buffer
        char *newline = ft_strchr(static_buffer, '\n');
        if (newline)
        {
            *newline = '\0';
            line = ft_strdup(static_buffer);
            temp = ft_strdup(newline + 1);
            free(static_buffer);
            static_buffer = temp;

            if (!line)
            {
                free(buffer);
                return (NULL);
            }
            break; // Break the loop as the line is complete
        }

        if (bytes_read == 0)
        {
            // Handle the end of the file
            if (static_buffer && *static_buffer)
            {
                line = ft_strdup(static_buffer);
                free(static_buffer);
                static_buffer = NULL;
            }
            break;
        }
    }

    free(buffer);
    if (static_buffer && *static_buffer == '\0')
    {
        free(static_buffer);
        static_buffer = NULL;
    }
    return (line);
}
*/
#define MAX_CHUNKS 1024
#define CHUNK_SIZE 512

char *chunks[MAX_CHUNKS];

// Function to read a chunk of data
ssize_t read_chunk(int fd, char **chunk) {
    *chunk = malloc(CHUNK_SIZE);
    if (!*chunk) return -1; // Allocation failed
    return read(fd, *chunk, CHUNK_SIZE);
}

// Function to free chunks
void free_chunks() {
    for (int i = 0; i < MAX_CHUNKS; ++i) {
        free(chunks[i]);
        chunks[i] = NULL;
    }
}

// Function to find a newline in a chunk
int find_newline(char *chunk, int start, int length) {
    for (int i = start; i < length; ++i) {
        if (chunk[i] == '\n') return i;
    }
    return -1;
}

// Function to get the next line
char *get_next_line(int fd) {
    static int current_chunk = 0;
    static int offset = 0;
    char *line = NULL;
    int line_length = 0;

    while (current_chunk < MAX_CHUNKS) {
        if (chunks[current_chunk] == NULL) {
            ssize_t bytesRead = read_chunk(fd, &chunks[current_chunk]);
            if (bytesRead <= 0) break; // End of file or error
        }

		int newline_index = find_newline(chunks[current_chunk], offset, CHUNK_SIZE);
        int to_copy;

		if (newline_index != -1) {
            to_copy = newline_index - offset + 1; // Include newline
        } else {
            to_copy = CHUNK_SIZE - offset;
        }

        line = realloc(line, line_length + to_copy + 1);
        if (!line) {
            free_chunks();
            return NULL; // Allocation error
        }

        memcpy(line + line_length, chunks[current_chunk] + offset, to_copy);
        line_length += to_copy;

		if (newline_index != -1) {
            offset = newline_index + 1;
            if (offset >= CHUNK_SIZE) {
                offset = 0;
                current_chunk++;
            }
            line[line_length] = '\0'; // Replace newline with null terminator
            return line;
        } else {
            offset = 0;
            current_chunk++;
        }
    }

    free_chunks();
    return line_length > 0 ? line : NULL;
}

