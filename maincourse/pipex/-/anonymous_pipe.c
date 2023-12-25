#include <stdio.h>      // Include for standard input/output operations.
#include <stdlib.h>     // Include for standard library functions like exit().
#include <unistd.h>     // Include for POSIX APIs, essential for pipe() and fork().
#include <string.h>     // Include for string handling functions, like strlen().


/*
Outline of anonymous pipe creation

- Initialization and Pipe Creation
	- [array]   - is used to store fd for the pipe
	- [buffer]  - is used to store data from the pipe
	- [message] - is used to write a message
	- [pipe]    -
- Process Forking
	-
- Child Process Block
- Parent Process Block
*/


int main() {

	/* INITIALIZATION AND PIPE CREATION */

    int pipefds[2];         // Array to store file descriptors for the pipe.
    char buffer[1024];      // Buffer to store the data read from the pipe.
    const char *message = "Hello from child process!"; // Message to be written to the pipe.

    // Create a pipe. pipefds[0] is for reading, pipefds[1] is for writing.
	/*

	The pipe() system call creates a unidirectional communication channel.
	This channel is used for transferring data between processes, typically between a parent and a child process.
	Without this step, these processes would have no dedicated and efficient means to communicate.

	When you call pipe(pipefds), it creates two file descriptors:
	pipefds[0]: This is the read end of the pipe. Data written to the pipe can be read from this file descriptor.
	pipefds[1]: This is the write end of the pipe. Data can be written to the pipe using this file descriptor.

	Buffering Mechanism: The pipe acts as a buffer. Data written to the write end of the pipe is stored by the kernel until it is read from the read end.
	This means the sending and receiving processes do not need to be synchronized tightly.
	The sender can write at its own pace, and the receiver can read at its own pace.

	*/

    if (pipe(pipefds) == -1) {
        perror("pipe");     // Print an error message if pipe creation fails.
        exit(EXIT_FAILURE); // Exit if pipe creation fails, indicating an error.
    }

	/* PROCESS FORKING */

    pid_t pid = fork();     // Create a new process. Child process will be a clone of the parent.

    if (pid == -1) {
        perror("fork");     // Print an error message if fork fails.
        exit(EXIT_FAILURE); // Exit if fork fails, indicating an error.
    }

	/* CHILD PROCESS BLOCK */

    if (pid == 0) {
        // This block is executed by the child process.
        close(pipefds[0]);  // Close the read end, child doesn't need to read from pipe.

        // Write the message to the pipe, transferring data to the parent.
        write(pipefds[1], message, strlen(message));

        close(pipefds[1]);  // Close the write end after writing is done.
        exit(EXIT_SUCCESS); // Exit child process successfully.
    }

	/* PARENT PROCESS BLOCK */

	else {
        // This block is executed by the parent process.
        close(pipefds[1]);  // Close the write end, parent doesn't need to write to pipe.

        // Read the message from the pipe, receiving data from the child.
        read(pipefds[0], buffer, sizeof(buffer));

        close(pipefds[0]);  // Close the read end after reading is done.

        // Print the message received from the child process.
        printf("Parent read: %s\n", buffer);
    }

    return 0; // Main function executed successfully.
}
