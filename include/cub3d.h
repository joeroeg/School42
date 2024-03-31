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
# define MAX_MAP_WIDTH  100
# define MAX_MAP_HEIGHT 100

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
	int				fd;
	struct s_mblock	*next;
}	t_mblock;

typedef struct s_config
{
	char	north_texture[MAX_PATH_LENGTH];
	char	south_texture[MAX_PATH_LENGTH];
	char	east_texture[MAX_PATH_LENGTH];
	char	west_texture[MAX_PATH_LENGTH];
	int		floor_color_r;
	int		floor_color_g;
	int		floor_color_b;
	int		ceiling_color_r;
	int		ceiling_color_g;
	int		ceiling_color_b;
	int		north_set;
	int		south_set;
	int		east_set;
	int		west_set;
	int		floor_set;
	int		ceiling_set;
}	t_config;

typedef struct s_cub
{
	char		*file;
	t_mblock	*memory;
	t_config	config;
	char		map[MAX_MAP_HEIGHT][MAX_MAP_WIDTH + 1];
	int			map_height;
	int			found_map;
}	t_cub;

// Memory management
t_mblock	*garbage_collector(void);
void		*gc_malloc(size_t size);
void		*gc_calloc(size_t count, size_t size);
void		gc_free(void *address);
void		gc_free_all(void);
int			gc_open(const char *pathname, int flags, mode_t mode);
char		*ft_strjoin_gc(char *s1, char *s2);
char		*ft_strdup_gc(const char *s);
char		**ft_split_gc(char const *s, char c);

// Validation
void		validate_map_file(t_cub *data);
int			check_extension(const char *filename, \
			const char *valid_extensions[], int num_extensions);
int			check_empty_file(int fd);

// Utilities
void		exit_error_message(char *message, int should_exit);
int			return_error_message(char *message, int return_value);
int			get_next_line(int fd, char **line);
char		*trim_space(const char *str);
int			prepare_file_descriptor(const char *file_path);
void		print_cub_config(const t_cub *data);
void		print_struct(t_cub *data);

// Parsing configuration
void		parse_map_parameters(t_cub *data);
void		parse_parameters_loop(t_cub *data, int *parsed_parameters);
void		parse_parameter(t_cub *data, \
			char *trimmed_line, int *parsed_parameters);
void		validate_all_parameters_set(int parsed_parameters);

// Parsing texture
void		parse_texture(t_cub *data, \
			const char *line, int *parsed_parameters);
bool		is_texture_line(const char *line);
void		validate_all_texture_paths_exist(const t_config *config);
bool		can_read_file(const char *path);
void		validate_extension(const char *path);
char		*trim_and_validate_path(const char *path);
void		set_north_texture(t_cub *data, \
			const char *path, int *parsed_parameters);
void		set_south_texture(t_cub *data, \
			const char *path, int *parsed_parameters);
void		set_west_texture(t_cub *data, \
			const char *path, int *parsed_parameters);
void		set_east_texture(t_cub *data, \
			const char *path, int *parsed_parameters);

// Parsing color
void		parse_color(t_cub *data, const char *line, \
			char color_type, int *parsed_parameters);
bool		is_color_line(const char *line);

// Parsing map
void		parse_map(t_cub *data);

#endif
