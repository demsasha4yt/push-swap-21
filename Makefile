EXECUTABLE1=push_swap

CC=gcc
CFLAGS=-Wall -Wextra -Werror
IFLAGS=-I ./includes -I ./libft/includes
LDFLAGS=

LIBFT_DIR=./libft
LIBFT_INCLUDE_DIR=$(LIBFT_DIR)/includes
INCLUDE_DIR=./includes

SRCS =		main.c\
			src/push_swap.c

OBJS = $(patsubst %.c,%.o, $(SRCS))

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
