/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:52:10 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/17 18:38:37 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}

/*
#include <stdio.h>
int main(void)
{
	t_list	*list = NULL;
	t_list	*node1 = ft_lstnew("First");
	t_list	*node2 = ft_lstnew("Second");

	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);

	printf("First: %s\n", (char *)list->content);
	printf("Back:  %s\n", (char *)list->next->content);
	return (0);
}
*/