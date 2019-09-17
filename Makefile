EXECUTABLE1=push_swap
EXECUTABLE2=checker

N_SDLARCH=SDL2-2.0.10.tar.gz


CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
IFLAGS=-I ./includes -I ./libft/includes
LDFLAGS=

D_SDL = ./SDL2-2.0.10
D_SDLINC = $(D_SDL)/include
D_SDLLIB = $(D_SDL)/lib

LIBFT_DIR=./libft
LIBFT_INCLUDE_DIR=$(LIBFT_DIR)/includes
INCLUDE_DIR=./includes

INC = $(IFLAGS) -I $(D_SDLINC)
L_SDL = `$(D_SDL)/sdl2-config --cflags --libs`

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
			./src/checker/displays/visual_display.c\
			./src/t_stack/t_stack.c\
			./src/t_stack/t_stack_minmax.c\
			./src/t_stack/t_stack_methods.c\
			./src/operations/operations.c\
			./src/utils/push_swap_initialize.c\
			./src/utils/push_swap_destroy.c\
			./src/utils/validations.c\
			./src/utils/initialize_args.c\
			./src/checker/displays/visualizer/sdl.c\
			./src/checker/displays/visualizer/render.c\

OBJS = $(patsubst %.c,%.o, $(SRCS))
OBJS2 = $(patsubst %.c,%.o, $(SRCS2))

all: push_swap checker

$(EXECUTABLE1): $(OBJS)
	@echo "===>Building libft for push_swap if needed..."
	make -C $(LIBFT_DIR)
	@echo "===>Libft has been builded!"
	@echo "===>Building $(EXECUTABLE1)"
	$(CC) $(LDFLAGS) $(CFLAGS) -o $(EXECUTABLE1) $(OBJS) -lm -L $(LIBFT_DIR) -lft
	@echo "===>$(EXECUTABLE1) has been builded"

$(EXECUTABLE2): $(D_SDL) $(D_SDLLIB) $(OBJS2)
	@echo "===>Building libft for checker if needed..."
	make -C $(LIBFT_DIR)
	@echo "===>Libft has been builded!"
	@echo "===>Building $(EXECUTABLE2)"
	$(CC) $(LDFLAGS) $(CFLAGS) -o $(EXECUTABLE2) $(OBJS2) -lm -L $(LIBFT_DIR) -lft -L $(D_SDLLIB) $(L_SDL)
	@echo "===>$(EXECUTABLE2) has been builded"

$(D_SDL):
	@tar -xf $(N_SDLARCH)
	@printf "Push_Swap:  %-25s$(C_CYAN)[extracted]$(C_NONE)\n" $@

$(D_SDLLIB):
	@mkdir $(D_SDLLIB)
	@printf "\n$(C_CYAN)[configuring SDL]$(C_NONE)\n"
	@cd $(D_SDL); ./configure --prefix=`pwd`/lib
	@printf "$(C_CYAN)[compiling SDL]$(C_NONE)\n"./
	@make -C $(D_SDL)
	@make -C $(D_SDL) install >/dev/null
	@printf "RTv1:  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

%.o: %.c
	$(CC) $(LDFLAGS) $(INC) $(CFLAGS) -o $@ -c $<

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)
	rm -rf $(OBJS2)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(EXECUTABLE1)
	rm -rf $(EXECUTABLE2)
re: fclean all
