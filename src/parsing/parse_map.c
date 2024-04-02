#include "cub3d.h"

void parse_map(t_cub *data)
{
    char *line = NULL;
    int result;
    int line_number = 0;
    int map_found = 0;
    int found_spaces = 0;


    while ((result = get_next_line(data->memory->fd, &line)) > 0)
    {
        if (!is_line_valid(line))
            exit_error_message("Error: Map contains invalid characters.", EXIT_FAILURE);
        if(!is_line_empty_or_whitespace(line))
            map_found = 1;
        if (map_found)
        {
            if (line_number >= MAX_MAP_HEIGHT)
                exit_error_message("Error: Map exceeds maximum height.", EXIT_FAILURE);
            if (strlen(line) > MAX_MAP_WIDTH)
                exit_error_message("Error: Map line exceeds maximum width.", EXIT_FAILURE);
            if (is_line_empty_or_whitespace(line))
                found_spaces = 1;
            if (found_spaces && !is_line_empty_or_whitespace(line))
                exit_error_message("Error: Map contains empty lines.", EXIT_FAILURE);
            strcpy(data->map[line_number], line);
            line_number++;
        }
        free_and_reset_line(&line);
    }
    data->map_height = line_number;
    // validate_map_playability(data);
    printf("----------------------------\n");
    for (int i = 0; i < line_number; i++)
        printf("%s\n", data->map[i]);
}
