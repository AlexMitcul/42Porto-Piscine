/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:17:02 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/07 16:27:15 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// Need to test

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list	*p;
	t_list	*tmp;

	p = *begin_list;
	while (p && p->next)
	{
		if ((*cmp)(p->data, data_ref) == 0)
		{
			tmp = p->next;
			p->next = p->next->next;
			(*free_fct)(tmp->data);
			free(tmp);
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

int		ft_strcmp(char *s1, char *s2);
void	ft_list_push_back(t_list **begin_list, void *data);

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

	ft_list_remove_if(&head, (void*)"42", &ft_strcmp, &free_data);

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
