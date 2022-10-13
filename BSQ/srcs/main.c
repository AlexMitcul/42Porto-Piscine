/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:24:39 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/13 11:50:33 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_map	*fill_map_with_zeros(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->rows = 0;
	map->cols = 0;
	map->empty_s = '\0';
	map->obstacle_s = '\0';
	map->full_s = '\0';
	map->symbols = 0;
	map->heat_map = 0;
	return (map);
}

int	main(int argc, char **argv)
{
	int		i;
	t_map	*map;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			map = fill_map_with_zeros();
			solve(map, argv[i]);
			free_map(map);
			i++;
		}
	}
	else
	{
		map = fill_map_with_zeros();
		solve(map, NULL);
		free_map(map);
	}
	return (0);
}
