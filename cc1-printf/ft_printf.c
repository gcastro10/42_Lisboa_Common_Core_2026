/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:02:15 by goperez-          #+#    #+#             */
/*   Updated: 2026/05/27 17:57:24 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_specifier(va_list args, char specifier)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_digit(va_arg(args, int), 10, 0));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int), 10, 0));
	else if (specifier == 'x')
		return (ft_print_unsigned(va_arg(args, unsigned int), 16, 0));
	else if (specifier == 'X')
		return (ft_print_unsigned(va_arg(args, unsigned int), 16, 1));
	else if (specifier == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	else if (specifier == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_length;

	if (!format)
		return (-1);
	i = 0;
	total_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			total_length += ft_check_specifier(args, format[i + 1]);
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


/* int main(int argc, char const *argv[])
{
	ft_printf("%");
	char *str = "IF THIS PRINTS PROJECT FAIL";
	return 0;
}


#include <stdio.h>
#include <limits.h>
int main() {
    int res, mine, real;
	char *s = NULL;
    res = ft_printf("Mine: %d, %s, %p\n", -42, "hello", &res);
    printf("Real: %d, %s, %p\n", -42, "hello", &res);

	//Testing INT_MIN
	printf("--- Test 1: INT_MIN ---\n");
    mine = ft_printf("Mine: [%d]\n", INT_MIN);
    real =    printf("Real: [%d]\n", INT_MIN);
    printf("Return values -> Mine: %d | Real: %d\n\n", mine, real);

    printf("--- Test 2: Hexadecimal Overflow ---\n");
    // This tests if your signed int logic accidentally triggers a '-' sign
    mine = ft_printf("Mine: [%x]\n", 4294967295U);
    real =    printf("Real: [%x]\n", 4294967295U);
    printf("Return values -> Mine: %d | Real: %d\n\n", mine, real);

	//Testing Zero
    printf("--- Test 3: Zero ---\n");
    mine = ft_printf("Mine: [%d]\n", 0);
    real =    printf("Real: [%d]\n", 0);
    printf("Return values -> Mine: %d | Real: %d\n", mine, real);

	//Testing NULL
	printf("\n--- Test 4: NULL String ---\n");
    mine = ft_printf("Mine: [%s]\n", s);
    real =    printf("Real: [%s]\n", s);
    printf("Return values -> Mine: %d | Real: %d\n", mine, real);

    printf("\n--- Test 5: NULL Pointer ---\n");
    mine = ft_printf("Mine: [%p]\n", NULL);
    real =    printf("Real: [%p]\n", NULL);
    printf("Return values -> Mine: %d | Real: %d\n", mine, real);
    return 0;
}

 */