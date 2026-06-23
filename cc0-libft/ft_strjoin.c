/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:11:52 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/18 16:05:14 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
	{
		return (NULL);
	}
	ft_memcpy(res, s1, s1_len);
	ft_memcpy(res + s1_len, s2, s2_len + 1);
	return (res);
}

/*
#include <stdio.h>
int main(void)
{
	char *res;

	res = ft_strjoin("Hello ", "42");
	printf("%s\n", res);
	free(res);
	return (0);
}
*/