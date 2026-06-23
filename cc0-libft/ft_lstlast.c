/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:48:33 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/17 18:40:41 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
#include <stdio.h>
int main(void)
{
	t_list	*node1 = ft_lstnew("First");
	t_list	*node2 = ft_lstnew("Last");
	t_list	*last;

	node1->next = node2;
	last = ft_lstlast(node1);
	
	printf("Last node content: %s\n", (char *)last->content);
	return (0);
}
*/