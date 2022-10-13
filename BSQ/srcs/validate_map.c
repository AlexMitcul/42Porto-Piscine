/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:37:06 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/12 21:29:11 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

/* Check that all lines of map are equal length */
static int	is_different_lines_length(t_map *map)
{
	int	line_length;
	int	i;

	line_length = ft_strlen(map->symbols[0]);
	i = 1;
	while (i < map->rows)
	{
		if (ft_strlen(map->symbols[i]) != line_length)
			return (TRUE);
		i += 1;
	}
	return (FALSE);
}

/* Check that map contains only 'empty_s' and 'obstacle_s' */
static int	is_contain_forbidden_symbols(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->symbols[i][j] != map->empty_s &&
				map->symbols[i][j] != map->obstacle_s)
				return (TRUE);
			j += 1;
		}
		i += 1;
	}
	return (FALSE);
}

/* Check that 'empty_s', 'obstacle_s' and 'full_s' are differens */
static int	is_duplicated_symbol(t_map *map)
{
	if (map->empty_s != map->obstacle_s && \
		map->empty_s != map->full_s && \
		map->full_s != map->obstacle_s)
		return (FALSE);
	return (TRUE);
}

/* Check that map contains at least one row and one column */
static int	has_required_cols_rows(t_map *map)
{
	if (map->rows > 0 && map->cols > 0)
		return (TRUE);
	return (FALSE);
}

int	validate_map(t_map *map)
{
	return (
		is_different_lines_length(map) == FALSE && \
		is_contain_forbidden_symbols(map) == FALSE && \
		is_duplicated_symbol(map) == FALSE && \
		has_required_cols_rows(map) == TRUE && \
		is_map_printable(map) == TRUE
	);
}
