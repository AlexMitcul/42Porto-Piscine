/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:18:01 by amitcul           #+#    #+#             */
/*   Updated: 2022/09/28 11:14:04 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	p1;
	unsigned char	p2;

	p1 = (unsigned char) *s1++;
	p2 = (unsigned char) *s2++;
	if (p1 == '\0')
		return (p1 - p2);
	while (p1 == p2 && p1 != '\0')
	{
		p1 = (unsigned char) *s1++;
		p2 = (unsigned char) *s2++;
	}
	return (p1 - p2);
}

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_strings(char **strings, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		ft_putstr(strings[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				ft_swap(&argv[j], &argv[j + 1]);
			j++;
		}
		i++;
	}
	print_strings(argv, argc);
	return (0);
}
