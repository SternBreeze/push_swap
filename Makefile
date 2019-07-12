NAME1 = push_swap
NAME2 = checker
CFLAGS = -Wall -Wextra -Werror -g -I libft/includes/
SRC = bubble_sort.c cmd.c dual_ops.c flags.c is_sorted.c ops.c optimize.c \
parse.c  quick_sort.c select_sort.c service.c sort3.c stacks_state.c pivot.c
SRC1 = push_swap.c
SRC2 = checker.c
GEN = gen.c
OBJ = $(SRC:.c=.o)
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
LIBFT = libft/libft.a
PRINTF = libft/libftprintf.a
.SILENT:
all: $(NAME1) $(NAME2)
$(LIBFT):
	make -C libft
$(OBJ1): %.o: %.c
	gcc -c $(CFLAGS) $< -o $@
$(OBJ2): %.o: %.c
	gcc -c $(CFLAGS) $< -o $@
$(OBJ): %.o: %.c
	gcc -c $(CFLAGS) $< -o $@
$(NAME1): $(LIBFT) $(OBJ1) $(OBJ)
	gcc $(CFLAGS) $(OBJ1) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME1)
$(NAME2): $(LIBFT) $(OBJ2) $(OBJ)
	gcc $(CFLAGS) $(OBJ2) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME2)
gen: $(GEN)
	gcc $(GEN) $(CFLAGS) $(LIBFT) $(PRINTF) -o $(GEN:.c=)
clean:
	/bin/rm -rf $(OBJ1) $(OBJ2) $(OBJ)
	/bin/rm -rf *.dSYM
	make -C libft clean
fclean: clean
	/bin/rm -rf $(NAME1) $(NAME2)
	make -C libft fclean
re: fclean all
