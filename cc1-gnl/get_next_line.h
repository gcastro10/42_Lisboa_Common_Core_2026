/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:28:36 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/01 17:19:23 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

// Default Buffer Size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000000
# endif
// Main function
char	*get_next_line(int fd);

// Utility functions
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	update_buffer(char *buffer, char *line, int start);
char	*read_and_store(int fd, char *line, char *buffer);

#endif