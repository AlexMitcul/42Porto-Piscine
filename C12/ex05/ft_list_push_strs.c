/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:15:57 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/07 22:54:58 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);


// Change to ft_list_push_front
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

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*head;
	int		i;

	i = 0;
	head = 0;
	while (i < size)
	{
		ft_list_push_back(&head, (void *)strs[i]);
		i++;
	}
	return (head);
}

/* #include <stdio.h>
int main()
{
	t_list	*head;
	char	*strs[3] = {
		"I'm first",
		"I'm second",
		"I'm third"
	};

	head = ft_list_push_strs(3, strs);
	while (head)
	{
		printf("List node contains: %s\n", (char*)head->data);
		head = head->next;
	}

	return 0;
} */
