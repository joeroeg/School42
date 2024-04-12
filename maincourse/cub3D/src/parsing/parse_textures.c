/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:35:42 by hezhukov          #+#    #+#             */
/*   Updated: 2024/04/11 12:53:41 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_texture(t_cub *data, const char *line, int *parsed_parameters)
{
	char	*path;

	path = trim_and_validate_path(line + 3);
	if (ft_strncmp(line, "NO ", 3) == 0)
		set_north_texture(data, path, parsed_parameters);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		set_south_texture(data, path, parsed_parameters);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		set_west_texture(data, path, parsed_parameters);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		set_east_texture(data, path, parsed_parameters);
	validate_extension(path);
}

void	validate_all_texture_paths_exist(const t_config *config)
{
	if (config->north_texture[0] == '\0' || \
		config->south_texture[0] == '\0' || \
		config->west_texture[0] == '\0' || \
		config->east_texture[0] == '\0')
		exit_error_message("Error: All required textures are not specified.", \
			EXIT_FAILURE);
	if (!can_read_file(config->north_texture) || \
		!can_read_file(config->south_texture) || \
		!can_read_file(config->west_texture) || \
		!can_read_file(config->east_texture))
		exit_error_message("Error: One or more texture files cannot be read.", \
			EXIT_FAILURE);
}

char	*trim_and_validate_path(const char *line)
{
	char	*path;

	path = trim_space(line);
	if (ft_strchr(path, ' '))
		exit_error_message("Error: Invalid path", EXIT_FAILURE);
	return (path);
}

void	validate_extension(const char *path)
{
	const char	*valid_extensions[] = {".png"};

	if (check_extension(path, valid_extensions, \
	sizeof(valid_extensions) / sizeof(valid_extensions[0])) == FAILURE)
		exit_error_message("Error: Invalid file extension", EXIT_FAILURE);
}
