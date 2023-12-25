#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


/* BASIC USAGE */

// int main() {
//     char *args[] = {"/bin/ls", NULL}; // Argument list must end with NULL
//     execv("/bin/ls", args); // Replaces the current process with /bin/ls
// 	// we don't need to check for an error
//     perror("execv"); // This will only execute if execv fails
//     return EXIT_FAILURE;
// }



/* CLA version */

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [arguments...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // The command to run is the first argument. The rest are its arguments.
    // execvp expects the first element of the argument array to be the command.
    execvp(argv[1], &argv[1]);

    // If execvp returns, an error occurred
    perror("execvp");
    return EXIT_FAILURE;
}


/* ENVIRONMENT VARIABLES */

// int main() {
//     char *args[] = {"/usr/bin/env", NULL};
//     char *envp[] = {"HOME=/myhome", "PATH=/bin:/usr/bin", NULL};

//     execve("/usr/bin/env", args, envp); // execve allows specifying env variables
//     perror("execve");
//     return EXIT_FAILURE;
// }



/* CREATE A NEW PROCESS */

// int main() {
//     pid_t pid = fork();

//     if (pid < 0) {
//         perror("fork");
//         return EXIT_FAILURE;
//     }

//     if (pid == 0) { // Child process
//         char *args[] = {"/bin/ls", "-l", NULL};
//         execv("/bin/ls", args);
//         perror("execv");
//         exit(EXIT_FAILURE); // Exit if execv fails
//     } else { // Parent process
//         wait(NULL); // Wait for the child process to complete
//     }

//     return EXIT_SUCCESS;
// }


/* PASS ARGUMENTS */

// int main() {
//     char *args[] = {"/bin/ls", "-l", "/", NULL}; // Includes arguments for ls
//     execv("/bin/ls", args);
//     perror("execv");
//     return EXIT_FAILURE;
// }
