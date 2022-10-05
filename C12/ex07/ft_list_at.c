/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:24:36 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/05 22:34:49 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

/* #include <stdio.h>
void	ft_list_push_back(t_list **begin_list, void *data);
int main()
{
	t_list	*head;
	t_list	*p;

	head = NULL;
	ft_list_push_back(&head, "I'm first");
	ft_list_push_back(&head, "I'm second");
	ft_list_push_back(&head, "I'm last");

	p = head;
	while (p)
	{
		printf("List node contains: %s\n", (char*)p->data);
		p = p->next;
	}
	printf("==========================\n");

	p = ft_list_at(head, 0);
	printf("List node at 0 is '%s'\n", (char*)p->data);	// I'm first
	p = ft_list_at(head, 2);
	printf("List node at 2 is '%s'\n", (char*)p->data);	// I'm last
	p = ft_list_at(head, 5);
	if (p == NULL)
		printf("List node at 5 is 'NULL'\n");	// NULL

	return 0;
}
 */
