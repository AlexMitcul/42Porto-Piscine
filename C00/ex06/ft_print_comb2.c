/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:01:03 by amitcul           #+#    #+#             */
/*   Updated: 2022/09/21 12:26:25 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_number(char i)
{
	if (i < 10)
	{
		ft_putchar('0');
		ft_putchar('0' + i);
	}
	else
	{
		ft_putchar('0' + i / 10);
		ft_putchar('0' + i % 10);
	}
}

void	write_space(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb2(void)
{
	char	i;
	char	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			write_number(i);
			ft_putchar(' ');
			write_number(j);
			if (i != 98 || j != 99)
				write_space();
			j = j + 1;
		}
		i = i + 1;
	}
}
