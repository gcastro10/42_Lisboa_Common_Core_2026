/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:52:33 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/18 16:10:13 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
	{
		return (NULL);
	}
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		return (ft_strdup(""));
	}
	if (len > s_len - start)
	{
		len = s_len - start;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		return (NULL);
	}
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

/*
#include <stdio.h>
int main(void)
{
	char *res;

	// take 5 chars starting from index 7
	res = ft_substr("Hello, world!", 7, 5);
	printf("Substr: %s\n", res);
	free(res);

	// start index is out of bounds
	res = ft_substr("Hello", 10, 5);
	printf("Out of bounds: '%s'\n", res);
	free(res);

	return (0);
}
*/