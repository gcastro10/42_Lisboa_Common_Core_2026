/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 21:25:00 by gonca             #+#    #+#             */
/*   Updated: 2026/06/05 14:40:03 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ctx *ctx)
{
	t_node	*n;

	n = stack_pop(&ctx->b);
	if (!n)
		return ;
	stack_push(&ctx->a, n);
	ctx->counts[OP_PA]++;
	put_str("pa\n", 1);
}

void	pb(t_ctx *ctx)
{
	t_node	*n;

	n = stack_pop(&ctx->a);
	if (!n)
		return ;
	stack_push(&ctx->b, n);
	ctx->counts[OP_PB]++;
	put_str("pb\n", 1);
}
