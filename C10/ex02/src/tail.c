/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:35:27 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/09 19:34:35 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tail.h"

int	count_symbold(char *file_name)
{
	int		fd;
	ssize_t	count;
	ssize_t	bytes;
	char	bf[1];

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (fd);
	count = 0;
	bytes = read(fd, &bf, 1);
	while (bytes)
	{
		count += bytes;
		bytes = read(fd, &bf, 1);
	}
	close(fd);
	return (count);
}

char	*read_n_symbols(char *file_name, int symbols_count)
{
	int		fd;
	char	bf[1];
	char	*res;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (symbols_count + 1));
	i = 0;
	while (read(fd, &bf, 1))
	{
		res[i] = bf[0];
		i += 1;
	}
	res[i] = '\0';
	close(fd);
	return (res);
}

void	iterate_by_files(char **file_names, int files_count,
	int bytes_to_print, int write_header)
{
	int		index;
	char	*file_content;
	int		symbols_count;

	index = 2;
	while (index++ < files_count - 1)
	{
		symbols_count = count_symbold(file_names[index]);
		if (symbols_count < 0)
		{
			write_error("tail: cannot open '");
			write_error(file_names[index]);
			write_error("' for reading: No such file or directory\n");
			continue ;
		}
		file_content = read_n_symbols(file_names[index], symbols_count);
		if (write_header)
			write_header_with_name(file_names[index]);
		write_n_tail_bytes(file_content, bytes_to_print);
		if (write_header && index + 1 < files_count)
			ft_putstr("\n");
		free(file_content);
	}
}

int	main(int argc, char *argv[])
{
	if (argc <= 2)
		write_error("Option is missing.\n");
	else if (argc <= 3)
		write_error("File is missing.\n");
	else if (argc == 4)
		iterate_by_files(argv, argc, ft_abs(ft_atoi(argv[2])), 0);
	else
		iterate_by_files(argv, argc, ft_abs(ft_atoi(argv[2])), 1);
	return (0);
}
