#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>



// int main(int argc, char **argv)
// {
// 	int fd[2];
// 	pipe(fd);
// 	pid_t	pid = fork();
// 	if (pid == 0)
// 	{
// 		close(fd[0]);
// 		dup2(fd[1], STDOUT_FILENO);
// 		char *args1[] = {argv[1], NULL};
// 		execvp(argv[1], args1);
// 	}
// 	else if (pid > 0)
// 	{
// 		close(fd[1]);
// 		dup2(fd[0], STDIN_FILENO);
// 		char *args2[] = {argv[2], NULL};
// 		execvp(argv[2], args2);
// 	}
// }




// void execute_command(char *cmd, int in_fd, int out_fd) {
//     pid_t pid = fork();
//     if (pid == 0) { // Child process
//         if (in_fd != STDIN_FILENO) {
//             dup2(in_fd, STDIN_FILENO);
//             close(in_fd);
//         }
//         if (out_fd != STDOUT_FILENO) {
//             dup2(out_fd, STDOUT_FILENO);
//             close(out_fd);
//         }
//         execlp(cmd, cmd, (char *) NULL);
//         perror("execlp");
//         exit(EXIT_FAILURE);
//     } else if (pid > 0) {
//         if (in_fd != STDIN_FILENO) {
//             close(in_fd);
//         }
//         if (out_fd != STDOUT_FILENO) {
//             close(out_fd);
//         }
//         wait(NULL); // Wait for the child process to complete
//     } else {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }
// }

// int main(int argc, char *argv[]) {
//     if (argc < 2) {
//         fprintf(stderr, "Usage: %s <command1> <command2> <command...>\n", argv[0]);
//         return 1;
//     }

//     int in_fd = STDIN_FILENO;
//     int fd[2];

//     for (int i = 1; i < argc; i++) {
//         if (i < argc - 1) { // Not the last command
//             if (pipe(fd) < 0) {
//                 perror("pipe");
//                 exit(EXIT_FAILURE);
//             }
//             execute_command(argv[i], in_fd, fd[1]);
//             in_fd = fd[0]; // The next command reads from here
//         } else {
//             execute_command(argv[i], in_fd, STDOUT_FILENO);
//         }
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


typedef struct {
    int *pipefds;   // Array of file descriptors
    int n_pipes;    // Number of pipes
    int n_cmds;     // Number of commands
} Pipeline;


void create_pipes(int pipefds[], int n_pipes) {
    for (int i = 0; i < n_pipes; i++) {
        if (pipe(pipefds + i*2) < 0) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }
}

void execute_command(const char *cmd, Pipeline *pipeline, int index) {
    // Split the command into arguments
    char *args[10]; // assuming a max of 10 arguments for simplicity
    int argc = 0;
    char *token;
    char *tempCmd = strdup(cmd); // create a modifiable copy of cmd

    token = strtok(tempCmd, " ");
    while (token != NULL && argc < 10) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL; // null-terminate the arguments list

    // Execute the command
    if (execvp(args[0], args) < 0) {
        perror("execvp");  // Handle errors in execvp
        free(tempCmd);
        exit(EXIT_FAILURE);
    }

    free(tempCmd); // free the duplicated command string
}

void redirect_io(Pipeline *pipeline, int index) {
    if (index > 0) {
        // If this is not the first command, redirect stdin from the previous pipe
        if (dup2(pipeline->pipefds[(index - 1) * 2], STDIN_FILENO) < 0) {
            perror("dup2");  // Handle errors in dup2
            exit(EXIT_FAILURE);
        }
    }

    if (index < pipeline->n_pipes) {
        // If this is not the last command, redirect stdout to the next pipe
        if (dup2(pipeline->pipefds[index * 2 + 1], STDOUT_FILENO) < 0) {
            perror("dup2");  // Handle errors in dup2
            exit(EXIT_FAILURE);
        }
    }

    // Close all pipe file descriptors in the child process
    for (int i = 0; i < 2 * pipeline->n_pipes; i++) {
        close(pipeline->pipefds[i]);
    }
}

void cleanup_pipes_and_wait(Pipeline *pipeline) {
    // Close all pipe file descriptors
    for (int i = 0; i < 2 * pipeline->n_pipes; i++) {
        close(pipeline->pipefds[i]);
    }

    // Wait for all child processes
    for (int i = 0; i < pipeline->n_cmds; i++) {
        wait(NULL); // You can modify this to handle return status if necessary
    }
}

void execute_pipeline(char *cmds[], int n) {
    int pipefds[2 * (n - 1)];
    Pipeline pipeline = {pipefds, n - 1, n};

    create_pipes(pipeline.pipefds, pipeline.n_pipes);

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            redirect_io(&pipeline, i);
            execute_command(cmds[i], &pipeline, i);
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }

    cleanup_pipes_and_wait(&pipeline);
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command1> <command2> ... <commandN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    execute_pipeline(argv + 1, argc - 1);
    return EXIT_SUCCESS;

}

