/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexmitcul <alexmitcul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:59:57 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/10 01:04:39 by alexmitcul       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hexdump.h"

void	write_offset(int n)
{
	// need to use here ft_convert_base from "0123456789"
	// to "0123456789abcdef" and after than I get converted
	// line, count ft_strlen() of this line and write '0'x(8 - ft_strlen)
}

void	write_hex_line(char *line, ssize_t bytes)
{
	ssize_t	i;

	i = 0;
	while (i < bytes)
	{
		if ((int)line[i] <= 16)
			ft_putchar('0');
		ft_putnbr_base((int)line[i], "0123456789abcdef");
		ft_putstr(" ");
		if (i == 7 || i == 15)
			ft_putstr(" ");
		i++;
	}
	// need add to space when line is not complete
}

void	write_content(char *line, ssize_t bytes)
{
	ssize_t	i;

	if (bytes == 0)
		return ;
	ft_putstr("|");
	i = 0;
	while (i < bytes)
	{
		if (ft_char_is_printable(line[i]))
			ft_putchar(line[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putstr("|\n");
}


void	read_hex_line(char *str)
{
	int		i;
	int		fd;
	char	bf[16];
	ssize_t	bytes_readed;

	fd = open(str, O_RDONLY);
	bytes_readed = read(fd, &bf, 16);
	i = 0;
	write_offset(i);
	while (bytes_readed)
	{
		write_hex_line(bf, bytes_readed);
		write_content(bf, bytes_readed);
		bytes_readed = read(fd, &bf, 16);
		i += 16;
		write_offset(i);
	}
	write_offset(bytes_readed);

}

int	main(int argc, char **argv)
{
	if (argc == 2)
		read_hex_line(argv[1]);
	return (0);
}
