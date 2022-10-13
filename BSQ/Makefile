NAME = bsq

SRC =	srcs/main.c srcs/map.c srcs/ft_atoi.c \
		srcs/file_works.c srcs/ft_split.c srcs/ft_strlen.c \
		srcs/ft_strdup.c srcs/check_borders.c srcs/ft_putstr.c \
		srcs/heatmap.c srcs/solve.c srcs/free.c \
		srcs/ft_putchar.c srcs/print.c srcs/validate_map.c \
		srcs/ft_putstr_fd.c srcs/ft_putchar_fd.c srcs/ft_putnbr.c \
		srcs/standart_input.c srcs/is_printable.c srcs/parse.c

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	gcc -Wall -Wextra -Werror -c -I includes $(SRC)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
