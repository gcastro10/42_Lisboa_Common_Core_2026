/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:54:39 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/17 18:38:41 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
	{
		return ;
	}
	del(lst->content);
	free(lst);
}

/*
#include <stdio.h>
void	del(void *content)
{
	free(content);
}

int main(void)
{
	t_list *node = ft_lstnew(malloc(5)); // Allocate some content
	
	ft_lstdelone(node, del);
	printf("Node deleted.\n");
	return (0);
}
*/