/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexmitcul <alexmitcul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 00:35:47 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/04 00:42:18 by alexmitcul       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int(*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <stdlib.h>

int	is_numeric_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	int	length = 5;
	char *arr[] = {"abasd", "asdas", "asdlk", "asd", "asdas", NULL};
	printf("%d\n", ft_any(arr, &is_numeric_line));

	return (0);
}
 */
