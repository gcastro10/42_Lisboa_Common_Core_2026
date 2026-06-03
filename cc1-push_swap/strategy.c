/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   strategy.c                                            :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	pick_strategy(int permille)
{
	if (permille < 200)
		return (SIMPLE);
	if (permille < 500)
		return (MEDIUM);
	return (COMPLEX);
}

void	dispatch_sort(t_ctx *ctx)
{
	if (ctx->strategy == ADAPTIVE)
		ctx->strategy = pick_strategy(ctx->disorder);
	if (ctx->strategy == SIMPLE)
		sort_simple(ctx);
	else if (ctx->strategy == MEDIUM)
		sort_medium(ctx);
	else
		sort_complex(ctx);
}

char	*strat_name(int strat)
{
	if (strat == SIMPLE)
		return ("simple (O(n^2))");
	if (strat == MEDIUM)
		return ("medium (O(n sqrt n))");
	return ("complex (O(n log n))");
}

long	count_total(t_ctx *ctx)
{
	long	total;
	int		i;

	total = 0;
	i = 0;
	while (i < 11)
	{
		total += ctx->counts[i];
		i++;
	}
	return (total);
}

void	print_bench(t_ctx *ctx)
{
	put_str("[bench] disorder: ", 2);
	put_uint(ctx->disorder / 10, 2);
	put_char('.', 2);
	put_uint(ctx->disorder % 10, 2);
	put_str("0%\n", 2);
	put_str("[bench] strategy: ", 2);
	put_str(strat_name(ctx->strategy), 2);
	put_str("\n[bench] total ops: ", 2);
	put_uint((unsigned int)count_total(ctx), 2);
	put_char('\n', 2);
	print_op_counts(ctx);
}
