EXECUTABLE1=push_swap
EXECUTABLE2=checker

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
			./src/utils/validations.c\
			./src/utils/initialize_args.c\
			./src/operations/operations.c\
			./src/algo_quicksort/algo_quicksort.c\
			./src/algo_quicksort/quicksort_utils.c\
			./src/algo_basic/basicsort.c\
			./src/algo_basic/basicsort_reverse.c\

SRCS2 =		./src/main_checker.c\
			./src/checker/get_next_line.c\
			./src/checker/initialize_checker.c\
			./src/checker/destroy_checker.c\
			./src/checker/t_history/t_history.c\
			./src/checker/displays/display.c\
			./src/checker/displays/default_display.c\
			./src/checker/displays/debug_display.c\
			./src/checker/displays/color_display.c\
			./src/t_stack/t_stack.c\
			./src/t_stack/t_stack_methods.c\
			./src/operations/operations.c\
			./src/utils/push_swap_initialize.c\
			./src/utils/push_swap_destroy.c\
			./src/utils/validations.c\
			./src/utils/initialize_args.c\

OBJS = $(patsubst %.c,%.o, $(SRCS))
OBJS2 = $(patsubst %.c,%.o, $(SRCS2))

all: push_swap checker

push_swap: $(OBJS)
	@echo "===>Building libft for push_swap if needed..."
	make -C $(LIBFT_DIR)
	@echo "===>Libft has been builded!"
	@echo "===>Building $(EXECUTABLE1)"
	$(CC) $(LDFLAGS) $(CFLAGS) -o $(EXECUTABLE1) $(OBJS) -lm -L $(LIBFT_DIR) -lft
	@echo "===>$(EXECUTABLE1) has been builded"

checker: $(OBJS2)
	@echo "===>Building libft for checker if needed..."
	make -C $(LIBFT_DIR)
	@echo "===>Libft has been builded!"
	@echo "===>Building $(EXECUTABLE2)"
	$(CC) $(LDFLAGS) $(CFLAGS) -o $(EXECUTABLE2) $(OBJS2) -lm -L $(LIBFT_DIR) -lft
	@echo "===>$(EXECUTABLE2) has been builded"

%.o: %.c
	$(CC) $(LDFLAGS) $(IFLAGS) $(CFLAGS) -o $@ -c $<

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)
	rm -rf $(OBJS2)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(EXECUTABLE1)
	rm -rf $(EXECUTABLE2)
re: fclean all
