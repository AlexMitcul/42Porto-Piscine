/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:26:54 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/13 11:41:01 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	num_length(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len += 1;
	}
	return (len);
}

int	parse_first_line(t_map *map, char *line)
{
	int	len;

	if (line == 0 || *line == 0)
		return (FALSE);
	len = ft_strlen(line);
	if (len <= 3)
		return (FALSE);
	if (line[0] <= '0' || line[0] > '9')
		return (FALSE);
	if (!is_printable_str(line))
		return (FALSE);
	map->rows = ft_atoi(line);
	if (len - num_length(map->rows) != 3)
		return (FALSE);
	map->empty_s = line[len - 3];
	map->obstacle_s = line[len - 2];
	map->full_s = line[len - 1];
	return (TRUE);
}

int	get_lines_count(char **lines)
{
	int	i;

	i = 0;
	while (lines[i] != NULL)
		i += 1;
	return (i - 1);
}
