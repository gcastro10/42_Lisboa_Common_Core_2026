/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:29:27 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:50:32 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
	char *str = "42 Lisboa";

	printf("Testing 'L': %s (Expected: Lisboa)\n", ft_strchr(str, 'L'));
	printf("Testing '4': %s (Expected: 42 Lisboa)\n", ft_strchr(str, '4'));
	printf("Testing '\\0': [%s] (Expected: [])\n", ft_strchr(str, '\0'));
	printf("Testing 'z': %s (Expected: (null))\n", ft_strchr(str, 'z'));
	return (0);
}
*/