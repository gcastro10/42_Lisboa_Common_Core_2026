/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   main.c                                                :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_ctx(t_ctx *ctx)
{
	int	i;

	ctx->a.top = NULL;
	ctx->a.bottom = NULL;
	ctx->a.size = 0;
	ctx->b.top = NULL;
	ctx->b.bottom = NULL;
	ctx->b.size = 0;
	ctx->bench_on = 0;
	ctx->strategy = ADAPTIVE;
	ctx->disorder = 0;
	i = 0;
	while (i < 11)
		ctx->counts[i++] = 0;
}

int	is_sorted(t_stack *a)
{
	t_node	*n;

	n = a->top;
	while (n && n->next)
	{
		if (n->value > n->next->value)
			return (0);
		n = n->next;
	}
	return (1);
}

void	run_sort(t_ctx *ctx)
{
	if (ctx->a.size < 2)
	{
		if (ctx->bench_on)
			print_bench(ctx);
		return ;
	}
	ctx->disorder = compute_disorder(&ctx->a);
	dispatch_sort(ctx);
	if (ctx->bench_on)
		print_bench(ctx);
}

void	free_ctx(t_ctx *ctx)
{
	stack_clear(&ctx->a);
	stack_clear(&ctx->b);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	init_ctx(&ctx);
	if (parse_args(argc, argv, &ctx))
	{
		free_ctx(&ctx);
		put_error();
		return (1);
	}
	run_sort(&ctx);
	free_ctx(&ctx);
	return (0);
}
