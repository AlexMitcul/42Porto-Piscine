/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:06:36 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/08 15:40:18 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_push_front(t_list **begin_list, void *data)
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

/* #include <stdlib.h>
int main()
{
	t_list	*head;

	head = NULL;
	ft_list_push_front(&head, "42");
	ft_list_push_front(&head, "21");
	ft_list_push_front(&head, "0");

	while (head)
	{
		printf("%s\n", (char*)head->data);
		head = head->next;
	}
	return 0;
}
 */
