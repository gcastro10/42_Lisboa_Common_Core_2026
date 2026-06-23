/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:11:45 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:33:52 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
	printf("Testing '0': %d (Expected: 1)\n", ft_isdigit('0'));
	printf("Testing '9': %d (Expected: 1)\n", ft_isdigit('9'));
	printf("Testing 'a': %d (Expected: 0)\n", ft_isdigit('a'));
	printf("Testing ' ': %d (Expected: 0)\n", ft_isdigit(' '));
	return (0);
}
*/