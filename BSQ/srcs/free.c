/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:24:43 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/12 15:01:21 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	free_heatmap(t_map *map)
{
	int	i;

	if (map->heat_map)
	{
		i = 0;
		while (i < map->rows)
		{
			if (map->heat_map[i] != NULL)
				free(map->heat_map[i]);
			i += 1;
		}
		free(map->heat_map);
	}
}

void	free_map(t_map *map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (i < map->rows)
	{
		if (map->symbols != NULL)
			free(map->symbols[i]);
		i += 1;
	}
	free(map->symbols);
	free(map);
}

int	free_splitted_lines(char **splitted_lines)
{
	int	i;

	i = 0;
	while (splitted_lines[i] != 0)
	{
		free(splitted_lines[i]);
		i++;
	}
	free(splitted_lines);
	return (0);
}

void	**free_all_readed_lines(char **lines, int lines_count)
{
	int	i;

	i = 0;
	while (i <= lines_count)
	{
		free(lines[i]);
		i += 1;
	}
	free(lines);
	return (0);
}

int	free_line(char *line)
{
	free(line);
	return (0);
}
