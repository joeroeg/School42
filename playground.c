#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	// STEP 1: CREATE A PIPE
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }
    // pipefd[0] is for reading, pipefd[1] is for writing

	// STEP 2: FORK A CHILD PROCESS
    pid_t child = fork();
    if (child == -1) {
        perror("fork");
        return 1;
    }

	// STEP 3: CHILD PROCESS - REDIRECT OUTPUT TO PIPE AND EXECUTE COMMAND
    if (child == 0) { // Child process
        close(pipefd[0]); // Close unused read end

        // Redirect STDOUT to the write end of the pipe
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]); // Close the original write end

        // Execute a command
        execlp("ls", "ls", NULL);

        // execlp only returns on error
        perror("execlp");
        exit(EXIT_FAILURE);
    }

	// STEP 4: PARENT PROCESS - READ FROM PIPE
	else { // Parent process
        close(pipefd[1]); // Close unused write end

        char buffer[1024];
        ssize_t count;

        // Read data from the pipe
        while ((count = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, count);
        }

        close(pipefd[0]); // Close the read end
        wait(NULL); // Wait for the child process to finish
    }
    return 0;
}
