*This project has been created as part of the 42 curriculum by goperez-.*
## Description
This project, known as **Libft**, is a foundational C library containing a collection of re-implemented standard C library functions. The goal of the project is to deeply understand the underlying logic of these essential tools by building them from scratch. This library serves as a personal toolkit that will be used and expanded upon in future 42 projects.

## Library Functions
The library is composed of several categories of functions, ranging from character checks to memory manipulation.

## Part 1
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

## Part 2: Additional Functions
These functions are not found in the standard C library, or are implemented in a specific way to assist with common programming tasks.

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Returns a substring from string 's'. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Concatenates 's1' and 's2' into a new string. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Trims characters in 'set' from the start and end of 's1'. |
| `ft_split` | `char **ft_split(char const *s, char c)` | Splits 's' into an array of strings using 'c' as delimiter. |
| `ft_itoa` | `char *ft_itoa(int n)` | Converts an integer to a string (ASCII). |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Applies function 'f' to each character to create a new string. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char *))` | Applies function 'f' to each character of 's' in-place. |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Outputs a character to the given file descriptor. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Outputs a string to the given file descriptor. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Outputs a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Outputs an integer to the given file descriptor. |

## Part 3: Linked List
These functions allow for the manipulation of a linked list using the following structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | Creates a new list node. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | Adds a node to the beginning of the list. |
| `ft_lstsize` | `int ft_lstsize(t_list *lst)` | Counts the number of nodes in the list. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Returns the last node of the list. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | Adds a node to the end of the list. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Frees a node content and the node itself. |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | Deletes and frees an entire list. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Applies 'f' to the content of every node. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Creates a new list by applying 'f' to each node. |


## Instructions

### Installation & Compilation
To get started, clone the repository and compile the library using the included Makefile:
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
#include "libft.h"

int main(void)
{
    int val;

    // Convert string to integer
    val = ft_atoi("41");

    // Output the number + 1 to standard output
    ft_putnbr_fd(val + 1, 1);
    ft_putchar_fd('\n', 1);

    return (0);
}
```
## Resources
- Library Functions Manual
- LibftTester by Francinette/Paco

### AI Usage Disclosure
AI (Gemini 3 Flash) was used complementarily during this project for the following specific tasks:
- Documentation: Organizing function lists and prototypes into structured Markdown tables for this README.
- Problem Solving: Clarifying edge cases for memory functions (like memmove vs memcpy) and conceptualizing linked list logic.
- Code Refinement: Suggesting clean and concise code examples for the Usage section.
- Guide: Used as a reference guide for syntax verification rather than an automated agent.

