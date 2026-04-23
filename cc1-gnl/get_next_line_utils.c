/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonca <gonca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:28:51 by gonca             #+#    #+#             */
/*   Updated: 2026/03/27 13:12:51 by gonca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		return (0);
	}
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
	{
		return (NULL);
	}
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if ((char)c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dest)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		return (ft_strdup(s2));
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
	{
		return (NULL);
	}
	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > ft_strlen(s + start))
	{
		len = ft_strlen(s + start);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
