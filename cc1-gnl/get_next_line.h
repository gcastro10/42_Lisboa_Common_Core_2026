/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonca <gonca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:28:36 by gonca             #+#    #+#             */
/*   Updated: 2026/03/25 22:08:41 by gonca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// Default Buffer Size
# ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
# endif
// Main function
char	*get_next_line(int fd);

// Utility functions
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);

#endif