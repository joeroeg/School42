import subprocess

# Specify the C source code file and the output executable name
source_file = "your_program.c"
output_executable = "output_program"

# Compile the C program using gcc
try:
    subprocess.check_call(["gcc", source_file, "-o", output_executable])
    print("Compilation successful!")
except subprocess.CalledProcessError:
    print("Compilation failed.")
