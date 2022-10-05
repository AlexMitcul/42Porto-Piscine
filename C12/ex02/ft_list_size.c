/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:22:54 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/05 21:40:58 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/* t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data); */

/**
 * Function 'ft_list_size' which returns the
 * number of elements in the list.
**/

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		count += 1;
	}
	return (count);
}

/* #include <stdio.h>
int main()
{
	t_list	*head;

	head = NULL;
	ft_list_push_front(&head, "42");
	ft_list_push_front(&head, "21");
	ft_list_push_front(&head, "42");
	printf("List size is %d\n", ft_list_size(head));

	return 0;
} */
