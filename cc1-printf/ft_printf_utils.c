/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 17:41:20 by goperez-          #+#    #+#             */
/*   Updated: 2026/05/14 15:16:24 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (ft_print_str("(null)"));
	}
	while (str[i] != '\0')
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_digit(int n, int base, int uppercase)
{
	int		count;
	char	*symbols;

	count = 0;
	if (uppercase)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n == -2147483648)
		return (ft_print_str("-2147483648"));
	if (n < 0)
	{
		count += ft_print_char('-');
		n = -n;
	}
	if (n >= base)
	{
		count += ft_print_digit(n / base, base, uppercase);
	}
	count += ft_print_char(symbols[n % base]);
	return (count);
}

// Helper for unsigned hex (used by %p, %x, %X, %u)
int	ft_print_unsigned(unsigned long long n, int base, int uppercase)
{
	int		count;
	char	*symbols;

	count = 0;
	if (uppercase)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n >= (unsigned long long)base)
		count += ft_print_unsigned(n / base, base, uppercase);
	count += ft_print_char(symbols[n % base]);
	return (count);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	count;

	if (!ptr)
		return (ft_print_str("(nil)"));
	count = ft_print_str("0x");
	count += ft_print_unsigned(ptr, 16, 0);
	return (count);
}
