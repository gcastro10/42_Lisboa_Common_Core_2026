#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    // int     fd;
    char    *line;
    // int     count;

  /*   // Test 1: Reading from a file
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    
    printf("--- Reading from test.txt ---\n");
    count = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: [%s]", count++, line);
        free(line);
    }
    close(fd); */

    // Test 2: Reading from Standard Input (Keyboard)
    printf("\n--- Reading from Stdin (Type something then Ctrl+D) ---\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("You typed: %s", line);
        free(line);
    }

    return (0);
}