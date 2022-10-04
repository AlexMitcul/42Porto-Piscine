

OBJ = srcs/main.o srcs/ft_atoi.o srcs/operations.o srcs/parser.o \
	srcs/print.o

INCLUDES = includes/do-op.h

do-op:
	cc -o do-op $(OBJ) -I$(INCLUDES)

all: do-op

clean:
	rm -rf do-op

fclean: clean
	rm -rf *.o

re: clean fclean all

.PHONY: clean fclean re do-op
