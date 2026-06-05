/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonca <gonca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:43:12 by gonca             #+#    #+#             */
/*   Updated: 2026/02/23 18:51:05 by gonca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_bzero1(void	*ptr, size_t n)
// {
// 	unsigned char	*pointer;
// 	size_t	i;

// 	pointer = (unsigned char *)ptr;
// 	i = 0;
// 	while (i < n)
// 	{
// 		pointer[i] = 0;
// 		i++;
// 	}
// }

void	ft_bzero(void *ptr, size_t n)
{
	ft_memset(ptr, 0, n);
}
