/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:52:50 by amitcul           #+#    #+#             */
/*   Updated: 2022/09/21 12:25:25 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_all(char i, char j, char k)
{
	ft_putchar('0' + i);
	ft_putchar('0' + j);
	ft_putchar('0' + k);
	if (i == 7 && j == 8 && k == 9)
		return ;
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				write_all(i, j, k);
				k = k + 1;
			}
			j = j + 1;
		}
		i = i + 1;
	}
}
