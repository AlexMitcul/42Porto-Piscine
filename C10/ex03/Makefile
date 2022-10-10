NAME = ft_hexdump

SRC =	src/main.c src/ft_putnbr_base.c src/ft_strlen.c \
		src/ft_putstr.c src/ft_putchar.c src/ft_char_is_printable.c \
		src/ft_convert_base.c src/ft_convert_base2.c

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
