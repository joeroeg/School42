/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:36 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/14 17:56:37 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *extract_line(char *buffer) {
    // Find the newline character
    char *newline = ft_strchr(buffer, '\n');
    if (!newline) return NULL; // No newline found

    // Calculate the length of the line
    int line_length = newline - buffer + 1; // Include newline

    // Allocate memory for the line
    char *line = malloc(line_length + 1); // +1 for null terminator
    if (!line) return NULL; // Allocation failure

    // Copy the line and add a null terminator
    strncpy(line, buffer, line_length);
    line[line_length] = '\0';

    return line;
}

char *get_next_line(int fd) {
    char *temporary_buffer = (char *)malloc(BUFFER_SIZE);
    if (!temporary_buffer) return NULL; // Allocation failure

    int read_bytes = read(fd, temporary_buffer, BUFFER_SIZE);

    // Check for read errors or empty reads
    if (read_bytes <= 0) {
        free(temporary_buffer);
        return NULL;
    }

    char *line = extract_line(temporary_buffer);
    free(temporary_buffer); // Remember to free the buffer

    return line;
}


