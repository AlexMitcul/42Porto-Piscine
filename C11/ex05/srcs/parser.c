/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:15:31 by alexmitcul        #+#    #+#             */
/*   Updated: 2022/10/04 22:32:23 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doop.h"

char	get_operation(char *line)
{
	if (line[0] == '\0' || line[1] != '\0')
		return (0);
	return (line[0]);
}

int	validate_operations(int b, char operation)
{
	if (b == 0 && operation == '/')
		return (write_error("Stop : division by zero"));
	if (b == 0 && operation == '%')
		return (write_error("Stop : modulo by zero"));
	return (1);
}
