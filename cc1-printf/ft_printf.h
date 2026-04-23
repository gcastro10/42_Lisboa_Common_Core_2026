/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonca <gonca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 17:35:09 by gonca             #+#    #+#             */
/*   Updated: 2026/03/29 18:27:34 by gonca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);

// Utility functions
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_digit(long n, int base, int uppercase);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_unsigned(unsigned long long n, int base, int uppercase);


#endif