/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:51:28 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:33:22 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	printf("Testing 'A': %d (Expected: 1)\n", ft_isalpha('A'));
	printf("Testing 'z': %d (Expected: 1)\n", ft_isalpha('z'));
	printf("Testing '5': %d (Expected: 0)\n", ft_isalpha('5'));
	printf("Testing '!': %d (Expected: 0)\n", ft_isalpha('!'));
	return (0);
}
*/