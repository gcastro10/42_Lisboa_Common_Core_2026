/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:18:50 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/18 16:08:31 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
	{
		return (NULL);
	}
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
	{
		start++;
	}
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
	{
		end--;
	}
	return (ft_substr(s1, start, end - start));
}

/* 
#include <stdio.h>
int main(void)
{
	char *res;

	res = ft_strtrim("...  hello world  ...", ". ");
	printf("Trimmed: |%s|\n", res);
	free(res);

	return (0);
}
*/