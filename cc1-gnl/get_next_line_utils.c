/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:28:51 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/01 16:41:01 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	res = malloc(i + j + 1);
	if (!res)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (free(s1), res);
}

void	update_buffer(char *buffer, char *line, int start)
{
	int	i;

	i = 0;
	while (line[start])
		buffer[i++] = line[start++];
	while (i < BUFFER_SIZE + 1)
		buffer[i++] = '\0';
}

char	*read_and_store(int fd, char *line, char *buffer)
{
	int	read_bytes;
	int	i;

	read_bytes = 1;
	while (read_bytes != 0)
	{
		i = 0;
		while (line && line[i])
		{
			if (line[i] == '\n')
				return (line);
			i++;
		}
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			buffer[0] = '\0';
			return (free(line), NULL);
		}
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}
