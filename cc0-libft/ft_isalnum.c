/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:17:25 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:33:37 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (1);
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	printf("Testing 'a': %d (Expected: 1)\n", ft_isalnum('a'));
	printf("Testing 'Z': %d (Expected: 1)\n", ft_isalnum('Z'));
	printf("Testing '5': %d (Expected: 1)\n", ft_isalnum('5'));
	printf("Testing '@': %d (Expected: 0)\n", ft_isalnum('@'));
	return (0);
}
*/