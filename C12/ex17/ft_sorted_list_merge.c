/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:11:34 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/07 23:54:35 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

//! KO

static void	move(t_list **dest, t_list **src)
{
	t_list	*p;

	p = *src;
	*src = p->next;
	p->next = *dest;
	*dest =  p;
}

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	t_list	*fist_lst = *begin_list1;
	t_list	head;
	t_list	*curr;

	head.next = 0;
	curr = &head;
	while (1)
	{
		if (fist_lst == 0)
		{
			curr->next = begin_list2;
			break ;
		}
		else if (begin_list2 == 0)
		{
			curr->next = fist_lst;
			break ;
		}
		if ((*cmp)(fist_lst->data, begin_list2->data) > 0)
			move(&(curr->next), &fist_lst);
		else
			move(&(curr->next), &begin_list2);
		curr = curr->next;
	}
	*begin_list1 = head.next;
}


#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *str);
void	ft_list_push_back(t_list **begin_list, void *data);

int	compare(void *a, void *b)
{
	int	a_int = atoi((char*)a);
	int	b_int = atoi((char*)b);
	printf("%d-%d\n", a_int, b_int);
	return (a_int - b_int);
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
}
