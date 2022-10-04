/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexmitcul <alexmitcul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:12:54 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/04 15:22:23 by alexmitcul       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

static int	write_error(char *error)
{
	ft_putstr(error);
	return (0);
}
