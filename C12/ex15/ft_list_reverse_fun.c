/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:30:51 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/08 19:53:02 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static int	ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*p;

	count = 0;
	p = begin_list;
	while (p)
	{
		p = p->next;
		count += 1;
	}
	return (count);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*p;

	p = begin_list;
	while (p && nbr)
	{
		p = p->next;
		nbr--;
	}
	return (p);
}

void	swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void ft_list_reverse_fun(t_list *begin_list)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_list_size(begin_list);
	while (i < len / 2)
	{
		swap(&(ft_list_at(begin_list, i)->data), &(ft_list_at(begin_list, len - i - 1)->data));
		i++;
	}
}

/* #include <stdio.h>

void	ft_list_push_back(t_list **begin_list, void *data);

int main()
{
	t_list	*head;
	t_list	*p;

	head = 0;
	ft_list_push_back(&head, "one");
	ft_list_push_back(&head, "two");
	ft_list_push_back(&head, "three");
	ft_list_push_back(&head, "four");

	p = head;
	while (p)
	{
		printf("List node contains: %s\n", (char*)p->data);
		p = p->next;
	}
	//void ft_list_reverse_fun(t_list *begin_list)
	ft_list_reverse_fun(head);
	printf("\n=========================\n");
	p = head;
	while (p)
	{
		printf("List node contains: %s\n", (char*)p->data);
		p = p->next;
	}


	return 0;
} */
