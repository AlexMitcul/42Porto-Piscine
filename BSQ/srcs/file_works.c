/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_works.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:23:43 by maguimar          #+#    #+#             */
/*   Updated: 2022/10/13 11:28:27 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	count_bytes(char *file_name)
{
	int		fd;
	char	bf[1];
	int		count;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	while (read(fd, &bf, 1))
		count += 1;
	close(fd);
	return (count);
}

char	*read_all_file(char *file_name, int bytes_count)
{
	char	*content;
	int		fd;
	char	bf[1];
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = (char *)malloc((bytes_count + 1) * (sizeof(char)));
	i = 0;
	while (i < bytes_count)
	{
		read(fd, &bf, 1);
		content[i] = bf[0];
		i++;
	}
	close(fd);
	content[i] = '\0';
	return (content);
}

char	**get_data(char *filename)
{
	char	*line;
	char	**splitted_lines;

	line = read_all_file(filename, count_bytes(filename));
	if (!line)
		return (NULL);
	splitted_lines = ft_split(line, "\n");
	free(line);
	return (splitted_lines);
}
