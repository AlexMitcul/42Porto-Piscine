/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:44:57 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/13 11:51:03 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static int	init_heatmap(t_map *map)
{
	int	i;
	int	j;

	map->heat_map = (int **)malloc(sizeof(int *) * map->rows);
	if (map->heat_map == NULL)
		return (FALSE);
	i = 0;
	while (i < map->rows)
	{
		map->heat_map[i] = (int *)malloc(sizeof(int) * map->cols);
		if (map->heat_map[i] == NULL)
			return (FALSE);
		j = 0;
		while (j < map->cols)
		{
			map->heat_map[i][j] = 0;
			j += 1;
		}
		i += 1;
	}
	return (TRUE);
}

/*	Fill first row and first row with numbers of obstacles	*/
static void	prepare_heatmap(t_map *map)
{
	int	i;
	int	obstacle_count;

	i = 0;
	obstacle_count = 0;
	while (i < map->cols)
	{
		if (map->symbols[0][i] == map->obstacle_s)
			obstacle_count += 1;
		map->heat_map[0][i] = obstacle_count;
		i += 1;
	}
	i = 0;
	obstacle_count = 0;
	while (i < map->rows)
	{
		if (map->symbols[i][0] == map->obstacle_s)
			obstacle_count += 1;
		map->heat_map[i][0] = obstacle_count;
		i += 1;
	}
}

int	build_heatmap(t_map *map)
{
	int	i;
	int	j;

	if (init_heatmap(map) == FALSE)
		return (FALSE);
	prepare_heatmap(map);
	i = 1;
	while (i < map->rows)
	{
		j = 1;
		while (j < map->cols)
		{
			if (map->symbols[i][j] == map->obstacle_s)
				map->heat_map[i][j] = map->heat_map[i][j - 1] + \
				map->heat_map[i - 1][j] - map->heat_map[i - 1][j - 1] + 1;
			else
				map->heat_map[i][j] = map->heat_map[i][j - 1] + \
				map->heat_map[i - 1][j] - map->heat_map[i - 1][j - 1] + 0;
			j += 1;
		}
		i += 1;
	}
	return (TRUE);
}
