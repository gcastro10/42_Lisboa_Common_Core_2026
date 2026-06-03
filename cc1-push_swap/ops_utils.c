/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   ops_utils.c                                           :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_min_pos(t_stack *s)
{
	t_node	*n;
	int		pos;
	int		best;
	int		i;

	n = s->top;
	pos = 0;
	best = n->value;
	i = 0;
	while (n)
	{
		if (n->value < best)
		{
			best = n->value;
			pos = i;
		}
		n = n->next;
		i++;
	}
	return (pos);
}

int	find_max_pos(t_stack *s)
{
	t_node	*n;
	int		pos;
	int		best;
	int		i;

	n = s->top;
	pos = 0;
	best = n->value;
	i = 0;
	while (n)
	{
		if (n->value > best)
		{
			best = n->value;
			pos = i;
		}
		n = n->next;
		i++;
	}
	return (pos);
}

void	do_rotate_dir(t_ctx *ctx, int up, int is_a)
{
	if (up && is_a)
		ra(ctx);
	else if (up && !is_a)
		rb(ctx);
	else if (!up && is_a)
		rra(ctx);
	else
		rrb(ctx);
}

void	rotate_to_top(t_ctx *ctx, int pos, int is_a)
{
	t_stack	*s;
	int		up;

	if (is_a)
		s = &ctx->a;
	else
		s = &ctx->b;
	up = (pos * 2 <= s->size);
	if (!up)
		pos = s->size - pos;
	while (pos-- > 0)
		do_rotate_dir(ctx, up, is_a);
}
