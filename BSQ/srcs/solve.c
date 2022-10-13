/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:49:30 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/13 11:51:15 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	prepare_map(t_map *map, char *filename)
{
	if (map == NULL)
		return (FALSE);
	if (init_map(map, filename) == FALSE)
		return (print_error("map error"));
	if (validate_map(map) == FALSE)
		return (print_error("map error"));
	build_heatmap(map);
	return (TRUE);
}

t_result	*init_result(void)
{
	t_result	*result;

	result = malloc(sizeof(t_result));
	if (result == NULL)
		return (NULL);
	result->i = -1;
	result->j = -1;
	result->x = 0;
	result->y = 0;
	result->size = 0;
	return (result);
}

void	set_new_values(t_result *result, int x, int y, int size)
{
	result->x = x;
	result->y = y;
	result->size = size;
}

void	solve(t_map *map, char *filename)
{
	t_result	*result;

	if (prepare_map(map, filename) == FALSE)
		return ;
	result = init_result();
	if (result == NULL)
		return ;
	while (result->i++ < map->rows)
	{
		result->j = -1;
		while (result->j++ < map->cols)
		{
			while (TRUE)
			{
				if (!possible(map, result))
					break ;
				set_new_values(result, result->i, result->j, result->size + 1);
			}
		}
	}
	print_result(map, result);
	free(result);
	free_heatmap(map);
}
