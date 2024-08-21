# cub3D

**Project Description:**
This project is inspired by the world-famous Wolfenstein 3D game, the first-ever first-person shooter (FPS). The goal is to create a dynamic 3D view inside a maze using ray-casting techniques, providing a first-person perspective of navigating the environment. It's a challenging graphics project designed to enhance your skills in C, mathematical algorithms, and handling graphical windows.

## Features

- **Ray-Casting Engine:** Implements a ray-casting engine to render a realistic 3D view of a maze from a first-person perspective.
- **MiniLibX Integration:** Uses MiniLibX to handle windowing, drawing, and event management.
- **Movement and Interaction:** Supports player movement (W, A, S, D keys) and camera rotation (left and right arrow keys).
- **Textured Walls:** Displays different textures depending on the wall's orientation (North, South, East, West).
- **Color Configuration:** Allows customization of floor and ceiling colors.
- **Error Handling:** Handles invalid map configurations and outputs appropriate error messages.

## Project Structure

```
cub3d/
.
├── -
├── Makefile
├── README.md
├── include
├── lib
├── maps
├── src
└── textures
```

## Usage

### Compiling the Project

Run the following command to compile the project:

```bash
make
```

### Running the Program

To run the program, use:

```bash
./cub3D path_to_map.cub
```

### Example Map Configuration (.cub file)

```plaintext
NO ./path_to_north_texture
SO ./path_to_south_texture
WE ./path_to_west_texture
EA ./path_to_east_texture

F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```

## Mandatory Requirements

- **Map Parsing:** Reads a map file in the `.cub` format and ensures it’s surrounded by walls.
- **Smooth Window Management:** Ensures smooth switching, minimizing, and resizing of the window.
- **Error Handling:** Properly exits with an error message if there’s any misconfiguration or invalid input.

## Bonus Features

- Wall collisions
- Minimap system
- Doors that can open and close
- Animated sprites
- Mouse-controlled view rotation

## Acknowledgments

This project is part of the 42 curriculum, inspired by Wolfenstein 3D and developed using the MiniLibX graphics library.
