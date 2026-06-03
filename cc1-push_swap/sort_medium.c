/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   sort_medium.c                                         :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	chunk_size(int size)
{
	if (size <= 50)
		return (size / 5 + 1);
	if (size <= 200)
		return (size / 10 + 1);
	return (size / 16 + 1);
}

void	push_one(t_ctx *ctx, int *pushed)
{
	pb(ctx);
	(*pushed)++;
	if (ctx->b.size > 1 && ctx->b.top->value < *pushed)
		rb(ctx);
}

void	push_chunks(t_ctx *ctx)
{
	int	chunk;
	int	pushed;
	int	limit;

	chunk = chunk_size(ctx->a.size);
	pushed = 0;
	while (ctx->a.size > 0)
	{
		limit = pushed - (pushed % chunk) + chunk;
		if (ctx->a.top->value < limit)
			push_one(ctx, &pushed);
		else
			ra(ctx);
	}
}

void	pull_back(t_ctx *ctx)
{
	int	pos;

	while (ctx->b.size > 0)
	{
		pos = find_max_pos(&ctx->b);
		rotate_to_top(ctx, pos, 0);
		pa(ctx);
	}
}

void	sort_medium(t_ctx *ctx)
{
	if (ctx->a.size < 2 || is_sorted(&ctx->a))
		return ;
	if (ctx->a.size <= 3)
	{
		sort_simple(ctx);
		return ;
	}
	rank_compress(&ctx->a);
	push_chunks(ctx);
	pull_back(ctx);
}
