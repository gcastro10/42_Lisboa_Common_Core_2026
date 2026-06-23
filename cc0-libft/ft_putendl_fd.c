/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:25:00 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/18 16:00:41 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
	{
		return ;
	}
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

/* 
int main(void)
{
	ft_putendl_fd("Hello 42", 1);
	ft_putendl_fd("Lisboa", 1);
	return (0);
}
 */