/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:11:07 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/08 23:27:32 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doop.h"

int	get_value(int a, int b, int (*f)(int, int))
{
	return (f(a, b));
}

void	calculate(int a, int b, char operation)
{
	int		(*operations[5])(int, int);
	char	operations_symbols[5];
	int		i;

	operations[0] = &addition;
	operations[1] = &substraction;
	operations[2] = &division;
	operations[3] = &multiplication;
	operations[4] = &modulo;
	operations_symbols[0] = '+';
	operations_symbols[1] = '-';
	operations_symbols[2] = '/';
	operations_symbols[3] = '*';
	operations_symbols[4] = '%';
	i = 0;
	while (i < 5)
	{
		if (operation == operations_symbols[i])
		{
			ft_putnbr(get_value(a, b, operations[i]));
			return ;
		}
		i++;
	}
	ft_putnbr(0);
}

int	main(int argc, char *argv[])
{
	int		a;
	int		b;
	char	operation;

	if (argc != 4)
		return (write_error(""));
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	operation = get_operation(argv[2]);
	if (validate_operations(b, operation))
		calculate(a, b, operation);
	write(1, "\n", 1);
	return (0);
}
