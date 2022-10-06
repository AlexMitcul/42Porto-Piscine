/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:19:41 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/06 23:17:10 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref,
	int (*cmp)())
{
	while (begin_list)
	{
		if ((*cmp)(begin_list->data, data_ref) == 0)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

#include <stdio.h>
#include <unistd.h>

void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_putstr(void *str);
int		ft_strcmp(char *s1, char *s2);

int main()
{
	t_list	*head;
	t_list	*p;

	head = NULL;
	ft_list_push_back(&head, "42");
	ft_list_push_back(&head, "324");
	ft_list_push_back(&head, "123");
	ft_list_push_back(&head, "42");

	p = head;
	while (head)
	{
		printf("List node contains: %s\n", (char*)head->data);
		head = head->next;
	}
	ft_list_foreach_if(p, &ft_putstr, (void*)"42", &ft_strcmp);

	return 0;
}

