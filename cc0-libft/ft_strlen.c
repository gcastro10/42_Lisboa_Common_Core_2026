/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:38:14 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:34:55 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/*
#include <stdio.h>
int main(void)
{
	printf("Testing \"Hello\": %d (Expected: 5)\n", ft_strlen("Hello"));
	printf("Testing \"\": %d (Expected: 0)\n", ft_strlen(""));
	printf("Testing \"42 Lisboa\": %d (Expected: 9)\n", ft_strlen("42 Lisboa"));
	return (0);
}
*/