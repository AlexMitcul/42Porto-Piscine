/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:43:13 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/08 18:08:29 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char const *argv[])
{
	for (int i = 1; i < argc; i++)
		printf("%s\n", argv[i]);

	return 0;
}
