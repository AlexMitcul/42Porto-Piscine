/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:29:41 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/08 19:53:37 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"


/* two pointers version */
// Need to test
void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*first;
	t_list	*second;
	t_list	*tmp;

	first = *begin_list;
	while (first != 0)
	{
		second = *begin_list;
		while (second->next != 0)
		{
			if ((*cmp)(second->data, second->next->data) > 0)
			{
				tmp->data = second->data;
				second->data = second->next->data;
				second->next->data = tmp->data;
			}
			second = second->data;
		}
		first = first->data;
	}
}

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

/* #include <stdio.h>

void	ft_putstr(char *str);
void	ft_list_push_back(t_list **begin_list, void *data);

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
	ft_list_sort(&head, &ft_strcmp);
	printf("\n=========================\n");
	p = head;
	while (p)
	{
		printf("List node contains: %s\n", (char*)p->data);
		p = p->next;
	}


	return 0;
} */
