

## Map requirements
1. **Map File Format**: The map must be in a `.cub` format.

2. **Valid Characters**: The map can only contain 6 characters:
   - `0` for an empty space,
   - `1` for a wall,
   - `N`, `S`, `E`, `W` for the player's start position and spawning orientation.

3. **Wall Enclosure**: The map must be completely surrounded by walls (`1`). If not, your program must return an error.

4. **Player Start Position**: There should be a single starting position indicated by `N`, `S`, `E`, or `W`. Multiple starting positions or the absence of a starting position is not allowed.

5. **Order of Elements**: Except for the map content, which must always be the last, each type of element can be set in any order in the file.

6. **Element Separation**: Except for the map content, each type of element can be separated by one or more empty line(s).

7. **Information Separation**: Except for the map, each type of information from an element can be separated by one or more space(s).

8. **Map Parsing**: The map must be parsed as it looks in the file. Spaces are a valid part of the map and must be handled accordingly. Any kind of map must be parsable as long as it respects the map rules.

9. **Texture and Color Configuration**: Each element (except the map) starts with a type identifier (composed of one or two characters) followed by all specific information for each object in a strict order. This includes:
   - North texture (`NO`),
   - South texture (`SO`),
   - West texture (`WE`),
   - East texture (`EA`),
   - Floor color (`F`),
   - Ceiling color (`C`).
   Each identifier is followed by specific details such as the path to the texture or RGB colors for the floor and ceiling.

10. **Error Handling**: If any misconfiguration of any kind is encountered in the file, the program must exit properly and return "Error\n" followed by an explicit error message of your choice.

This summary provides a structured framework for your map parsing feature, ensuring that you cover all necessary validations for the `.cub` file format and its contents according to the project requirements. Ensuring your parser adheres to these conditions will be crucial for the successful implementation of your `cub3D` project.



## ToDo
- [ ] Validate file extension
- [ ] Validate the file any information goes before a map
- [ ]
