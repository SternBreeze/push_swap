NAME = libft.a
SRC = mem/ft_*.c math/*.c str/ft_*.c print/ft_*.c gnl/get_next_line.c \
ADT/stack.c ADT/stack2.c ADT/queue.c ADT/list/list.c ADT/list/list_int.c \
ADT/list/list_extract.c ADT/list/list_add.c
OBJ = *.o
GCCFLAGS = -Wall -Wextra -Werror -g -I ./includes/ -c
.SILENT:
all: $(NAME)
$(NAME): $(SRC)
	gcc $(GCCFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
