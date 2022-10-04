/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 00:31:12 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/04 12:22:04 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*res;

	res = (int *) malloc(sizeof(int) * length);
	if (!res)
		return (NULL);
	i = 0;
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}

/* #include <stdio.h>

int	plus_one(int x)
{
	return (x + 1);
}

int	main(void)
{
	int	length = 10;
	int	arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	*res;

	res = ft_map(arr, length, &plus_one);
	for (int i = 0; i < length; i++)
		printf("%d ", res[i]);
	printf("\n");

	return (0);
} */
