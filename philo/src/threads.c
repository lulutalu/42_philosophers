/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:24:33 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/10 18:32:06 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*p_thread(void *arg_struct)
{
	t_main		*thread;
	t_philo		*cur;
	int			i;

	thread = (t_main *)arg_struct;
	i = thread->i;
	cur = thread->head;
	while (cur->i < i && cur != NULL)
		cur = cur->next;
	cur->eat = 0;
	gettimeofday(&cur->time_eat, NULL);
	if (thread->args.n_eat != -1)
	{
		while (thread->d_or_n != 1 && cur->eat < thread->args.n_eat)
		{
			philo(thread, cur);
			cur->eat++;
		}
	}
	else
		while (thread->d_or_n != 1)
			philo(thread, cur);
	return (0);
}

void	philo(t_main *main, t_philo *philo)
{
	if (philo->i == 1)
		action(main, philo, 0, main->args.n - 1);
	else if (philo->i % 2 == 0)
	{
		usleep(800);
		action(main, philo, philo->i - 1, philo->i - 2);
	}
	else
		action(main, philo, philo->i - 1, philo->i - 2);
}

void	action(t_main *main, t_philo *philo, int fork1, int fork2)
{
	pthread_mutex_lock(&main->fork[fork1]);
	print_take_fork(main, philo);
	pthread_mutex_lock(&main->fork[fork2]);
	print_take_fork(main, philo);
	print_eat(main, philo);
	usleep(main->args.t_eat);
	gettimeofday(&philo->time_eat, NULL);
	pthread_mutex_unlock(&main->fork[fork1]);
	pthread_mutex_unlock(&main->fork[fork2]);
	print_sleep(main, philo);
	usleep(main->args.t_sleep);
	print_thinking(main, philo);
}
