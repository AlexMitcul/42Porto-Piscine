/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:00:58 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/03 20:03:30 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*get_word(char *str, char *charset)
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

/*
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <string.h>
void mcheck(void * p, size_t required_size)
{
	void * p2 = malloc(required_size);
	if (malloc_usable_size(p) == malloc_usable_size(p2))
		printf("OK\n");
	else
		printf("KO\n");
	free(p2);
}
void	check(int res)
{
	if (res)
		printf("OK\n");
	else
		printf("KO\n");

}

int main(void)
{
	char * * tab = ft_split("  tripouille  42  ", " ");
	mcheck(tab, sizeof(char *) * 3);

	 check(!strcmp(tab[0], "tripouille"));
	 mcheck(tab[0], strlen("tripouille") + 1);

	 check(!strcmp(tab[1], "42"));
	 mcheck(tab[1], strlen("42") + 1);

	 check(tab[2] == NULL);

	tab = ft_split("tripouille", 0);
	 check(!strcmp(tab[0], "tripouille"));
	 check(tab[1] == NULL);

	tab = ft_split("     ", " ");
	 check(tab[0] == NULL);

	char * invalidReadCheck = 0;
	tab = ft_split(invalidReadCheck, 0);
	check(tab[0] == NULL);

	tab = ft_split("chinimala", " ");
	mcheck(tab, sizeof(char *) * 2);
	check(!strcmp(tab[0], "chinimala"));
	check(tab[1] == NULL);

	tab = ft_split("", " ");
	mcheck(tab, sizeof(char *) * 1);
	check(tab[0] == NULL);

	char * splitme = strdup("Tripouille");
	tab = ft_split(splitme, " ");
	mcheck(tab, sizeof(char *) * 2);
	check(!strcmp(tab[0], "Tripouille"));
	check(tab[1] == NULL);

	splitme = strdup("Tripouille ");
	tab = ft_split(splitme, " ");
	mcheck(tab, sizeof(char *) * 2);
	check(!strcmp(tab[0], "Tripouille"));
	check(tab[1] == NULL);

	splitme = strdup(" Tripouille");
	tab = ft_split(splitme, " ");
	mcheck(tab, sizeof(char *) * 2);
	check(!strcmp(tab[0], "Tripouille"));
	check(tab[1] == NULL);

	splitme = strdup(" Tripouille ");
	tab = ft_split(splitme, " ");
	mcheck(tab, sizeof(char *) * 2);
	check(!strcmp(tab[0], "Tripouille"));
	mcheck(tab[0], strlen("Tripouille") + 1);
	check(tab[1] == NULL);

	splitme = strdup("--1-2--3---4----5-----42");
	tab = ft_split(splitme, "-");
	mcheck(tab, sizeof(char *) * 7);
	check(!strcmp(tab[0], "1"));
	mcheck(tab[0], strlen("1") + 1);

	check(!strcmp(tab[1], "2"));
	mcheck(tab[1], strlen("2") + 1);

	check(!strcmp(tab[2], "3"));
	mcheck(tab[2], strlen("3") + 1);

	check(!strcmp(tab[3], "4"));
	mcheck(tab[3], strlen("4") + 1);

	check(!strcmp(tab[4], "5"));
	mcheck(tab[4], strlen("5") + 1);

	check(!strcmp(tab[5], "42"));
	mcheck(tab[5], strlen("42") + 1);

	check(tab[6] == NULL);


	return (0);
} */
