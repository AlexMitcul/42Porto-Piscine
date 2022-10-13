/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:43:15 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/11 17:21:56 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*cur;
	t_list	*nxt;

	if (!begin_list)
		return ;
	cur = begin_list;
	while (cur)
	{
		free_fct(cur->data);
		cur = cur->next;
	}
	cur = begin_list;
	nxt = begin_list->next;
	while (cur)
	{
		free(cur);
		cur = nxt;
		if (nxt)
			nxt = nxt->next;
	}
}

/* #include <stdio.h>
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*item;

	item = (t_list *) malloc(sizeof(t_list));
	if (!item)
		return (NULL);
	item->data = data;
	item->next = NULL;
	return (item);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*item;

	if (*begin_list)
	{
		item = ft_create_elem(data);
		item->next = *begin_list;
		*begin_list = item;
	}
	else
		*begin_list = ft_create_elem(data);
}
void	free_elem(void *elem)
{
	(void)elem;
	return ;
}

int main()
{
	t_list	*head;

	head = 0;
	ft_list_push_back(&head, "one");
	ft_list_push_back(&head, "two");
	ft_list_push_back(&head, "three");
	ft_list_push_back(&head, "four");
	ft_list_clear(head, &free_elem);

	return (0);
} */
