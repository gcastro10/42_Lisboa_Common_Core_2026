/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   parse2.c                                              :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	set_flag(char *arg, t_ctx *ctx)
{
	if (!ft_strcmp(arg, "--simple"))
		ctx->strategy = SIMPLE;
	else if (!ft_strcmp(arg, "--medium"))
		ctx->strategy = MEDIUM;
	else if (!ft_strcmp(arg, "--complex"))
		ctx->strategy = COMPLEX;
	else if (!ft_strcmp(arg, "--adaptive"))
		ctx->strategy = ADAPTIVE;
	else if (!ft_strcmp(arg, "--bench"))
		ctx->bench_on = 1;
	else
		return (-1);
	return (0);
}
