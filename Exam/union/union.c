/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:08:18 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/07 13:17:55 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_line(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (0);
		s++;
	}
	return (1);
}

int	check_line_at(char *s, char c, int index)
{
	int	i;

	i = 0;
	while (s[i] && i < index)
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (check_line_at(argv[1], argv[1][i], i))
			write(1, &argv[1][i], 1);
		i += 1;
	}
	i = 0;
	while (argv[2][i])
	{
		if (check_line(argv[1], argv[2][i]) && \
		check_line_at(argv[2], argv[2][i], i))
			write(1, &argv[2][i], 1);
		i += 1;
	}
	write(1, "\n", 1);
	return (0);
}
