#include "cub3d.h"


// void floodFill(t_cub *data, int x, int y, char old, char new) {
//     if (x < 0 || x >= data->map_height || y < 0 || y >= data->map_width) {
//         return;
//     }
//     // Accept both '0' and the player's position as valid starting points
//     if (data->map[x][y] != old && !(data->map[x][y] == 'N' || data->map[x][y] == 'S' ||
//                                     data->map[x][y] == 'E' || data->map[x][y] == 'W')) {
//         return;
//     }
//     if (data->map[x][y] == '1')
//         return;

//     // Temporarily replace the player's position with '0' to allow flood fill
//     char originalChar = data->map[x][y]; // Save the original character
//     data->map[x][y] = new; // Perform the replacement

//     // Recurse for adjacent positions
//     floodFill(data, x + 1, y, old, new);
//     floodFill(data, x - 1, y, old, new);
//     floodFill(data, x, y + 1, old, new);
//     floodFill(data, x, y - 1, old, new);

//     // If the original character was the player's position, restore it
//     if (originalChar == 'N' || originalChar == 'S' || originalChar == 'E' || originalChar == 'W') {
//         data->map[x][y] = originalChar;
//     }
// }

bool floodFillCheckEnclosure(t_cub *data, int x, int y, char old, char new) {
    // Base case: If we're out of bounds, we've reached the edge
    if (x < 0 || x >= data->map_height || y < 0 || y >= data->map_width) {
        return true; // Indicate that the edge has been reached
    }
    if (data->map[x][y] != old && !(data->map[x][y] == 'N' || data->map[x][y] == 'S' ||
                                    data->map[x][y] == 'E' || data->map[x][y] == 'W')) {
        return false; // Indicate that the edge has not been reached
    }
    // If this spot isn't the old value, we don't need to fill it, and we haven't hit an edge
    if (data->map[x][y] == 1) {
        return false; // Indicate that the edge has not been reached
    }

    // Fill this spot
    char originalChar = data->map[x][y]; // Save the original character
    data->map[x][y] = new;

    // Recursively fill adjacent spots and check if they hit an edge
    bool edgeReached = floodFillCheckEnclosure(data, x + 1, y, old, new) ||
                       floodFillCheckEnclosure(data, x - 1, y, old, new) ||
                       floodFillCheckEnclosure(data, x, y + 1, old, new) ||
                       floodFillCheckEnclosure(data, x, y - 1, old, new);

    // If the original character was the player's position, restore it
    if (originalChar == 'N' || originalChar == 'S' || originalChar == 'E' || originalChar == 'W') {
        data->map[x][y] = originalChar;
    }

    // Return true if any recursive call hit an edge
    return edgeReached;
}

void checkPlayerEnclosure(t_cub *data) {
    bool isEnclosed = !floodFillCheckEnclosure(data, data->player_x, data->player_y, '0', '2');
    if (!isEnclosed) {
        exit_error_message("Player start position is not properly enclosed.", true);
    }
    // Restore the map by reverting '2' back to '0'
    // for (int i = 0; i < data->map_height; i++) {
    //     for (int j = 0; j < data->map_width; j++) {
    //         if (data->map[i][j] == '2') {
    //             data->map[i][j] = '0';
    //         }
    //     }
    // }
}

// bool floodFillCheckEnclosure(t_cub *data, int x, int y, char old, char new) {
//     // Out of bounds or edge reached with a non-wall character
//     if (x < 0 || x >= data->map_height || y < 0 || y >= data->map_width) {
//         return true; // Edge of the map reached
//     }
//     // Check if the current position is an edge and not a wall
//     if ((x == 0 || x == data->map_height - 1 || y == 0 || y == data->map_width - 1) && data->map[x][y] != '1') {
//         return true; // Edge is not enclosed
//     }
//     if (data->map[x][y] != old) {
//         return false; // No need to fill this spot
//     }

//     data->map[x][y] = new; // Fill this spot

//     // Recursively fill adjacent spots and check if they hit an edge
//     bool edgeReached = floodFillCheckEnclosure(data, x + 1, y, old, new) ||
//                        floodFillCheckEnclosure(data, x - 1, y, old, new) ||
//                        floodFillCheckEnclosure(data, x, y + 1, old, new) ||
//                        floodFillCheckEnclosure(data, x, y - 1, old, new);

//     // If any recursive call hit an edge, this spot should be marked as open space again
//     if (edgeReached) {
//         data->map[x][y] = old; // Revert this spot to open space
//     }

//     return edgeReached;
// }

// bool isMapEnclosed(t_cub *data) {
//     // Use a different character for the fill that's not '1' or '0'
//     return !floodFillCheckEnclosure(data, data->player_x, data->player_y, '0', '2');
// }

// // bool checkMapEnclosure(t_cub *data) {
// //     // Initialize as not reached
// //     bool edgeReached = false;

// //     // Perform flood fill from the player's position
// //     edgeReached = floodFillCheckEnclosure(data, data->player_x, data->player_y, '0', '2', ' ');

// //     // Restore the map and check for a breach
// //     for (int i = 0; i < data->map_height; i++) {
// //         for (int j = 0; j < data->map_width; j++) {
// //             if (data->map[i][j] == '2') {
// //                 // Revert the temporary fill
// //                 data->map[i][j] = '0';
// //             }
// //             // Check edges for flood fill breach
// //             if ((i == 0 || i == data->map_height - 1 || j == 0 || j == data->map_width - 1) && data->map[i][j] == '2') {
// //                 edgeReached = true;
// //             }
// //         }
// //     }

// //     // The map is not enclosed if an edge was reached
// //     return !edgeReached;
// // }



void validate_map_playability(t_cub *data) {
    printf("Original Map:\n");
    printMapWithCoordinates(data);

    if (!validate_single_start_position(data)) {
        exit_error_message("Map must contain exactly one player start position (N, S, E, or W).", true);
    }
    if (!is_player_position_valid(data)) {
        exit_error_message("Player start position is invalid or outside playable area.", true);
    }
    for (int i = 0; i < data->map_height; i++) {
        if (!is_line_valid(data->map[i])) {
            exit_error_message("Map contains an empty line or invalid character.", true);
        }
    }
    if (!findAndSetPlayerStartPosition(data)) {
        exit_error_message("Player start position was not found.", true);
    }
    checkPlayerEnclosure(data);
    printf("\nMap is valid and playable.\n");
    printMapWithCoordinates(data);
}
