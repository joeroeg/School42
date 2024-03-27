#include "cub3d.h"

/**
 * @brief error_message prints an error message to the standard error output
 * @param message is the message to be printed
 * @param should_exit flag if should exit after printing the message or no
 * @return void
*/
void	exit_error_message(char *message, int should_exit)
{
	ft_putendl_fd(message, STDERR_FILENO);
	if (should_exit == EXIT_FAILURE)
	{
		// gc_free_all();
		exit(EXIT_FAILURE);
	}
}

int	return_error_message(char *message, int return_value)
{
	ft_putendl_fd(message, STDERR_FILENO);
	return (return_value);
}
