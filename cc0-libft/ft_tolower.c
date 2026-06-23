/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:27:08 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/27 15:45:34 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}

/*
#include <stdio.h>
int main(void)
{
	printf("Testing 'A': %c (Expected: a)\n", ft_tolower('A'));
	printf("Testing 'Z': %c (Expected: z)\n", ft_tolower('Z'));
	printf("Testing 'a': %c (Expected: a)\n", ft_tolower('a'));
	printf("Testing '7': %c (Expected: 7)\n", ft_tolower('7'));
	return (0);
}
*/