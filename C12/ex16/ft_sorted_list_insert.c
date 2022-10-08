/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:55:28 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/08 19:12:38 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new_node;
	t_list	*p;

	new_node = ft_create_elem(data);
	p = *begin_list;
	if (!p || ((*cmp)(p->data, new_node->data) >= 0))
	{
		new_node->next = *begin_list;
		*begin_list = new_node;
		return ;
	}
	while (p->next != 0 && ((*cmp)(p->next->data, new_node->data) < 0))
		p = p->next;
	new_node->next = p->next;
	p->next = new_node;
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
	ft_list_push_back(&head, "1");
	ft_list_push_back(&head, "2");
	ft_list_push_back(&head, "3");
	ft_list_push_back(&head, "5");
	ft_list_push_back(&head, "6");
	ft_list_push_back(&head, "7");
	ft_list_push_back(&head, "8");

	p = head;
	while (p)
	{
		printf("List node contains: %s\n", (char*)p->data);
		p = p->next;
	}
	ft_sorted_list_insert(&head, (void*)"4", &ft_strcmp);

	printf("\n=========================\n");
	p = head;
	while (p)
	{
		printf("List node contains: %s\n", (char*)p->data);
		p = p->next;
	}


	return 0;
}
 */
