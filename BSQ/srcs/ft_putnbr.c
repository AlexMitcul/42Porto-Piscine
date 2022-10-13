/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:38:55 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/11 00:58:01 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_putnbr(int nb)
{
	unsigned int	i;

	if (nb < 0)
	{
		i = nb * (-1);
		ft_putchar('-');
	}
	else
		i = nb;
	if (i < 10)
	{
		ft_putchar('0' + i);
	}
	else
	{
		ft_putnbr((int)(i / 10));
		ft_putnbr((int)(i % 10));
	}
}
