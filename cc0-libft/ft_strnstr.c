/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:31:28 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:51:15 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
	{
		return ((char *)big);
	}
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] == little[j] && (i + j) < len)
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
	char *haystack = "42 Lisboa Portugal";

	printf("Test 1: %s \n", ft_strnstr(haystack, "Lisboa", 20));
	printf("Test 2: %s \n", ft_strnstr(haystack, "Portugal", 20));
	printf("Test 3: %p \n", ft_strnstr(haystack, "Lisboa", 5));
	printf("Test 4: %s \n", ft_strnstr(haystack, "", 10));
	printf("Test 5: %p \n", ft_strnstr(haystack, "42", 1));
	return (0);
}
*/