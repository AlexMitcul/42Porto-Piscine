/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:31:40 by amitcul           #+#    #+#             */
/*   Updated: 2022/09/28 11:38:28 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*d;

	d = dest;
	while (*d != '\0')
		d++;
	while (*src != '\0' && nb)
	{
		*d = *(unsigned char *)src;
		d++;
		src++;
		nb--;
	}
	*d = '\0';
	return (dest);
}
