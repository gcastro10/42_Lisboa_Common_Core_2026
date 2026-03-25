/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonca <gonca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:05:46 by gonca             #+#    #+#             */
/*   Updated: 2026/02/23 19:30:01 by gonca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*pointer;
	size_t			i;

	pointer = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		if (pointer[i] == (unsigned char)c)
		{
			return ((void *)&pointer[i]);
		}
		i++;
	}
	return (NULL);
}
