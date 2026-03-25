/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonca <gonca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:37:51 by gonca             #+#    #+#             */
/*   Updated: 2026/02/24 16:28:00 by gonca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	s_len;

	s_len = ft_strlen(str);
	while (s_len >= 0)
	{
		if (str[s_len] == (char)c)
		{
			return ((char *)&str[s_len]);
		}
		s_len--;
	}
	return (NULL);
}
