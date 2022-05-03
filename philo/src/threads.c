/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:24:33 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/03 19:23:19 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*p_thread(void *arg_struct)
{
	t_main	*thread;
	t_philo	*cur;
	int		cpt;

	thread = (t_main *)arg_struct;
	pthread_mutex_lock(&thread->lock);
	cur = thread->head;
	cpt = 1;
	while (cpt++ < thread->i)
		cur = cur->next;
	printf("Thread n : %d\n", cur->i);
	usleep(1000);
	gettimeofday(&thread->time.actual, NULL);
	printf("Time passed in ms : %.2f\n", timer_ms(&thread->time));
	pthread_mutex_unlock(&thread->lock);
	return (0);
}
