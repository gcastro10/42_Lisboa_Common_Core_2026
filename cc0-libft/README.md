## Description
This project, known as **Libft**, is a foundational C library containing a collection of re-implemented standard C library functions. The goal of the project is to deeply understand the underlying logic of these essential tools by building them from scratch. This library serves as a personal toolkit that will be used and expanded upon in future 42 projects.

## Library Functions
The library is composed of several categories of functions, ranging from character checks to memory manipulation.

### Character Checks & Conversions
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`: Verify character types.
- `ft_toupper`, `ft_tolower`: Convert character cases.

### String Manipulation
- `ft_strlen`: Calculate string length.
- `ft_strchr`, `ft_strrchr`: Locate characters in strings.
- `ft_strncmp`: Compare two strings up to a specific length.
- `ft_strnstr`: Locate a substring within a string.
- `ft_strlcpy`, `ft_strlcat`: Size-bounded string copying and concatenation.

### Memory Management
- `ft_memset`: Fill memory with a constant byte.
- `ft_bzero`: Zero out a byte string.
- `ft_memcpy`, `ft_memmove`: Copy memory areas.
- `ft_memchr`, `ft_memcmp`: Scan and compare memory blocks.
- `ft_calloc`: Allocate memory and initialize it to zero.
- `ft_strdup`: Duplicate a string using dynamic allocation.

### Standard Utilities
- `ft_atoi`: Convert a string to an integer.

## Instructions

### Compilation
The project includes a `Makefile` that compiles the source files into a `libft.a` static library.
- To compile the library: `make`
- To remove object files: `make clean`
- To remove all generated files: `make fclean`
- To re-compile from scratch: `make re`

### Usage
To use this library in your own projects, include the header and link the library during compilation:
```c
#include "libft.h"