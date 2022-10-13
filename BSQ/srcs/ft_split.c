/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:39:10 by maguimar          #+#    #+#             */
/*   Updated: 2022/10/12 13:41:09 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/bsq.h"

static int	is_contained_in_charset(char c, char *charset)
{
	while (charset && *charset != '\0')
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

static int	count_word_count(char *str, char *charset)
{
	int	i;
	int	count;
	int	was_space;

	count = 0;
	was_space = 1;
	i = 0;
	while (str && str[i] != '\0')
	{
		if (!is_contained_in_charset(str[i], charset) && was_space)
		{
			count += 1;
			was_space = 0;
		}
		else if (was_space == 0 && is_contained_in_charset(str[i], charset))
			was_space = 1;
		i++;
	}
	return (count);
}

static char	*get_word(char *str, char *charset)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	while (str[len] != '\0' && !is_contained_in_charset(str[len], charset))
		len += 1;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	i = 0;
	while (i < len)
	{
		res[i] = *str;
		str++;
		i++;
	}
	return (res);
}

// static int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

char	**ft_split(char *str, char *charset)
{
	int		words_count;
	int		i;
	char	**lines;

	words_count = count_word_count(str, charset);
	lines = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!lines)
		return (NULL);
	i = 0;
	while (i < words_count)
	{
		while (*str != '\0' && is_contained_in_charset(*str, charset))
			str += 1;
		lines[i] = get_word(str, charset);
		str = str + ft_strlen(lines[i]);
		i++;
	}
	lines[i] = NULL;
	return (lines);
}
