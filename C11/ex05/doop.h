/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexmitcul <alexmitcul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:13:13 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/04 15:26:20 by alexmitcul       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H

# include <unistd.h>

int	write_error(char *error);

/**		operations.c	**/
int	addition(int a, int b);
int	substraction(int a, int b);
int	division(int a, int b);
int	multiplication(int a, int b);
int	modulo(int a, int b);

#endif
