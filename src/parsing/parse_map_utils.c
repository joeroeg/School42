#include "cub3d.h"

void free_and_reset_line(char **line)
{
    if (line != NULL && *line != NULL) {
        gc_free(*line);
        *line = NULL;
    }
}


int is_line_empty_or_whitespace(const char *line)
{
    if (line == NULL) {
        return 1; // Treat NULL lines as empty
    }

    for (int i = 0; line[i] != '\0'; i++) {
        if (!isspace((unsigned char)line[i])) {
            return 0; // Found a non-whitespace character
        }
    }
    return 1;
}

void trim_trailing_spaces(char *line) {
    if (line == NULL) return; // Safety check

    int len = strlen(line);
    while (len > 0 && isspace((unsigned char)line[len - 1])) {
        len--;
    }
    line[len] = '\0'; // Terminate the string, removing trailing spaces
}

bool is_map_line(char *line) {
    return line && strlen(line) > 0 && \
    (line[0] == '1' || \
    line[0] == '0' || \
    line[0] == 'N' || \
    line[0] == 'S' || \
    line[0] == 'E' || \
    line[0] == 'W');
}

bool is_line_valid(char *line) {


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
