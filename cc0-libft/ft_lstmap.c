/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:01:30 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/17 18:43:12 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
	{
		return (NULL);
	}
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
#include <stdio.h>
void	*duplicate(void *content)
{
	return (ft_strdup((char *)content));
}

void	del(void *content)
{
	free(content);
}

int main(void)
{
	t_list *list = ft_lstnew(ft_strdup("hello"));
	t_list *new_list;

	new_list = ft_lstmap(list, duplicate, del);
	
	printf("Original: %s\n", (char *)list->content);
	printf("New List: %s\n", (char *)new_list->content);

	ft_lstclear(&list, del);
	ft_lstclear(&new_list, del);
	return (0);
}
*/