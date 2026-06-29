/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:00:04 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/17 18:40:00 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
	{
		return ;
	}
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
#include <stdio.h>
void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int main(void)
{
	t_list	*node1 = ft_lstnew("Hello");
	t_list	*node2 = ft_lstnew("World");

	node1->next = node2;
	ft_lstiter(node1, print_content);
	return (0);
}
*/