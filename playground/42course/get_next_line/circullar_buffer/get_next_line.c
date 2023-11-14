/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:00:04 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/14 18:04:02 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct CircularBuffer {
    char	*buffer;
    size_t	capacity;
    size_t	head;
    size_t	tail;
    size_t	count;
} CircularBuffer;

void initCircularBuffer(CircularBuffer *cb, size_t capacity) {
    if (!cb->buffer) {
        cb->buffer = malloc(capacity);
        if (!cb->buffer) {
			free(cb->buffer);
            return ;
        }
        cb->capacity = capacity;
        cb->head = 0;
        cb->tail = 0;
        cb->count = 0;
    }
}

void freeCircularBuffer(CircularBuffer *cb) {
    if (cb->buffer) {
        free(cb->buffer);
        cb->buffer = NULL;
    }
}

int readLine(int fd, char *line, size_t lineCapacity) {
    static CircularBuffer cb; // Static circular buffer retains its state
    static int isInitialized = 0; // To check if buffer is initialized
    char tempBuffer[BUFFER_SIZE];
    ssize_t bytesRead = 0;
    size_t lineLength = 0;
    int isNewLineRead = 0;

    if (!isInitialized) {
        initCircularBuffer(&cb, BUFFER_SIZE);
        isInitialized = 1;
    }

    while (lineLength < lineCapacity - 1 && !isNewLineRead) {
        // Only read if the buffer has no unread data
        if (cb.count == 0) {
            bytesRead = read(fd, tempBuffer, BUFFER_SIZE);
            if (bytesRead == -1) {
                perror("Read error");
				freeCircularBuffer(&cb);
                return -1;
            } else if (bytesRead == 0) {
                // End of file reached
				freeCircularBuffer(&cb);
                break;
            }

            // Fill the circular buffer with new data
            for (ssize_t i = 0; i < bytesRead; ++i) {
                // This assumes you have space, you may need to handle buffer being full
                cb.buffer[cb.tail] = tempBuffer[i];
                cb.tail = (cb.tail + 1) % cb.capacity;
                cb.count++;
            }
        }

        // Process the circular buffer to build a line
        while (cb.count > 0 && lineLength < lineCapacity - 1 && !isNewLineRead) {
            char ch = cb.buffer[cb.head];
            cb.head = (cb.head + 1) % cb.capacity;
            cb.count--;

            line[lineLength++] = ch;
            if (ch == '\n') {
                isNewLineRead = 1;
                break; // Break the loop to stop reading further
            }
        }
    }

    // Null-terminate the line
    line[lineLength] = '\0';
    return lineLength > 0 ? lineLength : -1;
}

char *get_next_line(int fd) {
	static CircularBuffer cb;
    static int is_initialized = 0;
    char *line;
    size_t line_capacity = 100000; // or any suitable size
    ssize_t line_length;


    if (!is_initialized) {
        initCircularBuffer(&cb, BUFFER_SIZE); // BUFFER_SIZE as per your requirement
		if (!cb.buffer) {
			freeCircularBuffer(&cb);
			return NULL;
		}
        is_initialized = 1;
    }

	if (fd < 0) {
		// freeCircularBuffer(&cb);
		return NULL;
	}


    line = malloc(line_capacity);
    if (!line) {
		freeCircularBuffer(&cb);
		free(line);
		is_initialized = 0;
        return NULL;
    }

    line_length = readLine(fd, line, line_capacity);
    if (line_length <= 0) {
        free(line);
		freeCircularBuffer(&cb);
		is_initialized = 0;
        return NULL;
    }

    return line;
}
