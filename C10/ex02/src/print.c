/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:52:40 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/09 19:21:58 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tail.h"

void	write_header_with_name(char *file_name)
{
	ft_putstr("==> ");
	ft_putstr(file_name);
	ft_putstr(" <==\n");
}

void	write_error(char *error)
{
	write(STDERR_FILENO, error, ft_strlen(error));
}

void	write_n_tail_bytes(char *src, int bytes_to_print)
{
	int	i;
	int	len;

	len = ft_strlen(src);
	i = len - bytes_to_print;
	while (i < len)
	{
		ft_putchar(src[i]);
		i++;
	}
}
