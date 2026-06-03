/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   ops_rrotate.c                                         :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	do_rrotate(t_stack *s)
{
	t_node	*n;

	if (!s->top || !s->top->next)
		return ;
	n = s->bottom;
	s->bottom = n->prev;
	s->bottom->next = NULL;
	n->prev = NULL;
	n->next = s->top;
	s->top->prev = n;
	s->top = n;
}

void	rra(t_ctx *ctx)
{
	do_rrotate(&ctx->a);
	ctx->counts[OP_RRA]++;
	put_str("rra\n", 1);
}

void	rrb(t_ctx *ctx)
{
	do_rrotate(&ctx->b);
	ctx->counts[OP_RRB]++;
	put_str("rrb\n", 1);
}

void	rrr(t_ctx *ctx)
{
	do_rrotate(&ctx->a);
	do_rrotate(&ctx->b);
	ctx->counts[OP_RRR]++;
	put_str("rrr\n", 1);
}
