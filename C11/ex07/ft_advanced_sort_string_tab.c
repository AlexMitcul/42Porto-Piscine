/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:45:25 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/06 20:42:46 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j += 1;
		}
		i += 1;
	}
}

/* #include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char *tab[6] = {"Hello", "My", "Name", "Hallo", "world", 0};

	for (int i = 0; i < 5; i++)
		printf("%s ", tab[i]);
	printf("\n");
	ft_advanced_sort_string_tab(tab, &strcmp);
	for (int i = 0; i < 5; i++)
		printf("%s ", tab[i]);
	printf("\n");

	return 0;
} */
