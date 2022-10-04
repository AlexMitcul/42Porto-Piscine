/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:26:23 by amitcul           #+#    #+#             */
/*   Updated: 2022/09/30 09:53:45 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	i;

	if (nb <= 0)
		return (0);
	i = 0;
	while (i * i < (unsigned int)nb)
		i++;
	if ((unsigned int)nb == (i * i))
		return (i);
	return (0);
}
