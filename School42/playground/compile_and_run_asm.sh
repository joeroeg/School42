#!/bin/bash

# Assemble the assembly code
nasm -f elf64 -o practice.o practice.asm

# Link the object file
ld -o practice practice.o

# Run the executable
./practice

# Remove the object file and executable
rm practice.o practice

