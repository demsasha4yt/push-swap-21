EXECUTABLE1=push_swap

CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
IFLAGS=-I ./includes -I ./libft/includes
LDFLAGS=

LIBFT_DIR=./libft
LIBFT_INCLUDE_DIR=$(LIBFT_DIR)/includes
INCLUDE_DIR=./includes

SRCS =		src/main_ps.c\
			src/pswap_operations/pswap_pushs.c\
			src/pswap_operations/pswap_rotations.c\
			src/pswap_operations/pswap_rrotations.c\
			src/pswap_operations/pswap_swaps.c\
			src/pswap_operations/pfuncs.c\
			src/pswap_operations/debug.c\
			src/t_stack/t_stack.c\
			src/t_stack/t_stack_operations.c\
			src/t_stack/t_stack_methods.c\
			src/t_stack/t_stack_methods_2.c\
			src/t_stack/t_stack_debug.c\
			src/args/validations.c\
			src/args/initialize.c\
			src/push_swap/push_swap.c\
			src/push_swap/push_swap_init.c\
			src/push_swap/sort_utils/median.c\
			src/push_swap/sort_utils/resolve.c\
			src/push_swap/sort_utils/utils.c\
			src/push_swap/algo.c\
			src/push_swap/quicksort/algo_quicksort.c\

OBJS = $(patsubst %.c,%.o, $(SRCS))

all: $(EXECUTABLE1)

$(EXECUTABLE1): $(OBJS)
	@echo "===>Building libft..."
	make -C $(LIBFT_DIR)
	@echo "===>Libft has been builded!"
	@echo "===>Building $(EXECUTABLE1)"
	$(CC) $(LDFLAGS) $(CFLAGS) -o $(EXECUTABLE1) $(OBJS) -lm -L $(LIBFT_DIR) -lft
	@echo "===>$(EXECUTABLE1) has been builded"

libft:

%.o: %.c
	$(CC) $(LDFLAGS) $(IFLAGS) $(CFLAGS) -o $@ -c $<

clean:

	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(EXECUTABLE1)

re: fclean all
