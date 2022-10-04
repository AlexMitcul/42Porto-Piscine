/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:12:30 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/04 22:32:22 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doop.h"

int ft_atoi(char *str)
{
	int sign;
	int res;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r' || \
	*str == '\t' || *str == '\v')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + (*str - '0');
		else
			break ;
		str++;
	}
	return (res * sign);
}
