/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:38:44 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/28 16:57:38 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	add_lst(t_main main, int n)
{
	t_philo	*new;

	new = ft_calloc(1, sizeof(t_philo));
	if (mem_check(new) == 1)
		return (1);
	if (main.head == NULL)
	{
		new->i = n;
		new->prev = NULL;
		new->next = NULL;
		main.head = new;
		main.tail = main.head;
	}
	else
	{
		new->i = n;
		new->prev = main.tail;
		new->next = main.head;
		main.tail = new;
	}
	return (0);
}
