#include "cub3d.h"

/**
 * @brief validate_file checks if the file exists
 * @param filename is the name of the file to be validated
*/
int	validate_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (return_error_message("Error: File does not exist", FAILURE));
	if (check_extension(filename, ".cub") == FAILURE)
		exit_error_message("Error: Invalid file extension.", EXIT_FAILURE);
	if (check_empty_file(fd) == FAILURE)
		exit_error_message("Error: File is empty", EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

/**
 * @brief check_extension checks if the file has a valid extension
 * @param filename is the name of the file to be checked
 * @return SUCCESS if the file has a valid extension, otherwise FAILURE
*/
int	check_extension(const char *filename, const char *expected_extension)
{
	const char	*found_extension;

	found_extension = ft_strrchr(filename, '.');
	if (found_extension != NULL && \
		ft_strcmp(found_extension, expected_extension) == 0)
		return (SUCCESS);
	else
		return (FAILURE);
}



/**
 * @brief Checks if the given file is empty.
 * @param fd The file descriptor of the opened file.
 * @return SUCCESS if the file is not empty, otherwise FAILURE.
 */
int	check_empty_file(int fd)
{
	char	*line;
	int		result;

	result = get_next_line(fd, &line);
	if (result <= 0)
	{
		if (line != NULL)
			free(line);
		if (result == 0)
			return (FAILURE);
		else
			exit_error_message("Error: Read failed", EXIT_FAILURE);
	}
	free(line);
	return (SUCCESS);
}

