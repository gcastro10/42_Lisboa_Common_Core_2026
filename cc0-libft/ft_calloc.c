/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:00:14 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 18:49:56 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;

	if (nmemb != 0 && size > (size_t)-1 / nmemb)
	{
		return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (!ptr)
	{
		return (NULL);
	}
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
#include <stdio.h>
int main(void)
{
	int	*arr;
	size_t	n = 5;
	size_t	i;

	arr = (int *)ft_calloc(n, sizeof(int));
	if (!arr)
	{
		printf("Allocation failed\n");
		return (1);
	}
	
	printf("Array values (should all be 0):\n");
	i = 0;
	while (i < n)
	{
		printf("arr[%zu]: %d\n", i, arr[i]);
		i++;
	}

	free(arr);
	return (0);
}
*/