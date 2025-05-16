CC=clang
NAME = push_swap
SRCS = srcs/push_swap.c srcs/push_swap_utils.c srcs/rotate_numbers.c srcs/sorting_utils.c srcs/sorting.c srcs/push_numbers.c srcs/algorithm.c srcs/algorithm_smallest.c srcs/algorithm_getpos.c srcs/algorithm_utils.c srcs/algorithm_chunk.c srcs/algorithm_chunk_two.c srcs/parsing.c srcs/parsing_utils.c
HEADER = includes/push_swap.h
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I includes
LIBFT = libft/libft.a

all:$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

clean:
	@make clean -C libft
	@rm -f $(OBJS)

re: fclean all

.PHONY: all fclean clean run run2 re
