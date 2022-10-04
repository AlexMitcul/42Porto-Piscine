/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:33:36 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/03 22:06:12 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	char_in_base(char c, char *base);
int	get_index_from_base(char c, char *base);
int	check_base(char *base);
int	is_space(char c);

unsigned int	to_decimal(char *nbr, char *base_from)
{
	unsigned int	res;
	int				len;

	res = 0;
	len = ft_strlen(base_from);
	while (nbr && *nbr != '\0' && char_in_base(*nbr, base_from))
	{
		res = res * len + get_index_from_base(*nbr, base_from);
		nbr++;
	}
	return (res);
}

static int	count_number_length(unsigned int n, int sign, char *base_to)
{
	int	count;
	int	base_len;

	count = 0;
	if (n == 0)
		return (count + 1);
	base_len = ft_strlen(base_to);
	if (sign == -1)
		count += 1;
	while (n != 0)
	{
		n = n / base_len;
		count += 1;
	}
	return (count);
}

char	get_char_from_base(char *base, int index)
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

char	*to_base(unsigned int n, int sign, char *base_to)
{
	int		num_len;
	char	*res;
	int		base_len;
	int		rem;

	num_len = count_number_length(n, sign, base_to);
	res = (char *)malloc(sizeof(char) * (num_len + 1));
	res[num_len] = '\0';
	if (n == 0)
		res[num_len - 1] = get_char_from_base(base_to, 0);
	if (sign == -1 && n != 0)
		res[0] = '-';
	base_len = ft_strlen(base_to);
	num_len -= 1;
	while (n != 0)
	{
		rem = n % base_len;
		n = n / base_len;
		res[num_len] = get_char_from_base(base_to, rem);
		num_len -= 1;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				sign;
	char			*res;
	unsigned int	decimal_number;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	sign = 1;
	while (is_space(*nbr))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
		if (*(nbr++) == '-')
			sign *= -1;
	decimal_number = to_decimal(nbr, base_from);
	res = to_base(decimal_number, sign, base_to);
	return (res);
}

/*
#include <stdio.h>
#include <limits.h>
int main()
{
	// printf("result : $%s$\n", ft_convert_base("2147483647", "0123456789",
		"0123456789abcdef"));
	// printf("result : $%s$\n", ft_convert_base("---------7fffffff",
		"0123456789abcdef", "01"));
	// printf("result : $%s$\n", ft_convert_base("---+--0001023a", "0123456789",
		"0123456789"));
	// printf("result : $%s$\n", ft_convert_base("-0", "0123456789",
		"abcdefghij"));
	// printf("result : $%s$\n", ft_convert_base("42", "0123456789", "01"));

	// printf("result : $%s$\n", ft_convert_base("+0", "0123456789",
		"0123456789"));
	// printf("result : $%s$\n", ft_convert_base("1236712736172376123",
		"0123456789",
		"0123456789"));
	// printf("result : $%s$\n", ft_convert_base("-38475673485684369745874345",
		"0123456789", "0123456789"));

	// printf("result : $%s$\n", ft_convert_base("+0", "0123456789", ""));
	// printf("result : $%s$\n", ft_convert_base("+0", "", "0123456789"));
	// printf("result : $%s$\n", ft_convert_base("", "0123456789", "0123456789"));

	// printf("result : $%s$\n", ft_convert_base("42", "0123456789", 0));
	// printf("result : $%s$\n", ft_convert_base("42", 0, "0123456789"));
	// printf("result : $%s$\n", ft_convert_base(0, "0123456789", "0123456789"));

	return (0);
} */
