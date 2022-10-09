NAME = ft_cat

SRC = src/cat.c
OBJ = $(SRC:.c=.o)

all: $(OBJ)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
