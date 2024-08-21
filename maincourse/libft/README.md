# Libft

Libft is a custom implementation of common C standard library functions as part of the **42** curriculum. It provides a robust foundation of basic functions and utilities that are frequently needed across various C projects. The goal of this project is to gain a deeper understanding of low-level programming and build a personal library that can be reused in future projects.

## Features

This library implements functions in the following categories:

- **Memory Functions**: Memory allocation, copying, setting, and comparison.
- **String Functions**: String manipulation, comparison, searching, and conversions.
- **Character Checks**: Functions to check character types (alphanumeric, digits, etc.).
- **Linked List Utilities**: Functions to manage and manipulate linked lists.

## Functions Included

| Category | Functions |
|----------|-----------|
| Memory   | `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_bzero` |
| String   | `ft_strlen`, `ft_strcpy`, `ft_strcat`, `ft_strncmp`, `ft_strchr`, `ft_strrchr`, `ft_strnstr`, `ft_strdup`, etc. |
| Conversion | `ft_atoi`, `ft_itoa`, `ft_toupper`, `ft_tolower` |
| Character Checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Linked Lists | `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap` |

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection)
- Make (for building the library)

### Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/libft.git
    cd libft
    ```

2. Compile the library:
    ```bash
    make
    ```

3. The compiled library `libft.a` will be generated and can be linked to your C projects.

### Usage

To use `libft` in your project, include the library during the compilation step:

```bash
gcc your_code.c -L. -lft -o your_program


## Project Structure

```plaintext
libft/
│   libft.h     # Header file containing function prototypes
├── *.c         # Functions
├── Makefile    # Build instructions
└── README.md   # Project documentation
```

## Testing

You can test the library using the following tester:

```bash
bash -c "$(curl -fsSL https://raw.github.com/xicodomingues/francinette/master/bin/install.sh)"
```

## Contributing

If you wish to contribute to this project, feel free to open issues or submit pull requests. Make sure your code adheres to the project's coding standards and is properly documented.

## License

This project is licensed under the MIT License.

## Acknowledgments

This project is part of the **42** curriculum and is inspired by the need to create a robust set of reusable functions for future projects.
