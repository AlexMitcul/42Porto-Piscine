/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexmitcul <alexmitcul@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:11:34 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/09 01:52:09 by alexmitcul       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
*	Step 1: Merge two lists
*	Step 2: Sort that list
*/

static void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*p;

	p = *begin_list1;
	while (p->next)
		p = p->next;
	p->next = begin_list2;
}

static void	ft_list_sort(t_list **begin_list, int (*cmp)())
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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}

/* #include <stdio.h>
#include <stdlib.h>

int	compare(void *a, void *b)
{
	int	a_int = atoi((char*)a);
	int	b_int = atoi((char*)b);
	printf("%d-%d\n", a_int, b_int);
	return (a_int - b_int);
}

void	ft_list_push_back(t_list **begin_list, void *data);

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
} */
