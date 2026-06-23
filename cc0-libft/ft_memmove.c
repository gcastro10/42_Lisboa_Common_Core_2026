/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:34:02 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:59:50 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
	{
		return (NULL);
	}
	if (d <= s)
	{
		return (ft_memcpy(d, s, n));
	}
	while (n > 0)
	{
		n--;
		d[n] = s[n];
	}
	return (dest);
}

/*
#include <stdio.h>
int main(void)
{
	char str1[] = "123456789";
	char str2[] = "123456789";

	ft_memmove(str1 + 2, str1, 5);
	printf("Overlap Test (src < dest): %s (Expected: 121234589)\n", str1);
	ft_memmove(str2, str2 + 2, 5);
	printf("Overlap Test (src > dest): %s (Expected: 345676789)\n", str2);
	return (0);
}
*/