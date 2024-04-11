#!/bin/bash

GREEN='\033[0;32m'
RESET='\033[0m'

map_directory="./maps/invalid_maps"
# map_directory="./maps/valid_maps"
executable="./cub3D"
map_files=$(find "$map_directory" -type f -name "*.cub")
for map_file in $map_files; do
    echo -e "${GREEN}Executing $executable with map file: $map_file${RESET}"
    $executable "$map_file"
    # echo "--------------------------------------------------------"
done

