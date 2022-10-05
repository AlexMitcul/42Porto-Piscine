/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:14:25 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/05 12:56:36 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	int	len;
	int	i;
	int	j;

	if (!base)
		return (0);
	len = ft_strlen(base);
	if (len <= 1)
		return (0);
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-' || \
			base[j] == '+' || base[j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * Function that displays a number in a base system in the terminal.
 * This number 'nbr' is given in the shape of an int, and the radix
 * 'base' in the shape of a string characters.
 *
 * The fuction handle negative numbers.
 * If there is an invalid argument, nothing will be displayed.
 * Invalid base examples:
 * - base is empty or size of 1;
 * - base contains the same character twice;
 * - base contains + or - ;
**/

void	ft_putnbr_base(int nbr, char *base)
{
	if (!check_base(base))
		return ;
	if (nbr < 0)
		to_base((unsigned int)(-nbr), -1, base);
	else
		to_base((unsigned int)nbr, 1, base);
}

/* #include <stdio.h>
int main()
{
	ft_putnbr_base(-42, "01");					// -101010
	printf("\n");
	ft_putnbr_base(-42, "0123456789");			// -42
	printf("\n");
	ft_putnbr_base(-42, "0123456789ABCDEF");	// -2A
	printf("\n");
	ft_putnbr_base(-42, "poneyvif");			// -vn
	printf("\n");
	ft_putnbr_base(42, "01");					// 101010
	printf("\n");
	ft_putnbr_base(42, "0123456789");			// 42
	printf("\n");
	ft_putnbr_base(42, "0123456789ABCDEF");		// 2A
	printf("\n");
	ft_putnbr_base(42, "poneyvif");				// vn
	printf("\n");
	ft_putnbr_base(0, "");						//
	printf("\n");
	ft_putnbr_base(0, 0);						//
	printf("\n");
	ft_putnbr_base(+0, "pone");					// p
	printf("\n");
	ft_putnbr_base(-0, "pone");					// p
	printf("\n");
	ft_putnbr_base(0, "pone");					// p
	printf("\n");


	return 0;
} */
