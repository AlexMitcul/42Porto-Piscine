/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexmitcul <alexmitcul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:58:21 by amitcul           #+#    #+#             */
/*   Updated: 2022/09/26 20:15:53 by alexmitcul       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	p1;
	unsigned char	p2;

	p1 = (unsigned char) *s1++;
	p2 = (unsigned char) *s2++;
	if (p1 == '\0')
		return (p1 - p2);
	while (p1 == p2 && p1 != '\0')
	{
		p1 = (unsigned char) *s1++;
		p2 = (unsigned char) *s2++;
	}
	return (p1 - p2);
}
