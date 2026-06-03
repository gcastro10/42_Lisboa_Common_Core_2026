/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   strategy2.c                                           :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	set_op_names(char **n)
{
	n[0] = "sa";
	n[1] = "sb";
	n[2] = "ss";
	n[3] = "pa";
	n[4] = "pb";
	n[5] = "ra";
	n[6] = "rb";
	n[7] = "rr";
	n[8] = "rra";
	n[9] = "rrb";
	n[10] = "rrr";
}

void	print_op_counts(t_ctx *ctx)
{
	char	*names[11];
	int		i;

	set_op_names(names);
	i = 0;
	while (i < 11)
	{
		put_str(names[i], 2);
		put_char(':', 2);
		put_uint((unsigned int)ctx->counts[i], 2);
		if (i < 10)
			put_char(' ', 2);
		i++;
	}
	put_char('\n', 2);
}
