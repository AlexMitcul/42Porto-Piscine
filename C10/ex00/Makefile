NAME = ft_display_file

SRC = srcs/ft_display_file.c srcs/ft_putstr.c srcs/ft_putchar.c
OBJ = $(SRC:.c=.o)

all: $(OBJ)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
