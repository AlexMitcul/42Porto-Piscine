/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:23:58 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/09 18:26:56 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

/*		print.c		*/
void	write_error(char *error);
void	write_header_with_name(char *file_name);
void	write_n_tail_bytes(char *src, int bytes_to_print);

/*		utils functions		*/
void	ft_putstr(char *str);
int		ft_atoi(char *str);
char	*ft_strjoin(int size, char **strs, char *sep);
void	ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_abs(int value);
char	*ft_strcat(char *dest, char *src);
#endif
