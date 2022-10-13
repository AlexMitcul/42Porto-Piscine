/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:17:50 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/12 21:51:06 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	*read_first_line(void)
{
	char	bf[1];
	ssize_t	readed_bytes;
	int		i;
	char	*fl;

	fl = (char *)malloc(sizeof(char) * 1024);
	readed_bytes = read(STDIN_FILENO, &bf, 1);
	i = 0;
	while (readed_bytes && bf[0] != '\n')
	{
		fl[i] = bf[0];
		readed_bytes = read(STDIN_FILENO, &bf, 1);
		i += 1;
	}
	fl[i] = '\0';
	return (fl);
}

char	**read_lines_from_stdin(int lines_count)
{
	int		i;
	int		j;
	char	**symbols;
	char	bf[1];

	symbols = (char **)malloc(sizeof(char *) * (lines_count + 1));
	i = -1;
	while (++i < lines_count)
	{
		symbols[i] = (char *)malloc(sizeof(char) * 1024);
		j = 0;
		while (read(STDIN_FILENO, &bf, 1))
		{
			if (bf[0] == '\n')
				symbols[i][j] = '\0';
			if (bf[0] == '\n')
				break ;
			symbols[i][j] = bf[0];
			j += 1;
		}
	}
	symbols[i] = NULL;
	if ((i) != lines_count)
		return ((char **)free_all_readed_lines(symbols, i));
	return (symbols);
}

void	copy_splitted_line_from_stdin(t_map *map, char **splitted_lines)
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
