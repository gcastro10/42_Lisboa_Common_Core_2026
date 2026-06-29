/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:25:00 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/27 15:45:01 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

/*
#include <stdio.h>
int main(void)
{
	printf("Testing 'a': %c (Expected: A)\n", ft_toupper('a'));
	printf("Testing 'z': %c (Expected: Z)\n", ft_toupper('z'));
	printf("Testing 'A': %c (Expected: A)\n", ft_toupper('A'));
	printf("Testing '1': %c (Expected: 1)\n", ft_toupper('1'));
	return (0);
}
*/