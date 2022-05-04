/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:24:33 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/04 20:18:12 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*p_thread(void *arg_struct)
{
	t_main	*thread;
	t_philo	*cur;
	int		i;

	thread = (t_main *)arg_struct;
	i = thread->i;
	cur = thread->head;
	while (cur->i < i && cur != NULL)
		cur = cur->next;
	gettimeofday(&cur->time_eat, NULL);
	while (1)
	{
		if (check_death(cur, thread) == 1)
			return (NULL);
	}
	return (0);
}
