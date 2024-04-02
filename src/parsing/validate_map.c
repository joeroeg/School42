#include "cub3d.h"

void floodFill(char (*map)[101], int x, int y, int mapWidth, int mapHeight, bool **visited, bool *enclosed) {
    if (x < 0 || x >= mapWidth || y < 0 || y >= mapHeight) {
        // Reached outside the map, so it's not fully enclosed
        *enclosed = false;
        return;
    }
    if (map[y][x] == '1' || visited[y][x]) {
        // Hit a wall or already visited space
        return;
    }

    // Mark the space as visited
    visited[y][x] = true;

    // Recursively check adjacent spaces
    floodFill(map, x, y - 1, mapWidth, mapHeight, visited, enclosed);
    floodFill(map, x, y + 1, mapWidth, mapHeight, visited, enclosed);
    floodFill(map, x - 1, y, mapWidth, mapHeight, visited, enclosed);
    floodFill(map, x + 1, y, mapWidth, mapHeight, visited, enclosed);
}

bool is_map_enclosed(t_cub *data) {
    bool enclosed = true;

    // Initialize a visited array to keep track of visited spaces
    bool **visited = malloc(data->map_height * sizeof(bool *));
    for (int i = 0; i < data->map_height; i++) {
        visited[i] = calloc(data->map_width, sizeof(bool));
    }

    // Perform flood fill from each open space
    for (int y = 0; y < data->map_height && enclosed; y++) {
        for (int x = 0; x < data->map_width && enclosed; x++) {
            if (data->map[y][x] == '0' && !visited[y][x]) {
                floodFill(data->map, x, y, data->map_width, data->map_height, visited, &enclosed);
            }
        }
    }

    // Free the visited array
    for (int i = 0; i < data->map_height; i++) {
        free(visited[i]);
    }
    free(visited);

    return enclosed;
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
