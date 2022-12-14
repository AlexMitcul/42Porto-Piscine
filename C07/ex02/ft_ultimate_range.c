/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:42:32 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/05 17:17:40 by amitcul          ###   ########.fr       */
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
	int	**arr;
	int	*arr2;

	arr = &arr2;

	printf("%d \n", ft_ultimate_range(arr, 0, 10));
	for (int i = 0; i < 10; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	return 0;
}
 */
