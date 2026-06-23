/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:05:46 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:48:30 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pointer;
	size_t			i;

	pointer = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (pointer[i] == (unsigned char)c)
		{
			return ((void *)&pointer[i]);
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
	char str[] = "42 Lisboa";

	printf("Testing 'L': %s \n", (char *)ft_memchr(str, 'L', 9));
	printf("Testing '4': %s \n", (char *)ft_memchr(str, '4', 9));
	printf("Testing 'z': %p \n", ft_memchr(str, 'z', 9));
	printf("Testing 'o': %p \n", ft_memchr(str, 'o', 5));
	return (0);
}
*/