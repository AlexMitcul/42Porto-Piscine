CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJ = ${SRC:.c=.o}

INCLUDES = includes


.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCLUDES}

libft.a: ${OBJ}
	ar rc libft.a ${OBJ}
	ranlib libft.a

all: libft.a

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf libft.a

re: fclean clean

.PHONY: all clean fclean re .c.o


