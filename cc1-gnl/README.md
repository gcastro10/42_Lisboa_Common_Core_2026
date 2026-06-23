*This project has been created as part of the 42 curriculum by goperez-.*

## Description
This project, known as **get_next_line**. The goal of this project is to write a function that returns a line read from a file descriptor. Whether it's a file on your system or the standard input, get_next_line allows you to read text one line at a time by utilizing static variables to "remember" what was read but not yet returned.

## Logic & Implementation
The challenge lies in the fact that the read() function might pull more data than you need for a single line.

1. Read: Read from the fd into a temporary buffer of size BUFFER_SIZE.
2. Save: Append this buffer to a static variable (the "leftover" or "stash").
3. Extract: Look for a newline character (\n) in the stash. If found, extract the line to return and keep the remaining characters in the static variable for the next call.
4. Return: Return the extracted line (including the \n if it exists).

## Justification and Explanation of Algorithm
"The implementation utilizes a three-stage modular approach centered around a static pointer.

1. Accumulation: We read data in BUFFER_SIZE chunks, appending to the static variable until a delimiter (\n) is found. This minimizes system calls while ensuring we don't lose data between function calls.

2. Precision Extraction: By isolating the extraction logic, we ensure the returned line strictly follows the subject's requirements regarding the \n character and null-termination.

3. State Preservation: The 'clean' phase ensures that any 'over-read' data (data belonging to the next line) is preserved in the static segment, providing a seamless experience for the next call to the function."

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

#### Function Prototype
```c
char *get_next_line(int fd);
```

#### Compilation
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

#### Example
```c
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("example.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
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