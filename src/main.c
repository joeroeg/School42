#include "cub3d.h"

/**
 * @brief check_extension checks if the file has a valid extension
 * @param filename is the name of the file to be checked
 * @return SUCCESS if the file has a valid extension, otherwise FAILURE
*/
int	check_extension(const char *filename)
{
	const char	*extension;

	extension = ft_strrchr(filename, '.');
	if (extension != NULL && ft_strcmp(extension, ".cub") == 0)
		return (SUCCESS);
	else
		return (FAILURE);
}

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
	if (check_extension(filename) == FAILURE)
		exit_error_message("Error: Invalid file extension.", EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_error_message("Error: Invalid number of arguments.", EXIT_FAILURE);
	if (validate_file(argv[1]) == FAILURE)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
