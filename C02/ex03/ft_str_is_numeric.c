/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:31:00 by amitcul           #+#    #+#             */
/*   Updated: 2022/09/23 13:35:39 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}
