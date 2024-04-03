#include <stdio.h>
#include <stdbool.h>

#define M 8 // Height of canvas
#define N 8 // Width of canvas

// Utility function to print the canvas
void printCanvas(int canvas[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", canvas[i][j]);
        }
        printf("\n");
    }
}

// The flood fill function
void floodFill(int canvas[M][N], int x, int y, int prevColor, int newColor) {
    // Check if we are outside the canvas
    if (x < 0 || x >= M || y < 0 || y >= N) {
        return;
    }
    // Check if the current pixel is of the target color
    if (canvas[x][y] != prevColor) {
        return;
    }

    // Replace the color at (x, y)
    canvas[x][y] = newColor;

    // Recurse for north, east, south, and west directions
    floodFill(canvas, x+1, y, prevColor, newColor);
    floodFill(canvas, x-1, y, prevColor, newColor);
    floodFill(canvas, x, y+1, prevColor, newColor);
    floodFill(canvas, x, y-1, prevColor, newColor);
}

bool isEnclosed(int canvas[M][N]) {
    // Check top and bottom rows
    for (int j = 0; j < N; j++) {
        if (canvas[0][j] != 1 || canvas[M-1][j] != 1) {
            return false;
        }
    }
    // Check left and right columns
    for (int i = 0; i < M; i++) {
        if (canvas[i][0] != 1 || canvas[i][N-1] != 1) {
            return false;
        }
    }
    return true; // The canvas is fully enclosed
}

int main() {
    int canvas[M][N] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

    printf("Original Canvas:\n");
    printCanvas(canvas);

	// Check if the canvas is enclosed by walls before flood fill
    if (isEnclosed(canvas)) {
        // Start flood fill from a point inside the enclosure, for example, (1, 1)
        floodFill(canvas, 1, 1, 0, 2); // Assuming you want to fill the empty space with '2'
        printf("\nCanvas after flood fill:\n");
        printCanvas(canvas);
    } else {
        printf("The canvas is not fully enclosed by walls.\n");
    }

    return 0;
}
