/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_printable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:39:07 by maguimar          #+#    #+#             */
/*   Updated: 2022/10/12 17:30:40 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	is_printable(unsigned char c)
{
	if (c >= 32 && c <= 126)
		return (TRUE);
	return (FALSE);
}

int	is_printable_str(char *str)
{
	if (str == NULL)
		return (FALSE);
	while (*str != '\0')
	{
		if (is_printable(*str) == FALSE)
			return (FALSE);
		str++;
	}
	return (TRUE);
}

int	is_map_printable(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (is_printable_str(map->symbols[i]) == FALSE)
			return (FALSE);
		i += 1;
	}
	return (TRUE);
}
