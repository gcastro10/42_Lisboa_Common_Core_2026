/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonca <gonca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:02:15 by gonca             #+#    #+#             */
/*   Updated: 2026/03/29 18:27:33 by gonca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(va_list args, char format)
{
	if (format == 'c')
	{
		return (ft_print_char(va_arg(args, int)));
	}
	else if (format == 's')
	{
		return (ft_print_str(va_arg(args, char *)));
	}
	else if (format == 'd' || format == 'i')
	{
		return (ft_print_digit(va_arg(args, int), 10, 0));
	}
	else if (format == 'u')
	{
		return (ft_print_unsigned(va_arg(args, unsigned int), 10, 0));
	}
	else if (format == 'x')
	{
		return (ft_print_unsigned(va_arg(args, unsigned int), 16, 0));
	}
	else if (format == 'X')
	{
		return (ft_print_unsigned(va_arg(args, unsigned int), 16, 1));
	}
	else if (format == 'p')
	{
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	}
	else if (format == '%')
	{
		return (ft_print_char('%'));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_length;

	i = 0;
	total_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			total_length += ft_check_format(args, format[i + 1]);
			i++;
		}
		else 
		{
			total_length += ft_print_char(format[i]);
		}
		i++;
	}
	va_end(args);
	return (total_length);
}

#include "ft_printf.h"
#include <stdio.h>

int main() {
    int res;
    res = ft_printf("Mine: %d, %s, %p\n", -42, "hello", &res);
    printf("Real: %d, %s, %p\n", -42, "hello", &res);
    return 0;
}