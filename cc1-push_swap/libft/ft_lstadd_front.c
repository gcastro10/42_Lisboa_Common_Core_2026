/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonca <gonca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:51:48 by gonca             #+#    #+#             */
/*   Updated: 2026/03/24 18:25:48 by gonca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}

/* // --- Test Main ---
#include <stdio.h>
int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;

	head = NULL;
	node1 = ft_lstnew("First Node");
	node2 = ft_lstnew("New Front Node");

	// Add the first one
	ft_lstadd_front(&head, node1);
	// Add the second one to the front
	ft_lstadd_front(&head, node2);

	// Now head points to node2, and node2->next points to node1
	t_list *temp = head;
	while (temp)
	{
		printf("Content: %s\n", (char *)temp->content);
		temp = temp->next;
	}
	return (0);
} */