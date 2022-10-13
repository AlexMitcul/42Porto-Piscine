/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:19:41 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/11 17:23:23 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
	void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if ((*cmp)(begin_list->data, data_ref) == 0)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>
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

int main()
{
	t_list	*head;
	t_list	*p;

	head = NULL;
	ft_list_push_back(&head, "42");
	ft_list_push_back(&head, "324");
	ft_list_push_back(&head, "123");
	ft_list_push_back(&head, "42");

	p = head;
	while (head)
	{
		printf("List node contains: %s\n", (char*)head->data);
		head = head->next;
	}
	ft_list_foreach_if(p, &ft_putstr, (void*)"42", &strcmp);

	return 0;
} */
