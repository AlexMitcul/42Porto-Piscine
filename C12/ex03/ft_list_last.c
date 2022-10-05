/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:42:56 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/05 22:06:12 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/* void	ft_list_push_front(t_list **begin_list, void *data); */

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*p;

	p = begin_list;
	while (p->next)
		p = p->next;
	return (p);
}

/* #include <stdio.h>
int main()
{
	t_list	*head;

	head = NULL;
	ft_list_push_front(&head, "I'm last!!!");
	ft_list_push_front(&head, "21");
	ft_list_push_front(&head, "42");

	head = ft_list_last(head);
	printf("Last item contains\n%s\n", (char*)head->data);

	return 0;
} */
