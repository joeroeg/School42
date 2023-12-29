#include "../pipex.h"

/*
main
	parse_command
		allocate space for tokens
		split tokens
		store tokens
	fork first command
		redirect input to a file (infile)
		redirect output to a pipe[w]
		execute ft_execvp
			find_path_env
			tokenize_path
			build_full_path
			executable test
				execute_command
			command_not_found
	fork second command
		redirect input to a pipe[r]
		redirect output to a file (outfile)
		execute ft_execvp
			find_path_env
			tokenize_path
			build_full_path
			executable test
				execute_command
			command_not_found
*/

char **parse_command(char *cmd) {
    char **argv = malloc((MAX_ARGS + 1) * sizeof(char *));
    if (argv == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    char *token = strtok(cmd, " ");
    while (token != NULL && i < MAX_ARGS) {
        argv[i++] = ft_strdup(token);
        token = strtok(NULL, " ");
    }
    argv[i] = NULL; // NULL-terminate the array
    return argv;
}

int main(int argc, char **argv, char **envp) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input_file> \"<cmd1>\" \"<cmd2>\" <output_file>\n", argv[0]);
        return 1;
    }

    char **cmd1_args = parse_command(argv[2]);
    char **cmd2_args = parse_command(argv[3]);

    int pipe_fds[2];
    if (pipe(pipe_fds) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t cmd1, cmd2;

    // Fork for the first command
    cmd1 = fork();
    if (cmd1 == -1) {
        perror("fork");
        return 1;
    }

    if (cmd1 == 0) {
        int infile_fd = open(argv[1], O_RDONLY);
        if (infile_fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        dup2(infile_fd, STDIN_FILENO);
        close(infile_fd);

        dup2(pipe_fds[1], STDOUT_FILENO);
        close(pipe_fds[0]);
        close(pipe_fds[1]);

        // ft_execvp(argv[2], cmd1_args, envp);
        // ft_execvp(argv[2], &argv[2], envp);
		ft_execvp(cmd1_args[0], cmd1_args, envp);

        exit(EXIT_FAILURE);
    }

    // Fork for the second command
    cmd2 = fork();
    if (cmd2 == -1) {
        perror("fork");
        return 1;
    }

    if (cmd2 == 0) {
        close(pipe_fds[1]);
        dup2(pipe_fds[0], STDIN_FILENO);
        close(pipe_fds[0]);

        int outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outfile_fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        dup2(outfile_fd, STDOUT_FILENO);
        close(outfile_fd);

        // ft_execvp(argv[3], cmd2_args, envp);
        // ft_execvp(argv[3], &argv[3], envp);
		ft_execvp(cmd2_args[0], cmd2_args, envp);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; cmd1_args[i] != NULL; i++) free(cmd1_args[i]);
    free(cmd1_args);

    for (int i = 0; cmd2_args[i] != NULL; i++) free(cmd2_args[i]);
    free(cmd2_args);

    // Parent process
    close(pipe_fds[0]);
    close(pipe_fds[1]);

    waitpid(cmd1, NULL, 0);
    waitpid(cmd2, NULL, 0);

    return 0;
}
