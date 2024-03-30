#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <ctype.h>
# include <errno.h>

# define MALLOC_ERROR "Error when allocating memory on the heap"
# define FAILURE 1
# define SUCCESS 0
# define MAX_PATH_LENGTH 255
# define MAX_LINE_LENGTH 512

typedef enum e_parameter_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	t_parameter_type;

typedef struct s_mblock
{
	void			*address;
	struct s_mblock	*next;
}	t_mblock;

typedef struct s_config
{
	char	north_texture[MAX_PATH_LENGTH];
	char	south_texture[MAX_PATH_LENGTH];
	char	east_texture[MAX_PATH_LENGTH];
	char	west_texture[MAX_PATH_LENGTH];
	bool	north_texture_set;
	bool	south_texture_set;
	bool	east_texture_set;
	bool	west_texture_set;
	int		floor_color_r;
	int		floor_color_g;
	int		floor_color_b;
	int		ceiling_color_r;
	int		ceiling_color_g;
	int		ceiling_color_b;
}	t_config;

typedef struct s_cub
{
	int			fd;
	char		*file;
	t_mblock	*memory;
	t_config	config;
	char		*content;
	char		**tokens;
	char		**map;
	int			found_map;
}	t_cub;

// Memory management
void	*gc_malloc(size_t size);
void	*gc_calloc(size_t count, size_t size);
void	gc_free(void *address);
void	gc_free_all(void);
char	*ft_strjoin_gc(char *s1, char *s2);
char	*ft_strdup_gc(const char *s);

// Validation
void	validate_map_file(t_cub *data);
int		check_extension(char *filename, const char *expected_extension);
int		check_empty_file(int fd);

// Utilities
void	exit_error_message(char *message, int should_exit);
int		return_error_message(char *message, int return_value);
int		get_next_line(int fd, char **line);
char	*trim_space(const char *str);
void	print_cub_config(const t_cub *data);

// Parsing
void	parse_map_parameters(t_cub *data);
void	parse_texture(t_cub *data, const char *line);
void	parse_color(t_cub *data, const char *line, char color_type);
void	parse_map(t_cub *data);

#endif
