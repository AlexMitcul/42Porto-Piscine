/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexmitcul <alexmitcul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:19:17 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/04 14:46:16 by alexmitcul       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

static void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	get_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i += 1;
	return (i);
}

// ! need to test
static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned int)s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;
	int	len;

	len = get_tab_len(tab);
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (strcmp(tab[j], tab[j + 1]) > 0) // change to ft_strcmp
				ft_swap(&tab[j], &tab[j + 1]);
			j += 1;
		}
		i += 1;
	}
}

int	main()
{
	char *tab[6] = {"Hello", "My", "Name", "Hallo", "world", 0};
	for (int i = 0; i < 5; i++)
		printf("%s ", tab[i]);
	printf("\n");
	ft_sort_string_tab(tab);
	for (int i = 0; i < 5; i++)
		printf("%s ", tab[i]);
	printf("\n");
	return (0);
}
