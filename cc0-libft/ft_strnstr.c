/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonca <gonca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:31:28 by gonca             #+#    #+#             */
/*   Updated: 2026/03/24 16:02:54 by gonca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
	{
		return ((char *)s1);
	}
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i + j] != '\0' && s2[j] != '\0' && s1[i + j] == s2[j] && (i + j) < n)
		{
			j++;
		}
		if (s2[j] == '\0')
		{
			return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
