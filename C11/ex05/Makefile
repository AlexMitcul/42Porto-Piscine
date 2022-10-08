SRC = srcs/main.c srcs/ft_atoi.c srcs/operations.c srcs/parser.c srcs/print.c
OBJ = $(SRC:.c=.o)
NAME = do-op

INCLUDES = includes/do-op.h

all:
	gcc -Wall -Wextra -Werror $(SRC) -o $(NAME) -I$(INCLUDES)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean fclean

.PHONY: clean fclean re all
