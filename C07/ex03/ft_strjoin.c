/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:34:36 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/08 00:05:25 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_length(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += ft_strlen(sep) * (size - 1);
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	char	*tmp;
	int		i;

	if (size == 0)
		return ((char *) malloc(sizeof(char)));
	res = (char *) malloc(sizeof(char) * (get_length(size, strs, sep) + 1));
	if (!res)
		return (0);
	tmp = res;
	i = 0;
	while (i < size)
	{
		ft_strcpy(tmp, strs[i]);
		tmp += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(tmp, sep);
			tmp += ft_strlen(sep);
		}
		i++;
	}
	*tmp = '\0';
	return (res);
}

/* #include <stdio.h>
#include <string.h>
#include <malloc.h>

int		main(void)
{
	int		index;
	char	**strs;
	char	*separator;
	char	*result;

	strs = (char**)malloc(4 * sizeof(strs));
	strs[0] = "lol";
	strs[1] = "1234";
	strs[2] = "poiuic";
	strs[3] = "1234";
	separator = "";
	index = 0;
	while (index < 4)
	{
		result = ft_strjoin(index, strs, separator);
		printf("result with size = %d : $%s$\n", index, result);
		free(result);
		index++;
	}
} */
