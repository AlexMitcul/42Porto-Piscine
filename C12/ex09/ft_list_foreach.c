/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:51:30 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/11 17:22:34 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

/*
#include <stdio.h>
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

void	ft_print_strlen(void *str)
{
	int	i;

	i = 0;
	while (((char*)str)[i] != '\0')
		i++;
	printf("strlen is %d\n", i);
}

int main()
{
	t_list	*head;
	t_list	*p;

	head = NULL;
	ft_list_push_back(&head, "first");
	ft_list_push_back(&head, "second");
	ft_list_push_back(&head, "third");
	ft_list_push_back(&head, "fourth");

	p = head;
	while (head)
	{
		printf("List node contains: %s\n", (char*)head->data);
		head = head->next;
	}
	ft_list_foreach(p, &ft_print_strlen);


	return 0;
} */
