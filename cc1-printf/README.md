*This project has been created as part of the 42 curriculum by goperez-.*

## Description
This project, known as **ft_printf**, involves re-coding the libc's `printf` function. The goal is to create a versatile and reusable logging function that mimics the behavior of the original. This project provides a deep dive into variadic functions in C and the challenges of handling diverse data types and format specifiers.

## Supported Conversions
The library handles the following format specifiers:

| Specifier | Description |
| :--- | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string (as defined by the common C convention). |
| `%p` | Prints the void * pointer argument in hexadecimal format. |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | Prints a percent sign. |

## Algorithm and Data Structure
### Variadic Functions
The core of this project relies on the `<stdarg.h>` library. The `ft_printf` function uses a `va_list` to iterate through an indefinite number of arguments.

### Recursive Base Conversion
To handle integers, unsigned integers, and hexadecimals, a recursive algorithm was chosen for base conversion. This approach allows for:
- **Scalability:** The same logic handles base 10 and base 16.
- **Simplicity:** By using recursion, we avoid complex buffer management for string reversals, instead printing digits in the correct order as the recursion unwinds.

### Memory Management
This implementation prioritizes low memory overhead by writing directly to the standard output using the `write` system call, avoiding the need for large temporary heap allocations.

## Instructions

### Installation & Compilation
To compile the library, clone the repository and run the Makefile:
```bash
git clone <repository_url>
cd <project_folder>
make
```

### Makefile Commands
The project includes a `Makefile` that compiles the source files into a `libft.a` static library.
- To compile the library: `make`
- To remove object files: `make clean`
- To remove all generated files: `make fclean`
- To re-compile from scratch: `make re`

### Usage
To use this library in your own projects, include the header and link the library during compilation:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! The magic number is %d.\n", "42", 42);
    ft_printf("Hex: %x | Pointer: %p\n", 255, &main);
    return (0);
}
```

## Resources
- Library Functions Manual
- PrintfTester by Francinette/Paco

### AI Usage Disclosure
AI (Gemini 3 Flash) was used complementarily during this project for the following specific tasks:
- Debugging: Identifying a mismatch between the Makefile SRCS variable and the actual filenames on disk.
- Troubleshooting: Diagnosing common Makefile errors such as "No rule to make target".
- Documentation: Assisting in formatting this README to maintain consistency with previous project documentation.