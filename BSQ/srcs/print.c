/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:38:12 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/12 21:29:16 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	print_result(t_map *map, t_result *res)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if ((i >= res->x && i < res->x + res->size) && \
				(j >= res->y && j < res->y + res->size))
				ft_putchar(map->full_s);
			else
				ft_putchar(map->symbols[i][j]);
			j += 1;
		}
		ft_putchar('\n');
		i += 1;
	}
}

void	print_heat_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			ft_putnbr(map->heat_map[i][j]);
			j += 1;
		}
		ft_putchar('\n');
		i += 1;
	}
}

int	print_error(char *error)
{
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (0);
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		ft_putstr(map->symbols[i]);
		ft_putstr("\n");
		i++;
	}
}
