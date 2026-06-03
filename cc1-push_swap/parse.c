/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   parse.c                                               :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_strcmp(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (a[i] && a[i] == b[i])
		i++;
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}

int	parse_int(const char *s, int *out)
{
	long	n;
	int		i;
	int		sign;

	n = 0;
	i = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
	if (!s[i])
		return (-1);
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (s[i++] - '0');
		if (n * sign > 2147483647 || n * sign < -2147483648)
			return (-1);
	}
	if (s[i])
		return (-1);
	*out = (int)(n * sign);
	return (0);
}

int	is_duplicate(int val, t_stack *a)
{
	t_node	*n;

	n = a->top;
	while (n)
	{
		if (n->value == val)
			return (1);
		n = n->next;
	}
	return (0);
}

int	parse_one(char *arg, t_ctx *ctx)
{
	int		v;
	t_node	*n;

	if (arg[0] == '-' && arg[1] == '-')
		return (set_flag(arg, ctx));
	if (parse_int(arg, &v))
		return (-1);
	if (is_duplicate(v, &ctx->a))
		return (-1);
	n = node_new(v);
	if (!n)
		return (-1);
	stack_push(&ctx->a, n);
	return (0);
}

int	parse_args(int argc, char **argv, t_ctx *ctx)
{
	int	i;

	i = argc - 1;
	while (i >= 1)
	{
		if (parse_one(argv[i], ctx))
			return (-1);
		i--;
	}
	return (0);
}
