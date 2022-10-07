/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:38:12 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/07 13:58:22 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += 32);
	return (c);
}

int	count_sybols(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (to_lower(*str) == to_lower(c))
			count += 1;
		str++;
	}
	return (count);
}

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	check_line_at(char *str, char c, int index)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (to_lower(str[i]) == to_lower(c) && i < index)
			return (0);
		i += 1;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	int	i;
	int	flag;
	int	count;

	if (argc != 2)
		return (printf("\n") - 1);
	i = 0;
	flag = 0;
	while (argv[1][i])
	{
		if (is_alpha(argv[1][i]) && check_line_at(argv[1], argv[1][i], i))
		{
			if (flag)
				printf(", ");
			count = count_sybols(argv[1], argv[1][i]);
			printf("%d%c", count, to_lower(argv[1][i]));
			flag = 1;
		}
		i += 1;
	}
	printf("\n");
	return 0;
}
