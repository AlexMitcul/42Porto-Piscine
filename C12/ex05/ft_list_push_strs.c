/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:15:57 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/11 17:21:40 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

static void	ft_list_push_front(t_list **begin_list, void *data)
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

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*head;
	int		i;

	i = 0;
	head = 0;
	while (i < size)
	{
		ft_list_push_front(&head, (void *)strs[i]);
		i++;
	}
	return (head);
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
