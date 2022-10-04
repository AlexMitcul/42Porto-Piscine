/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexmitcul <alexmitcul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:48:08 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/09/26 21:00:59 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;
	int	first;

	i = 0;
	j = 0;
	if (!*to_find)
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			first = i;
			k = i;
			while (to_find[j] != '\0' && (str[k++] == to_find[j]))
				j++;
			if (to_find[j] == '\0' && (str[k - 1] == to_find[j - 1]))
				return (&((char *)str)[first]);
		}
		i++;
	}
	return (0);
}
