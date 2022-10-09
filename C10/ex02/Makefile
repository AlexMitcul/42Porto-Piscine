NAME = ft_tail

SRC =	src/ft_abs.c src/ft_atoi.c src/ft_putchar.c src/ft_putstr.c \
		src/ft_strlen.c src/print.c src/tail.c

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
