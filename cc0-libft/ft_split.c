/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:52:09 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/29 19:28:03 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

static char	**ft_free_all(char **lst, int i)
{
	while (i > 0)
	{
		i--;
		free(lst[i]);
	}
	free(lst);
	return (NULL);
}

static char	**ft_fill(char **lst, char const *s, char c)
{
	size_t	word_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			word_len = 0;
			while (s[i + word_len] && s[i + word_len] != c)
				word_len++;
			lst[j] = ft_substr(s, (unsigned int)i, word_len);
			if (!lst[j])
				return (ft_free_all(lst, j));
			j++;
			i = i + word_len;
		}
	}
	lst[j] = NULL;
	return (lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;

	if (!s)
	{
		return (NULL);
	}
	lst = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!lst)
	{
		return (NULL);
	}
	return (ft_fill(lst, s, c));
}
