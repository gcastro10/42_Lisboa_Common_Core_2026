/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   stack.c                                               :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}

void	stack_push(t_stack *s, t_node *n)
{
	n->prev = NULL;
	n->next = s->top;
	if (s->top)
		s->top->prev = n;
	else
		s->bottom = n;
	s->top = n;
	s->size++;
}

t_node	*stack_pop(t_stack *s)
{
	t_node	*n;

	n = s->top;
	if (!n)
		return (NULL);
	s->top = n->next;
	if (s->top)
		s->top->prev = NULL;
	else
		s->bottom = NULL;
	s->size--;
	return (n);
}

void	stack_clear(t_stack *s)
{
	t_node	*n;
	t_node	*tmp;

	n = s->top;
	while (n)
	{
		tmp = n->next;
		free(n);
		n = tmp;
	}
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

int	*stack_to_array(t_stack *s)
{
	int		*arr;
	t_node	*n;
	int		i;

	if (s->size <= 0)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * s->size);
	if (!arr)
		return (NULL);
	n = s->top;
	i = 0;
	while (n)
	{
		arr[i++] = n->value;
		n = n->next;
	}
	return (arr);
}
