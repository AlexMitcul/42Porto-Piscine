/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:43:15 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/06 12:46:04 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*cur;
	t_list	*nxt;

	cur = begin_list;
	while (cur)
	{
		free_fct(cur->data);
		cur = cur->next;
	}
	cur = begin_list;
	nxt = begin_list->next;
	while (cur && nxt)
	{
		free(cur);
		cur = nxt;
		nxt = nxt->next;
	}
}
