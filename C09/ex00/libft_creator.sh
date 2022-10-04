#!/bin/sh

rm -rf libft.a
rm -rf *.o
gcc -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
#gcc -o ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
ar rcs libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
