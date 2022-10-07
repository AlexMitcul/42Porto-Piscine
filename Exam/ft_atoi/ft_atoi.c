/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:19:29 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/07 13:35:50 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || \
		c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	unsigned int		res;
	int			sign;

	i = 0;
	sign = 1;
	res = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (unsigned int)(str[i] - '0');
		else
			break ;
		i++;
	}
	return (res * (sign));
}

/*
#include <stdio.h>
int	main(int argc, char *argv[])

	char	*input;

//	input = " \n\t\v\r\f --+--42abc";
//	input = "21474836471";
	input = "-2147483649";
	if (argc == 2)
		printf("%d\n", ft_atoi(argv[1]));
	else
	{
		printf("%d\n", ft_atoi(input));
		printf("%d\n", atoi(input));
	}
	return (0);
}
*/
