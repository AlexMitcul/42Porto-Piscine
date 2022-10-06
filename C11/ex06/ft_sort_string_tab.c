/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:19:17 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/06 20:43:13 by amitcul          ###   ########.fr       */
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

static int	ft_strcmp(char *s1, char *s2)
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
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j += 1;
		}
		i += 1;
	}
}

/*#include <string.h>
#include <stdio.h>
int	main(void)
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
} */
