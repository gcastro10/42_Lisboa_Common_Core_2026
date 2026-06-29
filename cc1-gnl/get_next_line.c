/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:28:23 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/01 17:06:26 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buffer);
	line = read_and_store(fd, line, buffer);
	if (!line || *line == '\0')
	{
		buffer[0] = '\0';
		return (free(line), NULL);
	}
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	temp = ft_substr(line, 0, i + (line[i] == '\n'));
	update_buffer(buffer, line, i + (line[i] == '\n'));
	free(line);
	return (temp);
}


#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;
    int     count; 

    //Test 1: Reading from a file
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    
    count = 1;
    printf("--- Reading from test.txt ---\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", count++, line);
        free(line);
    } 
    close(fd); 
    return (0);
} 


/* 
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;
    int     count; 

    //Test 1: Reading from a file
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    printf("Line: %s", line);
    free(line); 
    close(fd); 

    return (0);
} 

*/

/* 
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    char    *line;
  
    // Test 2: Reading from Standard Input (Keyboard)
    printf("\n--- Reading from Stdin (Type something then Ctrl+D) ---\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("You typed: %s", line);
        free(line);
    } 

    return (0);
}  */
