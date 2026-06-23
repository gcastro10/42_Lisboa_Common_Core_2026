/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:08:10 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/27 15:44:53 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(src);
	d_len = 0;
	while (dst[d_len] && d_len < size)
	{
		d_len++;
	}
	if (d_len == size)
	{
		return (size + s_len);
	}
	i = 0;
	while (src[i] != '\0' && (d_len + i + 1) < size)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}

/*
#include <stdio.h>
int main(void)
{
	char	dest[20] = "Hello";
	char	*src = " World";
	size_t	ret;

	ret = ft_strlcat(dest, src, 20);
	printf("Dest: %s | Return: %zu (Expected: Hello World | 11)\n", dest, ret);

	char	dest2[10] = "123";
	ret = ft_strlcat(dest2, "456789", 6);
	printf("Dest: %s | Return: %zu (Expected: 12345 | 9)\n", dest2, ret);
	return (0);
}
*/