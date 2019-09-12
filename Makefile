EXECUTABLE1=push_swap

CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
IFLAGS=-I ./includes -I ./libft/includes
LDFLAGS=

LIBFT_DIR=./libft
LIBFT_INCLUDE_DIR=$(LIBFT_DIR)/includes
INCLUDE_DIR=./includes

SRCS =		./src/main_ps.c\
			./src/t_stack/t_stack.c\
			./src/t_stack/t_stack_methods.c\
			./src/utils/push_swap_initialize.c\
			./src/utils/push_swap_destroy.c\
			./src/utils/merge_commands.c\
			./src/utils/print_result.c\
			./src/operations/operations.c\
			./src/algo_quicksort/algo_quicksort.c\
			./src/algo_quicksort/quicksort_utils.c\
			./src/algo_basic/basicsort.c\
			./src/algo_basic/basicsort_reverse.c\

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
