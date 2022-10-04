/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:17:30 by amitcul           #+#    #+#             */
/*   Updated: 2022/09/27 11:22:25 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The strlen() function calculates the length of the
**		string pointed to by s, excluding the terminating null byte ('\0')
**	The strlen() function returns the number of
**		bytes in the string pointed to by s.
*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
