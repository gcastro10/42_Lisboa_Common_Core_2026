/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:49:51 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:35:23 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i] || s1[i] == '\0')
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	printf("Test 1: %d (Expected: 0)\n", ft_strncmp("abc", "abc", 3));
	printf("Test 2: %d (Expected: >0)\n", ft_strncmp("abd", "abc", 3));
	printf("Test 3: %d (Expected: <0)\n", ft_strncmp("abc", "abd", 3));
	printf("Test 4: %d (Expected: 0)\n", ft_strncmp("abc", "abd", 2));
	printf("Test 5: %d (Expected: 0)\n", ft_strncmp("test", "testss", 4));
	return (0);
}
*/