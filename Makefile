NAME := push_swap
NAME_SRC := push_swap.c
BONUS := checker
BONUS_SRC := checker.c
SRC := \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	super_operations.c \
	parse.c \
	print.c \
	clean.c \
	init.c \
	sort.c \
	optimize.c \
	utility.c \
	op_utility.c \
	sort_utility.c
LIBFT_DIR := Libft
LIBFT := $(LIBFT_DIR)/libft.a
CC_FLAG := -Wall -Wextra -Werror -O3

.PHONY: all clean fclean re bonus

all: $(NAME) bonus

$(NAME): $(LIBFT)
	@cc $(CC_FLAG) $(SRC) $(NAME_SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

bonus: $(BONUS)

$(BONUS): $(LIBFT)
	@cc $(CC_FLAG) $(SRC) $(BONUS_SRC) $(LIBFT) -o $(BONUS)
