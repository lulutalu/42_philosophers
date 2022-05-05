/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:24:33 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/05 19:52:32 by lduboulo         ###   ########.fr       */
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
		if (thread->d_or_n == 1)
			usleep(10000);
		if (check_death(cur, thread) == 1)
			return (NULL);
	}
	return (0);
}

void	eat(t_main *main, t_philo *philo)
{
	if (philo->i == 1)
	{
		pthread_mutex_lock(&main->fork[0]);
		pthread_mutex_lock(&main->fork[main->args.n - 1]);
		gettimeofday(&philo->time_eat, NULL);
		gettimeofday(&philo->now, NULL);
		pthread_mutex_lock(&main->write);
		printf("Philo %d eat at %.1f ms\n", philo->i, \
				timer_ms(main->start, philo->now));
		pthread_mutex_unlock(&main->write);
		pthread_mutex_unlock(&main->fork[0]);
		pthread_mutex_unlock(&main->fork[main->args.n - 1]);
	}
}
