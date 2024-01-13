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

void execute_command(char *cmd) {
    pid_t pid = fork();
    if (pid == 0) { // Child process
        execlp(cmd, cmd, (char *) NULL);
        fprintf(stderr, "Failed to execute '%s'\n", cmd);
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command1> <command2> ... <commandN>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        execute_command(argv[i]);
    }

    while (wait(NULL) > 0); // Wait for all child processes to complete

    return 0;
}


