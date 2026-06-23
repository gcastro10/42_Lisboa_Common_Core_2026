/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:57:05 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:50:24 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(src);
	if (size == 0)
	{
		return (s_len);
	}
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s_len);
}

/*
#include <stdio.h>
int main(void)
{
	char	dest[10];
	char	*src = "42 Lisboa";
	size_t	ret;

	ret = ft_strlcpy(dest, src, 10);
	printf("Dest: %s | Return: %zu (Expected: 42 Lisboa | 9)\n", dest, ret);
	ret = ft_strlcpy(dest, src, 5);
	printf("Dest: %s | Return: %zu (Expected: 42 L | 9)\n", dest, ret);
	return (0);
}
*/