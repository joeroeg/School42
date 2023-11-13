# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

# Directories
SRC_DIR = src
INC_DIR = include
TEST_DIR = tests

# Source and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

# Test object files (excluding main from library if it exists)
TEST_SRC_FILES = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.c,$(TEST_DIR)/%.o,$(TEST_SRC_FILES))

# Library name
LIB_NAME = mylibrary

# Build targets
all: library test

# Rule to make object files from source
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to make object files for tests
$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

library: $(OBJ_FILES)
	ar rcs lib$(LIB_NAME).a $(OBJ_FILES)

test: $(TEST_OBJ_FILES) library
	$(CC) $(CFLAGS) -o test_suite $(TEST_OBJ_FILES) -L. -l$(LIB_NAME)
	./test_suite

clean:
	rm -f $(SRC_DIR)/*.o $(TEST_DIR)/*.o lib$(LIB_NAME).a test_suite

.PHONY: all library test clean
