#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
When you have a more complex pipeline with many commands, managing the forks and pipes within a single function using nested if-else statements can become unwieldy and hard to maintain.
In practice, you would typically want to modularize the code for readability and maintainability.
One common approach to handling multiple forks and pipes in a modular way is to use loops and arrays of file descriptors for pipes.
Here's how you could structure a program to handle an arbitrary number of commands in a pipeline:

Create an Array of Pipes: For n commands, you need n - 1 pipes.
You can create an array to hold the file descriptors for these pipes.
Loop to Create Pipes and Fork: Use a loop to create the pipes and fork child processes.
For each child process, redirect the appropriate file descriptors and then exec the desired command.
Close Unneeded File Descriptors: After forking, ensure that each process closes the file descriptors that it doesn't need.
This is necessary to prevent resource leaks and ensure EOF is properly received when the last writer to a pipe closes their end.
Wait for Child Processes: The parent should wait for all child processes to finish.


In the actual implementation, you would replace the / * ... * / with the appropriate command and arguments for each process.
This outline provides a scalable way to handle multiple commands, as the logic for setting up pipes and processes is contained within a loop rather than a chain of if-else blocks.
*/

#define COMMAND_COUNT 3  // For example, "ls | grep 'txt' | sort"

int main() {
    int pipes[COMMAND_COUNT - 1][2];  // Array to hold the pipes
    pid_t pids[COMMAND_COUNT];        // Array to hold child PIDs

    // Create the pipes
    for (int i = 0; i < COMMAND_COUNT - 1; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    // Fork processes and set up redirection
    for (int i = 0; i < COMMAND_COUNT; i++) {
        pids[i] = fork();
        if (pids[i] == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pids[i] == 0) {  // Child process
            if (i > 0) {  // If not the first command, get input from the previous pipe
                dup2(pipes[i - 1][0], STDIN_FILENO);
            }
            if (i < COMMAND_COUNT - 1) {  // If not the last command, output to the next pipe
                dup2(pipes[i][1], STDOUT_FILENO);
            }
            // Close all pipe fds
            for (int j = 0; j < COMMAND_COUNT - 1; j++) {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }
            // Execute the command
            execlp(/* ... */);
            exit(EXIT_FAILURE);
        }
    }

    // Close all pipe fds in the parent
    for (int i = 0; i < COMMAND_COUNT - 1; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    // Wait for all child processes
    for (int i = 0; i < COMMAND_COUNT; i++) {
        waitpid(pids[i], NULL, 0);
    }

    return 0;
}


