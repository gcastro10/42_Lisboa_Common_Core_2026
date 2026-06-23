/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:56:29 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/18 15:58:52 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*data = "Hello Node";
	t_list	*node = ft_lstnew(data);

	if (node)
	{
		printf("Content: %s\n", (char *)node->content);
		printf("Next: %p\n", node->next); // Should be nil/0x0
		free(node);
	}
	return (0);
}
*/