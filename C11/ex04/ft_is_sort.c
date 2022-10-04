/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:22:46 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/04 15:36:24 by amitcul          ###   ########.fr       */
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

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/* #include <stdio.h>

int	is_less(int a, int b)
{
	return (a <= b);
}

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	// int arr[5] = {1, 2, 1, 4, 5};
	// int arr[5] = {1, 2, 2, 4, 5};
	int length = 5;

	printf("Result = %d\n", ft_is_sort(arr, length, &is_less));
	return (0);
} */
