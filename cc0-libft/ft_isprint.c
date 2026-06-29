/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:32:52 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:33:54 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
	{
		return (1);
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	printf("Testing ' ' (32): %d (Expected: 1)\n", ft_isprint(32));
	printf("Testing '~' (126): %d (Expected: 1)\n", ft_isprint(126));
	printf("Testing 'A' (65): %d (Expected: 1)\n", ft_isprint(65));
	printf("Testing '\\n' (10): %d (Expected: 0)\n", ft_isprint(10));
	return (0);
}
*/