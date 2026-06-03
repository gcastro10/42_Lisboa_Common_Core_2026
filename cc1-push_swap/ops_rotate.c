/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   ops_rotate.c                                          :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	do_rotate(t_stack *s)
{
	t_node	*n;

	if (!s->top || !s->top->next)
		return ;
	n = s->top;
	s->top = n->next;
	s->top->prev = NULL;
	n->next = NULL;
	n->prev = s->bottom;
	s->bottom->next = n;
	s->bottom = n;
}

void	ra(t_ctx *ctx)
{
	do_rotate(&ctx->a);
	ctx->counts[OP_RA]++;
	put_str("ra\n", 1);
}

void	rb(t_ctx *ctx)
{
	do_rotate(&ctx->b);
	ctx->counts[OP_RB]++;
	put_str("rb\n", 1);
}

void	rr(t_ctx *ctx)
{
	do_rotate(&ctx->a);
	do_rotate(&ctx->b);
	ctx->counts[OP_RR]++;
	put_str("rr\n", 1);
}
