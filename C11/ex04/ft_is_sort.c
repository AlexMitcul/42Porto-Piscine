/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:22:46 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/06 20:43:59 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* 	* Check that array is sorted and return '1' if is it ordered,
*	* 	or '0' if isn't.
*
*	tab The array of ints.
*	length Length of array of ints.
*	int(*f)(int, int) Funtion that compare two ints.
**/

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	is_sorted;

	i = 0;
	is_sorted = 1;
	while (i < length - 1 && is_sorted)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			is_sorted = 0;
		i++;
	}
	if (!is_sorted)
	{
		i = 0;
		is_sorted = 1;
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}

/* #include <stdio.h>
#include <stdlib.h>

int		ft_less_than(int a, int b)
{
	return (b - a);
}

int		ft_more_than(int a, int b)
{
	return (a - b);
}

int		main(void)
{
	static int	tabx[] = { 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 6, 6, 7 };
	int			index;
	int			*tab;
	int			length;

	length = 10;
	tab = malloc(length * sizeof(int));
	index = 0;
	while (index < length)
	{
		tab[index] = index;
		index++;
	}
	printf("ft_is_sorted(1.........10) = %d\n", \
		ft_is_sort(tab, length, &ft_less_than));
	index = 0;
	while (index < length)
	{
		tab[length - 1 - index] = index;
		index++;
	}
	printf("is_sorted(10.........1) = %d\n", \
		ft_is_sort(tab, length, &ft_more_than));
	tab[5] = 100;
	printf("is_sorted(10...100...1) = %d\n", \
		ft_is_sort(tab, length, &ft_more_than));
	tab[5] = 4;
	tab[9] = 100;
	printf("is_sorted(10.....1.100) = %d\n", \
		ft_is_sort(tab, length, &ft_more_than));
	printf("is_sorted(.tabx.......) = %d\n", \
		ft_is_sort(tabx, 13, &ft_more_than));
	printf("is_sorted(.tabx.......) = %d\n", \
		ft_is_sort(tabx, 13, &ft_less_than));
} */
