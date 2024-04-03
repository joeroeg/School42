#include "cub3d.h"

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

void printMapWithCoordinates(t_cub *data) {
    // Print column numbers for reference
    printf("   "); // Adjust spacing based on your map's width and coordinate system
    for (int j = 0; j < data->map_width; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < data->map_height; i++) {
        // Print row number
        printf("%d: ", i);
        for (int j = 0; j < data->map_width; j++) {
            printf("%c ", data->map[i][j]);
        }
        printf("\n");
    }
}

bool findAndSetPlayerStartPosition(t_cub *data) {
    for (int i = 0; i < data->map_height; i++) {
        for (int j = 0; j < data->map_width; j++) {
            if (data->map[i][j] == 'N' || data->map[i][j] == 'S' ||
                data->map[i][j] == 'E' || data->map[i][j] == 'W') {
                data->player_x = i; // Update player_x with the found row
                data->player_y = j; // Update player_y with the found column
                // printf("Player start position found at (%d, %d)\n", data->player_x, data->player_y);
                return true; // Return true indicating the player's start position was found
            }
        }
    }
    return false; // Return false if the player's start position was not found
}


