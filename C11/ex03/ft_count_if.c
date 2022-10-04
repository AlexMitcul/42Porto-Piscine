/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:15:59 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/04 12:21:49 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			count += 1;
		i += 1;
	}
	return (count);
}

/* #include <stdio.h>

int	contains_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int main()
{
	char *tab[5] = {"abcd", "cgdj", "1as", "dasd", "asd2"};
	int	length = 5;
	printf("result = %d\n", ft_count_if(tab, length, &contains_numeric)); // 2
	return 0;
} */
