#include "cub3d.h"

/**
 * @brief validates the given file
 * @param filename is the name of the file to be validated
*/
void	validate_map_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error_message("Error: File does not exist", FAILURE);
	if (check_extension(filename, ".cub") == FAILURE)
	{
		close(fd);
		exit_error_message("Error: Invalid file extension", EXIT_FAILURE);
	}
	if (check_empty_file(fd) == FAILURE)
	{
		close(fd);
		exit_error_message("Error: File is empty", EXIT_FAILURE);
	}
	close(fd);
}

/**
 * @brief checks if the file has a valid extension
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
 * @brief checks if the file is empty
 * @param fd is the file descriptor of the file to be checked
 * @return SUCCESS if the file is not empty, otherwise FAILURE
 * @note a file is considered empty if it contains only whitespaces
 * or non-printable characters
*/
int	check_empty_file(int fd)
{
	char	*line;
	int		result;
	char	*current_char;

	result = get_next_line(fd, &line);
	while (result > 0)
	{
		current_char = line;
		while (*current_char != '\0')
		{
			if (isascii(*current_char) && !isspace(*current_char))
			{
				gc_free(line);
				return (SUCCESS);
			}
			current_char++;
		}
		gc_free(line);
		result = get_next_line(fd, &line);
	}
	if (result == 0 && line != NULL)
		gc_free(line);
	return (FAILURE);
}

