/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::::*/
/*   utils.c                                               :+:      :+:    :+:*/
/*                                                       +:+ +:+         +:+  */
/*   By: gonca <gonca@student.42.fr>                   +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/06/03 21:25:00 by gonca                #+#    #+#          */
/*   Updated: 2026/06/03 21:25:00 by gonca               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	put_char(char c, int fd)
{
	write(fd, &c, 1);
}

void	put_str(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		put_char(s[i], fd);
		i++;
	}
}

void	put_uint(unsigned int n, int fd)
{
	if (n >= 10)
		put_uint(n / 10, fd);
	put_char('0' + (n % 10), fd);
}

void	put_nbr(int n, int fd)
{
	if (n < 0)
	{
		put_char('-', fd);
		put_uint((unsigned int)(-(long)n), fd);
	}
	else
		put_uint((unsigned int)n, fd);
}

void	put_error(void)
{
	write(2, "Error\n", 6);
}
