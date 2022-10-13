/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:09:07 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/12 23:32:22 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		i++;
	}
	return (str);
}

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	// int	i;
	// int	was_space;

	if (!str)
		return (str);
	str = ft_strcapitalize(str);
	// i = 0;
	// was_space = 1;
	// while (str[i] != '\0')
	// {
	// 	if (is_alpha(str[i]) && was_space)
	// 	{
	// 		// str[i] -= ('a' - 'A');
	// 		was_space = 0;
	// 	}
	// 	else if (was_space == 0 && !is_alpha(str[i]))
	// 		was_space = 1;
	// 	i += 1;
	// }
	return (str);
}

int main()
{
	char	*str_base;
	char	str_cap[36];
	int		index;

	//str_base = "salut, c0mment tu vas ? 42mots quarante-deux; cinquante+et+un";
	str_base = "Vk_(7X)Vmf#H'Fk?>8j@} /7VVxh3(X{6)Xb";
	index = 0;
	while (index < 37)
	{
		str_cap[index] = str_base[index] + 0;
		index++;
	}
	ft_strcapitalize(&str_cap[0]);
	printf("base        : %s\n", str_base);
	printf("%s\n", str_cap);

	return (0);
}
