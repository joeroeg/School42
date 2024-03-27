#include "cub3d.h"

/**
 * @brief error_message prints an error message to the standard error output
 * @param message is the message to be printed
 * @param should_exit flag if should exit after printing the message or no
 * @return void
*/

void	error_message(const char *message, int should_exit)
{
	write(2, message, ft_strlen(message));
	if (should_exit == EXIT_FAILURE)
	{
		gc_free_all();
		exit(EXIT_FAILURE);
	}
}
