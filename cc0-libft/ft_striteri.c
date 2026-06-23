/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:23:22 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/18 16:05:22 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
	{
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>
void	my_func(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = *c - 32;
}

int main(void)
{
	char str[] = "hello world";

	ft_striteri(str, my_func);
	printf("%s\n", str); // Expected: HeLlO WoRlD
	return (0);
}
*/