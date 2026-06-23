/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:37:51 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:50:46 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		s_len;

	s_len = ft_strlen(s);
	while (s_len > 0)
	{
		if (s[s_len] == (char)c)
		{
			return ((char *)&s[s_len]);
		}
		s_len--;
	}
	if (s[s_len] == (char)c)
	{
		return ((char *)&s[s_len]);
	}
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
	char *str = "bonjourno";

	printf("Testing 'o': %s (Expected: o)\n", ft_strrchr(str, 'o'));
	printf("Testing 'n': %s (Expected: no)\n", ft_strrchr(str, 'n'));
	printf("Testing 'b': %s (Expected: bonjourno)\n", ft_strrchr(str, 'b'));
	printf("Testing 'z': %s (Expected: (null))\n", ft_strrchr(str, 'z'));
	return (0);
}
*/