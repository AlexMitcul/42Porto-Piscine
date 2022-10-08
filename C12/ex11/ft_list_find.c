/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:01:48 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/07 23:06:52 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if ((*cmp)(begin_list->data, data_ref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (0);
}

/* #include <stdio.h>

void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
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
	p = ft_list_find(head, (void*)"123", &ft_strcmp);
	printf("Find node data is %s\n", (char*)(p->data));


	return 0;
} */
