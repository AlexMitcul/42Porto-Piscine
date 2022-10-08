/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:07:53 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/05 22:15:18 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

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

/* #include <stdio.h>
int main()
{
	t_list	*head;

	head = NULL;
	ft_list_push_back(&head, "I'm first");
	ft_list_push_back(&head, "I'm second");
	ft_list_push_back(&head, "I'm last");

	while (head)
	{
		printf("List node contains: %s\n", (char*)head->data);
		head = head->next;
	}

	return 0;
} */
