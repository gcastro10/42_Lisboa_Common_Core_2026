/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonca <gonca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:28:23 by gonca             #+#    #+#             */
/*   Updated: 2026/03/27 13:19:56 by gonca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_from_file(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		return (NULL);
	}
	bytes_read = 1;
	while (!ft_strchr(storage, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

static char	*extract_line(char *storage)
{
	int		i;
	char	*line;

	i = 0;
	if (!storage || !storage[i])
	{
		return (NULL);
	}
	while (storage[i] && storage[i] != '\n')
	{
		i++;
	}
	line = ft_substr(storage, 0, i + 1);
	return (line);
}

static char	*clean_storage(char *storage)
{
	int		i;
	char	*new_storage;

	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		i++;
	}
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	new_storage = ft_substr(storage, i + 1, ft_strlen(storage) - i);
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	storage = read_from_file(fd, storage);
	if (!storage)
	{
		return (NULL);
	}
	line = extract_line(storage);
	storage = clean_storage(storage);
	if (line && *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
