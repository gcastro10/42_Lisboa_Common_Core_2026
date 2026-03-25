# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gonca <gonca@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 14:43:54 by gonca             #+#    #+#              #
#    Updated: 2026/02/24 15:28:46 by gonca            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Sets the name of your final output (the library)
NAME = libft.a

# Specifies the compiler you are using
CC = cc

# The cc compiler flags
CFLAGS = -Wall -Wextra -Werror

# The command used to archive files (libraries), facilitates code reuse, modularity, and faster compilation by allowing linkers to extract only necessary functions
# ".a" = static library (linux /unix); ".lib" = static library (windows); ".so" = shared object library (linux); ".dll" = dynamic link library (windows)
# "r" = replace existing files; "c" = create the library if it doesn't exist; "s" = create an index (makes the library faster to use)
AR = ar rcs
# The command to delete files. -f = force, prevents errors if the file doesn't exist.
RM = rm -f

# List of source files
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c

# Transformation of .c files into .o files. *Important note, we are not compiling it to a.out, we do a.o, which are object files. (machine code version of the .c files)
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Create the library using 'ar'
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Rule for compiling .c to .o. "$<" refers to source file (.c) and "$@" refers to the target file (.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files (deletes the .o files)
clean:
	$(RM) $(OBJS)

# Clean object files and the library (deletes the .o files by calling clean, then deletes the libft.a file for complete clean)
fclean: clean
	$(RM) $(NAME)

# Rebuild everything (re = recompile) (deletes everything first, then builds from scratch)
re: fclean all

# Phony targets to prevent conflicts with files of the same name
.PHONY: all clean fclean re