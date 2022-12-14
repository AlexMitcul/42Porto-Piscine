/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:18:17 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/11 16:59:28 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*p;

	if (begin_list1 == 0 || *begin_list1 == 0)
		*begin_list1 = begin_list2;
	else
	{
		p = *begin_list1;
		while (p->next)
			p = p->next;
		p->next = begin_list2;
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
	t_list	*head1;
	t_list	*head2;
	t_list	*p;

	head1 = 0;
	ft_list_push_back(&head1, "1");
	ft_list_push_back(&head1, "2");
	ft_list_push_back(&head1, "3");
	ft_list_push_back(&head1, "4");

	head2 = 0;
	ft_list_push_back(&head2, "5");
	ft_list_push_back(&head2, "6");
	ft_list_push_back(&head2, "7");
	ft_list_push_back(&head2, "8");

	printf("\nFirst list:\n");
	p = head1;
	while (p)
	{
		printf("List node contains: %s\n", (char*)p->data);
		p = p->next;
	}

	ft_list_merge(&head1, head2);
	printf("\nFirst list after merging:\n");
	p = head1;
	while (p)
	{
		printf("List node contains: %s\n", (char*)p->data);
		p = p->next;
	}

	return 0;
} */
