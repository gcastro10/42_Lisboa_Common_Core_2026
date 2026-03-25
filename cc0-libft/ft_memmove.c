/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonca <gonca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:34:02 by gonca             #+#    #+#             */
/*   Updated: 2026/02/23 19:22:44 by gonca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	if (!dest && !src)
	{
		return (NULL);
	}
	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (destination < source)
	{
		i = 0;
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	else if (destination > source)
	{
		i = n;
		while (i > 0)
		{
			i--;
			destination[i] = source[i];
		}
	}
	return (dest);
}
