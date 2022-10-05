/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:18:18 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/05 17:40:12 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_index_from_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

static int	char_in_base(char c, char *base)
{
	while (*base)
	{
		if (*base == c)
			return (1);
		base++;
	}
	return (0);
}

static long	to_decimal(char *nbr, char *base_from)
{
	unsigned int	res;
	int				len;

	len = 0;
	while (base_from[len])
		len += 1;
	res = 0;
	while (nbr && *nbr != '\0' && char_in_base(*nbr, base_from))
	{
		res = res * len + get_index_from_base(*nbr, base_from);
		nbr++;
	}
	return (res);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			if (base[i] == ' ' || base[i] == '\f' || base[i] == '\n' || \
			base[i] == '\r' || base[i] == '\t' || base[i] == '\v' || \
			base[i] == '+' || base[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	long	decimal_number;

	if (!str || !check_base(base))
		return (0);
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r' || \
	*str == '\t' || *str == '\v')
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	decimal_number = to_decimal(str, base);
	return (decimal_number * (long) sign);
}

/* #include <stdio.h>
int	main()
{
	printf("%d\n", ft_atoi_base(" \f\n\r\t\v    --+--42a", "0123456789"));
	printf("%d\n", ft_atoi_base(" \f\n\r\t\v--+-0012a", "01"));
	printf("%d\n", ft_atoi_base(" \f\n\r\t\v--+-42a", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base(" \f\n\r\t\v-2147483648", "0123456789"));
	return (0);
} */
