/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:10:59 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/07 16:16:11 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{

}

#include <stdio.h>
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

	ft_list_reverse(&head);

	p = head;
	while (p)
	{
		printf("List node contains: %s\n", (char*)p->data);
		p = p->next;
	}

	return 0;
}
