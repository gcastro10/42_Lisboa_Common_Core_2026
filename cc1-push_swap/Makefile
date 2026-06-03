NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c utils.c parse.c parse2.c stack.c \
       ops_swap.c ops_push.c ops_rotate.c ops_rrotate.c ops_utils.c \
       disorder.c sort_simple.c sort_medium.c sort_complex.c \
       strategy.c strategy2.c

OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
