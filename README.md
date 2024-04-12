gdb ./your_program               # Start GDB with your program
set follow-fork-mode child       # Configure GDB to follow the child process
run                              # Run your program
info inferiors                   # List all processes to find IDs
inferior 2                       # Switch to the process with ID 2 (for example)
break someFunction               # Set a breakpoint in someFunction
continue                         # Continue execution until the breakpoint is hit



