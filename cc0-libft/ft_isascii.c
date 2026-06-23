/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:28:34 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:33:43 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	printf("Testing 'A' (65): %d (Expected: 1)\n", ft_isascii(65));
	printf("Testing 0: %d (Expected: 1)\n", ft_isascii(0));
	printf("Testing 127: %d (Expected: 1)\n", ft_isascii(127));
	printf("Testing 128: %d (Expected: 0)\n", ft_isascii(128));
	return (0);
}
*/