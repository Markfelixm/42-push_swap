NAME := push_swap
SRC := \
	push_swap.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	parse.c \
	utility.c \
	op_utility.c \
	sort_utility.c \
	radix.c
LIBFT_DIR := Libft
LIBFT := $(LIBFT_DIR)/libft.a
CC_FLAG := -Wall -Wextra -Werror -fsanitize=address -g -O3

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT)
	@cc $(CC_FLAG) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@make bonus -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
