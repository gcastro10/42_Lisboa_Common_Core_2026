/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:57:11 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/17 18:38:40 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del || !*lst)
	{
		return ;
	}
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

/* 
#include <stdio.h>
void	simple_del(void *content)
{
	(void)content; 
}

int main(void)
{
	t_list *node = ft_lstnew("Hello");
	
	ft_lstclear(&node, simple_del);
	
	if (node == NULL)
		printf("Clear successful\n");
	return (0);
}
*/