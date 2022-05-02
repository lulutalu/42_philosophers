/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:38:44 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/02 14:42:14 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	add_lst(t_philo **head, t_philo **tail, int n)
{
	t_philo	*new;

	new = ft_calloc(1, sizeof(t_philo));
	if (mem_check(new) == 1)
		return (1);
	new->next = NULL;
	new->prev = NULL;
	new->i = n;
	if (*head == NULL)
	{
		*head = new;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		new->prev = (*tail);
		*tail = new;
	}
	return (0);
}

void	del_lst(t_philo	**head, t_philo **tail)
{
	while (*head != *tail)
		last_del_lst(tail);
	free(*head);
	*head = NULL;
	*tail = NULL;
}

void	last_del_lst(t_philo **tail)
{
	t_philo	*del;

	del = *tail;
	*tail = del->prev;
	free(del);
}
