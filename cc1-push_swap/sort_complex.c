/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   sort_complex.c                                        :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	count_less(int *arr, int n, int v)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (i < n)
	{
		if (arr[i] < v)
			c++;
		i++;
	}
	return (c);
}

void	rank_compress(t_stack *a)
{
	int		*arr;
	t_node	*n;
	int		sz;

	sz = a->size;
	arr = stack_to_array(a);
	if (!arr)
		return ;
	n = a->top;
	while (n)
	{
		n->value = count_less(arr, sz, n->value);
		n = n->next;
	}
	free(arr);
}

int	max_bits(int n)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < n)
		bits++;
	return (bits);
}

void	radix_pass(t_ctx *ctx, int bit)
{
	int	size;
	int	i;

	size = ctx->a.size;
	i = 0;
	while (i < size)
	{
		if (((ctx->a.top->value >> bit) & 1) == 0)
			pb(ctx);
		else
			ra(ctx);
		i++;
	}
	pa_all(ctx);
}

void	sort_complex(t_ctx *ctx)
{
	int	bits;
	int	bit;

	if (ctx->a.size < 2 || is_sorted(&ctx->a))
		return ;
	if (ctx->a.size <= 3)
	{
		sort_simple(ctx);
		return ;
	}
	rank_compress(&ctx->a);
	bits = max_bits(ctx->a.size);
	bit = 0;
	while (bit < bits)
	{
		radix_pass(ctx, bit);
		bit++;
	}
}
