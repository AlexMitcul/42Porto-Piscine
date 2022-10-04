/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:34:36 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/04 21:48:11 by amitcul          ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	ft_strcpy(dest + ft_strlen(dest), src);
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;

	if (size == 0)
		return ((char *) malloc(sizeof(char)));
	res = (char *) malloc(sizeof(char) * (get_length(size, strs, sep) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		if (i < size - 1)
			ft_strcat(res, sep);
		i++;
	}
	res[ft_strlen(res)] = '\0';
	return (res);
}

/* #include <stdio.h>
#include <string.h>
#include <malloc.h>
void check(int succes)
{
	if (succes)
		printf("\033[0;32m OK \033[0m\n");
	else
	 	printf("\033[1;31m KO \033[0m\n");
}

void mcheck(void * p, size_t required_size)
{
	void * p2 = malloc(required_size);
	if (malloc_usable_size(p) == malloc_usable_size(p2))
		printf("\033[0;32m OK \033[0m\n");
	else
	 	printf("\033[1;31m KO \033[0m\n");
	free(p2);
}

int main()
{
	char *s;


	char *arr1[2] = {"tripouille", "42"};
	s = ft_strjoin(2, arr1, "");
	check(!strcmp(s, "tripouille42"));
	mcheck(s, strlen("tripouille") + strlen("42") + 1);

	char *arr2[2] = {"", "42"};
	s = ft_strjoin(2, arr2, "");
	check(!strcmp(s, "42"));
	mcheck(s, strlen("") + strlen("42") + 1);

	char *arr3[2] = {"42", ""};
	s = ft_strjoin(2, arr3, "");
	check(!strcmp(s, "42"));
	mcheck(s, strlen("42") + strlen("") + 1);

	char *arr4[2] = {"", ""};
	s = ft_strjoin(2, arr4, "");
	check(!strcmp(s, ""));
	mcheck(s, strlen("") + strlen("") + 1);

	char *arr5[3] = {"Hello", ",", "World!"};
	s = ft_strjoin(3, arr5, "-");
	check(!strcmp(s, "Hello-,-World!"));
	mcheck(s, strlen("Hello") + strlen(",") + strlen("World!")
	+ strlen("-") * 2);

	char *arr6[4] = {"Hello", ",", "World", "!"};
	s = ft_strjoin(4, arr6, "*****");
	check(!strcmp(s, "Hello*****,*****World*****!"));
	mcheck(s, strlen("Hello") + strlen(",") + strlen("World")
	+ strlen("!") + strlen("*****") * 3);

	return (0);
} */
