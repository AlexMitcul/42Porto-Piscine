/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:43:13 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/09 19:29:30 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	write_console_input(void)
{
	char	c;

	while (read(STDIN_FILENO, &c, 1) > 0)
		write(1, &c, 1);
}

static void	write_error(char *file_name)
{
	write(STDERR_FILENO, "cat: ", ft_strlen("cat: "));
	write(STDERR_FILENO, file_name, ft_strlen(file_name));
	if (errno == EISDIR)
		write(STDERR_FILENO, ": Is a directory\n", 17);
	if (errno == ENOENT)
		write(STDERR_FILENO, ": No such file or directory\n", 28);
}

void	display_files(char **file_names, int count)
{
	int		fd;
	char	buf[1];
	int		i;
	char	*file_name;
	ssize_t	read_bytes;

	i = 1;
	while (i < count)
	{
		file_name = file_names[i];
		fd = open(file_name, O_RDWR);
		if (fd < 0)
		{
			write_error(file_name);
			i++;
			continue ;
		}
		while (read(fd, &buf, 1))
			write(STDOUT_FILENO, &buf, 1);
		close(fd);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		write_console_input();
	else
		display_files(argv, argc);
	return (0);
}
