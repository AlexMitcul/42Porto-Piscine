/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 00:22:15 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/04 12:39:02 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

/* #include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int x)
{
	ft_putchar(x + '0');
}

int	main(void)
{
	int	length = 10;
	int	arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	ft_foreach(arr, length, &ft_putnbr);
	return (0);
} */
