/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:49:48 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/07 15:06:45 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		tmp;
	t_list	*p;

	p = lst;
	while (p->next != 0)
	{
		if (((*cmp)(p->data, p->next->data)) == 0)
		{
			tmp = p->data;
			p->data = p->next->data;
			p->next->data  = tmp;
			p = lst;
		}
		else
			p = p->next;
	}
	return (lst);
}

/* #include <stdlib.h>
#include <stdio.h>

int ascending(int a, int b)
{
	return (a <= b);
}

t_list	*ft_create_elem(int data)
{
	t_list	*item;

	item = (t_list *) malloc(sizeof(t_list));
	if (!item)
		return (0);
	item->data = data;
	item->next = 0;
	return (item);
}

void	ft_list_push_front(t_list **begin_list, int data)
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
	ft_list_push_front(&head, 2);
	ft_list_push_front(&head, 4);
	ft_list_push_front(&head, 6);
	ft_list_push_front(&head, 8);

	p = head;
	while (head)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
	head = p;
	head = sort_list(head, &ascending);
	printf("\n--- Sorted List ---\n");
	while (head)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
	return 0;
} */
