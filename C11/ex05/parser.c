/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexmitcul <alexmitcul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:15:31 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/04 15:18:38 by alexmitcul       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	get_operation(char *line)
{
	if (line[0] == '\0' || line[1] != '\0')
		return (0);
	return (line[0]);
}

// ! Need to add ft_atoic.
int	ft_atoi(char *str)
{
	return (0); // !
}
