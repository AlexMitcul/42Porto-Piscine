/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:09:21 by maguimar          #+#    #+#             */
/*   Updated: 2022/10/13 11:50:53 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	n;
	int	i;

	res = 0;
	i = 0;
	n = ft_strlen(str) - 3;
	while ((str[i] >= '0' && str[i] <= '9') && i < n)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (i < n)
		return (0);
	return (res);
}
