/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:13:58 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/09 22:19:39 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hexdump.h"

static char	get_char_from_base(char *base, int index)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (i == index)
			return (base[i]);
		i += 1;
	}
	return ('\0');
}

static void	to_base(unsigned int n, int sign, char *base_to)
{
	char				c;
	unsigned int		base_len;

	base_len = ft_strlen(base_to);
	if (sign == -1)
		write(1, "-", 1);
	if (n < base_len)
	{
		c = get_char_from_base(base_to, n);
		write(1, &c, 1);
	}
	else
	{
		to_base(n / base_len, 1, base_to);
		to_base(n % base_len, 1, base_to);
	}
}

static int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base)
		return (0);
	while (base[i])
	{
		j = i;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			if (base[i] == '+' || base[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (!check_base(base))
		return ;
	if (nbr < 0)
		to_base((unsigned int)(-nbr), -1, base);
	else
		to_base((unsigned int)nbr, 1, base);
}
