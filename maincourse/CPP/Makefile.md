# Example of a makefile for a C++ program

### Understanding Make and Makefiles

At its core, `make` looks for a file named `Makefile` (or `makefile`) in the current directory, which specifies how to compile and link the program. The `Makefile` contains:
- **Targets**: These are typically the names of files to generate. The special target `.PHONY` is used for actions that don't produce a file.
- **Dependencies**: Files that must be up-to-date before the target can be generated.
- **Rules**: Commands that `make` will execute to generate the target from the dependencies.

### A Simple Makefile for a C++ Project

Let's assume you have a project with the following structure:
- `main.cpp`: The main C++ source file.
- `greet.cpp`: A C++ source file containing a function to print a greeting.
- `greet.h`: The header file for `greet.cpp`.

Here's a simple `Makefile` to build this project:

```makefile
# Define the C++ compiler to use
CXX=g++

# Define any compile-time flags
CXXFLAGS=-Wall -std=c++98

# Define the target executable
TARGET=program

# Define source files
SRCS=main.cpp greet.cpp

# Define object files from source files
OBJS=$(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the target executable from the object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to generate object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean target to remove build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
```

### How This Makefile Works

- **CXX**: Specifies the C++ compiler to use, in this case, `g++`.
- **CXXFLAGS**: Flags for the compiler, such as `-Wall` for all warnings and `-std=c++98` to enforce C++98 standard.
- **TARGET**: The name of the final executable to build.
- **SRCS**: A list of source files in the project.
- **OBJS**: The object files that will be generated from the source files. The notation `$(SRCS:.cpp=.o)` automatically substitutes `.cpp` file extensions with `.o`.
- **all**: The default target, which depends on the target executable.
- **$(TARGET)**: A rule to link the object files into the final executable. The `$@` symbol refers to the target name, and the `$^` symbol refers to all dependencies of the target.
- **%.o**: A pattern rule for creating object files from source files. The `$<` symbol refers to the first dependency.
- **clean**: A special target to clean up the build directory, removing object files and the executable to allow a fresh build.

To build the project, you would navigate to the directory containing the `Makefile` and run:
```bash
make
```

To clean up build artifacts:
```bash
make clean
```

This introduction should help you get started with using `make` for compiling C++ projects. As projects grow, `Makefiles` can become more complex, handling multiple directories, libraries, and custom build steps, but the basic principles remain the same.
