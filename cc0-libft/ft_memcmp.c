/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:14:55 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:35:59 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	printf("Test 1: %d (Expected: 0)\n", ft_memcmp("abc", "abc", 3));
	printf("Test 2: %d (Expected: <0)\n", ft_memcmp("aba", "abc", 3));
	printf("Test 3: %d (Expected: >0)\n", ft_memcmp("abc", "aba", 3));
	printf("Test 4: %d (Expected: 0)\n", ft_memcmp("abc", "abd", 2));
	printf("Test 5: %d (Expected: >0)\n", ft_memcmp("\xff", "\xaa", 1));
	return (0);
}
*/