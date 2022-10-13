/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:17:02 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/11 17:23:52 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list	*p;
	t_list	*tmp;

	p = *begin_list;
	while (p && p->next)
	{
		if ((*cmp)(p->next->data, data_ref) == 0)
		{
			tmp = p->next;
			p->next = p->next->next;
			(*free_fct)(tmp->data);
			free(tmp);
			p = *begin_list;
		}
		p = p->next;
	}
	p = *begin_list;
	if (p && (*cmp)(p->data, data_ref) == 0)
	{
		*begin_list = p->next;
		(*free_fct)(p->data);
		free(p);
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void	ft_list_push_back(t_list **begin_list, void *data)
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

void	free_data(void *data)
{
	if (data != NULL)
		free(data);
	return ;
}

int main()
{
	t_list	*head;
	t_list	*p;

	head = 0;
	ft_list_push_back(&head, strdup("42"));
	ft_list_push_back(&head, strdup("324"));
	ft_list_push_back(&head, strdup("123"));
	ft_list_push_back(&head, strdup("42"));
	ft_list_push_back(&head, strdup("42"));
	ft_list_push_back(&head, strdup("123"));
	ft_list_push_back(&head, strdup("123"));
	ft_list_push_back(&head, strdup("42"));

	p = head;
	while (p)
	{
		printf("List node contains: %s\n", (char*)p->data);
		p = p->next;
	}

	ft_list_remove_if(&head, (void*)"42", &strcmp, &free_data);

	printf("\n--- ======= ---\n");
	p = head;
	while (p)
	{
		if (p->data == NULL)
			printf("List node contains: NULL\n");
		else
			printf("List node contains: %s\n", (char*)p->data);
		p = p->next;
	}


	return 0;
} */
