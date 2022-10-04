/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexmitcul <alexmitcul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:11:07 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/04 16:09:43 by alexmitcul       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int	validate_operations(int b, char operation)
{
	if (b == 0 && operation == '/')
		return (write_error("Stop : division by zero"));
	if (b == 0 && operation == '%')
		return (write_error("Stop : modulo by zero"));
	return (1);
}

void	calculate(int a, int b, char operation)
{
	int	(*operations[5])(int, int);
	char	operations_symbols[5];

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
