/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:19:00 by goperez-          #+#    #+#             */
/*   Updated: 2026/04/18 15:59:43 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
	{
		return ;
	}
	write(fd, &c, 1);
}

/*
#include <unistd.h>
int main(void)
{
	ft_putchar_fd('4', 1);
	ft_putchar_fd('2', 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/