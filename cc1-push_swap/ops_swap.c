/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   ops_swap.c                                            :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	do_swap(t_stack *s)
{
	t_node	*a;
	t_node	*b;

	if (!s->top || !s->top->next)
		return ;
	a = s->top;
	b = a->next;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	else
		s->bottom = a;
	b->prev = NULL;
	b->next = a;
	a->prev = b;
	s->top = b;
}

void	sa(t_ctx *ctx)
{
	do_swap(&ctx->a);
	ctx->counts[OP_SA]++;
	put_str("sa\n", 1);
}

void	sb(t_ctx *ctx)
{
	do_swap(&ctx->b);
	ctx->counts[OP_SB]++;
	put_str("sb\n", 1);
}

void	ss(t_ctx *ctx)
{
	do_swap(&ctx->a);
	do_swap(&ctx->b);
	ctx->counts[OP_SS]++;
	put_str("ss\n", 1);
}
