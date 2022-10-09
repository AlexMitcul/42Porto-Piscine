/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:14:40 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/09 23:09:30 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

//!
# include <stdio.h>

# include <fcntl.h>
# include <unistd.h>


int		ft_strlen(char *str);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_char_is_printable(char c);


#endif
