/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:34:48 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/18 16:07:02 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s || !f)
	{
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/* 
#include <stdio.h>
char	my_func(unsigned int i, char c)
{
	return (c + 1);
}

int main(void)
{
	char *res;

	res = ft_strmapi("abc", my_func);
	if (res)
	{
		printf("Original: abc\n");
		printf("Mapped:   %s\n", res);
		free(res);
	}
	return (0);
}
*/