/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:25:39 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/08 16:20:28 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//close, open, read, write

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);

static void	write_data_from(int fd)
{
	char	buf[1];

	while (read(fd, buf, 1))
	{
		ft_putchar(*buf);
	}
}

static void	ft_display_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	write_data_from(fd);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
		ft_display_file(argv[1]);
	return (0);
}
