/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:11:34 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/12 23:01:53 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
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

static void	ft_list_sort(t_list **begin_list, int (*cmp)())
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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	compare(void *a, void *b)
{
	int	a_int = atoi((char*)a);
	int	b_int = atoi((char*)b);
	printf("%d-%d\n", a_int, b_int);
	return (a_int - b_int);
}

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

static void	ft_list_push_back(t_list **begin_list, void *data)
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
	ft_list_push_back(&head1, "5");
	ft_list_push_back(&head1, "8");
	ft_list_push_back(&head1, "9");

	head2 = 0;
	ft_list_push_back(&head2, "6");
	ft_list_push_back(&head2, "7");

	p = head1;
	printf("List 1:\n");
	while (p)
	{
		printf("Node value: %s\n", (char*)p->data);
		p = p->next;
	}
	p = head2;
	printf("\n\nList 2:\n");
	while (p)
	{
		printf("Node value: %s\n", (char*)p->data);
		p = p->next;
	}
	ft_sorted_list_merge(&head1, head2, &compare);
	printf("\nAfter merging:\n");
	p = head1;
	while (p)
	{
		printf("Node value: %s\n", (char*)p->data);
		p = p->next;
	}

	return 0;
}*/
