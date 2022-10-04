/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:13:13 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/04 22:23:42 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H

# include <unistd.h>

/**		print.c		**/
int		write_error(char *error);
void	ft_putnbr(int nb);

/**		ft_atoi.c	**/
int		ft_atoi(char *str);

/**		parser.c	**/
char	get_operation(char *line);
int		validate_operations(int b, char operation);

/**		operations.c	**/
int		addition(int a, int b);
int		substraction(int a, int b);
int		division(int a, int b);
int		multiplication(int a, int b);
int		modulo(int a, int b);

#endif
