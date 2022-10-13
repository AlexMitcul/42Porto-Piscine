/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:41:06 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/13 11:41:14 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	copy_splitted_lines(t_map *map, char **splitted_lines)
{
	int	i;

	i = 0;
	map->symbols = (char **)malloc(sizeof(char *) * map->rows);
	while (i < map->rows)
	{
		map->symbols[i] = ft_strdup(splitted_lines[i + 1]);
		i++;
	}
	map->cols = ft_strlen(splitted_lines[1]);
}

int	init_map_using_file(t_map *map, char *filename)
{
	char	**splitted_lines;

	splitted_lines = get_data(filename);
	if (splitted_lines == NULL)
		return (FALSE);
	if (parse_first_line(map, splitted_lines[0]) == FALSE)
		return (free_splitted_lines(splitted_lines));
	if (get_lines_count(splitted_lines) != map->rows)
		return (free_splitted_lines(splitted_lines));
	copy_splitted_lines(map, splitted_lines);
	free_splitted_lines(splitted_lines);
	return (TRUE);
}

void	copy_splitted_lines_from_stdin(t_map *map, char **splitted_lines)
{
	int	i;

	i = 0;
	map->symbols = (char **)malloc(sizeof(char *) * map->rows);
	while (i < map->rows)
	{
		map->symbols[i] = ft_strdup(splitted_lines[i]);
		i++;
	}
	map->cols = ft_strlen(splitted_lines[0]);
}

int	init_map_using_stdin(t_map *map)
{
	char	*first_line;
	char	**splitted_lines;

	first_line = read_first_line();
	if (parse_first_line(map, first_line) == FALSE)
		return (free_line(first_line));
	free_line(first_line);
	splitted_lines = read_lines_from_stdin(map->rows);
	if ((get_lines_count(splitted_lines) + 1) != map->rows)
		return (free_splitted_lines(splitted_lines));
	copy_splitted_lines_from_stdin(map, splitted_lines);
	free_splitted_lines(splitted_lines);
	return (1);
}

int	init_map(t_map *map, char *filename)
{
	if (filename == NULL)
		return (init_map_using_stdin(map));
	return (init_map_using_file(map, filename));
}
