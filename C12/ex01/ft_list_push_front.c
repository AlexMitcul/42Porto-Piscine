/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:06:36 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/05 19:30:11 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

#include <stdio.h>


void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*item;

	item = ft_create_elem(data);
	if (begin_list == 0)
		printf("begin list is NULL\n");
	if (*begin_list == 0)
		printf("begin list is NULL");
	if (!begin_list || !(*begin_list))
		begin_list = &item;
	else
	{
		item->next = *begin_list;
		*begin_list = item;
	}
}

int main()
{
	t_list	*list;

	list = 0;
	ft_list_push_front(&list, "42");
	// ft_list_push_front(&list, "21");
	// ft_list_push_front(&list, "0");

	while (list && list->next != 0)
	{
		printf("%s\n", (char*)list->data);
		list = list->next;
	}
	return 0;
}

