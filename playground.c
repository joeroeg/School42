#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pipefd[2];
    pid_t pid;

    // Create a pipe
    pipe(pipefd);

    // Fork the process
    pid = fork();

    if (pid == 0) {  // Child process
        close(pipefd[0]); // Close unused read end
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to pipe
        close(pipefd[1]); // Close write end after dup2

        execlp(argv[1], argv[1], NULL); // Execute first command
        exit(EXIT_FAILURE); // Exit if exec fails
    } else {  // Parent process
        close(pipefd[1]); // Close unused write end
        dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to pipe
        close(pipefd[0]); // Close read end after dup2

        execlp(argv[2], argv[2], NULL); // Execute second command
        exit(EXIT_FAILURE); // Exit if exec fails
    }

    return 0;
}




// int main() {

// 	// STEP 1: CREATE A PIPE
//     int pipefd[2];
//     if (pipe(pipefd) == -1) {
//         perror("pipe");
//         return 1;
//     }
//     // pipefd[0] is for reading, pipefd[1] is for writing

// 	// STEP 2: FORK A CHILD PROCESS
//     pid_t child = fork();
//     if (child == -1) {
//         perror("fork");
//         return 1;
//     }

// 	// STEP 3: CHILD PROCESS - REDIRECT OUTPUT TO PIPE AND EXECUTE COMMAND
//     if (child == 0) { // Child process
//         close(pipefd[0]); // Close unused read end

//         // Redirect STDOUT to the write end of the pipe
//         dup2(pipefd[1], STDOUT_FILENO);
//         close(pipefd[1]); // Close the original write end

//         // Execute a command
//         execlp("ls", "ls", NULL);

//         // execlp only returns on error
//         perror("execlp");
//         exit(EXIT_FAILURE);
//     }

// 	// STEP 4: PARENT PROCESS - READ FROM PIPE
// 	else { // Parent process
//         close(pipefd[1]); // Close unused write end

//         char buffer[1024];
//         ssize_t count;

//         // Read data from the pipe
//         while ((count = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
//             write(STDOUT_FILENO, buffer, count);
//         }

//         close(pipefd[0]); // Close the read end
//         wait(NULL); // Wait for the child process to finish
//     }
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/wait.h>

// int main() {
//     int pipefd[2]; // create a pipe that we will use across all processes.
//     pid_t cpid1, cpid2; // 2 commands pid's.

//     if (pipe(pipefd) == -1) {
//         perror("pipe");
//         exit(EXIT_FAILURE);
//     }

//     cpid1 = fork();
//     if (cpid1 == -1) {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }

//     if (cpid1 == 0) {    // Child 1: `ls` process
//         // Redirect stdout to the write end of the pipe
//         dup2(pipefd[1], STDOUT_FILENO);
//         close(pipefd[0]); // Close unused read end
//         close(pipefd[1]); // Close write end after duplicating

//         // Execute `ls`
//         execlp("ls", "ls", (char *) NULL);
//         // If execlp returns, it must have failed
//         perror("execlp ls");
//         exit(EXIT_FAILURE);
//     } else {
//         cpid2 = fork();
//         if (cpid2 == -1) {
//             perror("fork");
//             exit(EXIT_FAILURE);
//         }

//         if (cpid2 == 0) {    // Child 2: `grep` process
//             // Redirect stdin to the read end of the pipe
//             dup2(pipefd[0], STDIN_FILENO);
//             close(pipefd[1]); // Close unused write end
//             close(pipefd[0]); // Close read end after duplicating

//             // Execute `grep`
//             execlp("grep", "grep", "txt", (char *) NULL);
//             // If execlp returns, it must have failed
//             perror("execlp grep");
//             exit(EXIT_FAILURE);
//         } else {
//             // Parent process
//             close(pipefd[0]); // Close the read end
//             close(pipefd[1]); // Close the write end

//             // Wait for both children to exit
//             waitpid(cpid1, NULL, 0);
//             waitpid(cpid2, NULL, 0);
//         }
//     }

//     return 0;
// }


/*
1. fork current process
2. if fork = 0 -> continue in child process
3. redirect output
3. if fork != 0 -> continue in parent process
*/
