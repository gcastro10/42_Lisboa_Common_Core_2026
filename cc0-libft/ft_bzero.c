/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:43:12 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:36:59 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* 
#include <stdio.h>
int main(void)
{
	char str[10] = "42Lisboa";

	ft_bzero(str + 2, 3);
	printf("Index 0: %c\n", str[0]);
	printf("Index 1: %c\n", str[1]);
	printf("Index 2 (bzeroed): %d\n", str[2]);
	printf("Index 5: %c\n", str[5]);
	return (0);
}
*/