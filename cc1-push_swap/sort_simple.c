/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   sort_simple.c                                         :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_2(t_ctx *ctx)
{
	if (ctx->a.top->value > ctx->a.top->next->value)
		sa(ctx);
}

void	sort_3(t_ctx *ctx)
{
	int	a;
	int	b;
	int	c;

	a = ctx->a.top->value;
	b = ctx->a.top->next->value;
	c = ctx->a.bottom->value;
	if (a > b && b < c && a < c)
		sa(ctx);
	else if (a > b && b > c)
	{
		sa(ctx);
		rra(ctx);
	}
	else if (a > b && a > c)
		ra(ctx);
	else if (a < b && b > c && a < c)
	{
		sa(ctx);
		ra(ctx);
	}
	else if (a < b && b > c && a > c)
		rra(ctx);
}

void	push_min_to_b(t_ctx *ctx)
{
	int	pos;

	pos = find_min_pos(&ctx->a);
	rotate_to_top(ctx, pos, 1);
	pb(ctx);
}

void	pa_all(t_ctx *ctx)
{
	while (ctx->b.size > 0)
		pa(ctx);
}

void	sort_simple(t_ctx *ctx)
{
	if (ctx->a.size < 2 || is_sorted(&ctx->a))
		return ;
	if (ctx->a.size == 2)
	{
		sort_2(ctx);
		return ;
	}
	while (ctx->a.size > 3)
		push_min_to_b(ctx);
	sort_3(ctx);
	pa_all(ctx);
}
