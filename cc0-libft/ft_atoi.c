/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:47:49 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:34:24 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

/*
#include <stdio.h>
int main(void)
{
	printf("Test 1: %d (Expected: 42)\n", ft_atoi("42"));
	printf("Test 2: %d (Expected: -42)\n", ft_atoi("   -42"));
	printf("Test 3: %d (Expected: 12345)\n", ft_atoi(" \n \t +12345ab67"));
	printf("Test 4: %d (Expected: 0)\n", ft_atoi("  --42"));
	printf("Test 5: %d (Expected: 0)\n", ft_atoi("words 42"));
	return (0);
}
*/