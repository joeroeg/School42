#include "cub3d.h"

bool is_map_enclosed(t_cub *data) {
    // Check top and bottom borders
    for (int i = 0; i < strlen(data->map[0]); i++) {
        if (data->map[0][i] != '1' || data->map[data->map_height - 1][i] != '1') {
            return false;
        }
    }
    // Check left and right borders
    for (int i = 0; i < data->map_height; i++) {
        if (data->map[i][0] != '1' || data->map[i][strlen(data->map[i]) - 1] != '1') {
            return false;
        }
    }
    return true;
}


bool is_player_position_valid(t_cub *data) {
    for (int i = 0; i < data->map_height; i++) {
        for (int j = 0; data->map[i][j]; j++) {
            if (data->map[i][j] == 'N' || data->map[i][j] == 'S' ||
                data->map[i][j] == 'E' || data->map[i][j] == 'W') {
                // Check if the player's position is valid:
                // 1. Not on the first or last row/column
                // 2. Surrounded by '0' (open space) or '1' (walls), not directly next to ' ' (space)
                if (i == 0 || i == data->map_height - 1 || j == 0 || j == strlen(data->map[i]) - 1 ||
                    data->map[i-1][j] == ' ' || data->map[i+1][j] == ' ' ||
                    data->map[i][j-1] == ' ' || data->map[i][j+1] == ' ') {
                    return false;
                }
            }
        }
    }
    return true;
}


bool validate_single_start_position(t_cub *data) {
    int start_positions = 0;

    for (int i = 0; i < data->map_height; i++) {
        char *line = data->map[i];
        // Skip leading spaces for the purpose of finding start positions
        while (*line == ' ') {
            line++;
        }
        for (int j = 0; line[j]; j++) {
            if (line[j] == 'N' || line[j] == 'S' || line[j] == 'E' || line[j] == 'W') {
                start_positions++;
                if (start_positions > 1) {
                    return false;
                }
            }
        }
    }
    return start_positions == 1;
}



bool is_map_line(char *line) {
    return line && strlen(line) > 0 && (line[0] == '1' || line[0] == '0' ||
            line[0] == 'N' || line[0] == 'S' || line[0] == 'E' || line[0] == 'W');
}



bool is_line_valid(char *line) {
    if (line == NULL || *line == '\0') {
        return false; // Line is empty
    }

    bool valid_characters_only = true;
    for (int i = 0; line[i]; i++) {
        if (!(line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == 'S' ||
              line[i] == 'E' || line[i] == 'W' || line[i] == ' ')) {
            valid_characters_only = false;
            break;
        }
    }
    return valid_characters_only;
}


void validate_map_playability(t_cub *data) {
    if (!validate_single_start_position(data)) {
        exit_error_message("Map must contain exactly one player start position (N, S, E, or W).", true);
    }
    if (!is_map_enclosed(data)) {
        exit_error_message("Map is not properly enclosed by walls.", true);
    }

    if (!is_player_position_valid(data)) {
        exit_error_message("Player start position is invalid or outside playable area.", true);
    }
    for (int i = 0; i < data->map_height; i++) {
        if (!is_line_valid(data->map[i])) {
            exit_error_message("Map contains an empty line or invalid character.", true);
        }
    }
}


void parse_map(t_cub *data) {
    char *line = NULL;
    int result;
    int line_number = 0;

    // file descriptor is already at the correct position
    // after configuration parsing, we continue reading the lines for the map.
    while ((result = get_next_line(data->memory->fd, &line)) > 0) {
        if (is_map_line(line)) {
            if (line_number >= MAX_MAP_HEIGHT) {
                gc_free(line);
                exit_error_message("Map exceeds maximum height.", true);
            }
            if (strlen(line) > MAX_MAP_WIDTH) {
                gc_free(line);
                exit_error_message("Map line exceeds maximum width.", true);
            }
            strcpy(data->map[line_number], line);
            line_number++;
        }
        gc_free(line);
        line = NULL;
    }

    if (result == -1) {
        exit_error_message("Failed to read the map file.", true);
    }
    if (line_number == 0) {
        exit_error_message("No map data found in file.", true);
    }
    data->map_height = line_number;
    validate_map_playability(data);
    for (int i = 0; i < data->map_height; i++) {
        printf("%s\n", data->map[i]);
    }
}

