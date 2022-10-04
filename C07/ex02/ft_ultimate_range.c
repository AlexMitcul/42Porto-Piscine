/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:42:32 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/03 12:41:38 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (0);
	arr = (int *) malloc(sizeof(int) * (max - min));
	if (!arr)
		return (-1);
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	*range = arr;
	return (i);
}

/* #include <stdio.h>
#include <limits.h>
int main()
{
	int	*arr;

	printf("%d \n", ft_ultimate_range(&arr, 0, -1));
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
} */
