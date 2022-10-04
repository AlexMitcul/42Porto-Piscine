/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:18:19 by amitcul           #+#    #+#             */
/*   Updated: 2022/09/29 14:12:19 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	i;

	if (nb <= 0)
		return (nb);
	i = 0;
	while (i * i <= (unsigned int)nb)
		i++;
	i -= 1;
	return (i);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt;

	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 2;
	sqrt = ft_sqrt(nb);
	while ((i <= sqrt) && (nb % i != 0))
		i++;
	return (i > sqrt);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 0)
		return (2);
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
}
