/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:52:25 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/12 21:21:42 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

/*
*	height = rows count
*	width = cols count
*	row = row position
*	col = col position
*	res->size
*/
int	if_out_of_borders(int height, int width, t_result *res)
{
	if (res->i + res->size >= height || res->j + res->size >= width)
		return (TRUE);
	return (FALSE);
}

/* Check that square fits */
static int	can_put_square(int p1, int p2, int p3, int p4)
{
	if ((p4 - p3 - p2 + p1) > 0)
		return (FALSE);
	return (TRUE);
}

/*
*	p1 = left upper corner value
*	p2 = right upper corner value
*	p3 = lower right corner value
*	p4 = left upper corner value
*/
int	possible(t_map *map, t_result *res)
{
	if (if_out_of_borders(map->rows, map->cols, res))
		return (FALSE);
	if (res->i == 0 && res->j == 0)
		return (can_put_square(0, 0, 0, \
		map->heat_map[res->i + res->size][res->j + res->size]));
	else if (res->i == 0)
		return (can_put_square(0, 0, \
		map->heat_map[res->i + res->size][res->j - 1], \
		map->heat_map[res->i + res->size][res->j + res->size]));
	else if (res->j == 0)
		return (can_put_square(0, \
		map->heat_map[res->i - 1][res->j + res->size], 0, \
		map->heat_map[res->i + res->size][res->j + res->size]));
	else
		return (can_put_square(map->heat_map[res->i - 1][res->j - 1], \
		map->heat_map[res->i - 1][res->j + res->size], \
			map->heat_map[res->i + res->size][res->j - 1], \
			map->heat_map[res->i + res->size][res->j + res->size]));
	return (FALSE);
}
