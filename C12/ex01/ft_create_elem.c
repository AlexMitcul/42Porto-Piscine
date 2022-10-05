/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:58:29 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/05 19:21:45 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*item;

	item = (t_list*) malloc(sizeof(t_list));
	if (!item)
		return (NULL);
	item->data = data;
	item->next = NULL;
	return (item);
}

/* #include <stdio.h>
int main()
{
	t_list	*item;
	int	data = 42;

	item = ft_create_elem(&data);
	if (item != NULL)
	{
		printf("Item data is %d\n", (*(int *)item->data));
		if (!item->next)
			printf("Item next is NULL\n");
	}
	return 0;
} */
