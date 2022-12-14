/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:29:41 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/11 17:12:44 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/* two pointers version */
void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*first;
	t_list	*second;
	void	*tmp_data;

	first = *begin_list;
	while (first != 0)
	{
		second = *begin_list;
		while (second != 0 && second->next != 0)
		{
			if ((*cmp)(second->data, second->next->data) > 0)
			{
				tmp_data = second->data;
				second->data = second->next->data;
				second->next->data = tmp_data;
			}
			second = second->next;
		}
		first = first->next;
	}
}

/* #include <stdio.h>
#include <string.h>
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

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*p;

	p = *begin_list;
	if (!p)
		*begin_list = ft_create_elem(data);
	else if (!p->next)
		(*begin_list)->next = ft_create_elem(data);
	else
	{
		while (p->next)
			p = p->next;
		p->next = ft_create_elem(data);
	}
}

int main()
{
	t_list	*head;
	t_list	*p;

	head = 0;
	ft_list_push_back(&head, "42");
	ft_list_push_back(&head, "324");
	ft_list_push_back(&head, "123");
	ft_list_push_back(&head, "42");

	p = head;
	while (p)
	{
		printf("List node contains: %s\n", (char*)p->data);
		p = p->next;
	}
	ft_list_sort(&head, &strcmp);
	printf("\n=========================\n");
	p = head;
	while (p)
	{
		printf("List node contains: %s\n", (char*)p->data);
		p = p->next;
	}


	return 0;
} */

/* KO for this version
void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	void	*tmp;
	t_list	*p;

	p = *begin_list;
	while (p->next != 0)
	{
		if (((*cmp)(p->data, p->next->data)) > 0)
		{
			tmp = p->data;
			p->data = p->next->data;
			p->next->data = tmp;
			p = *begin_list;
		}
		else
			p = p->next;
	}
}
*/
