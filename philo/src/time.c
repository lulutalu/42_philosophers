/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:44:52 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/09 20:35:21 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

double	timer_ms(struct timeval start, struct timeval now)
{
	double	pass;
	double	upass;

	pass = now.tv_sec - start.tv_sec;
	upass = now.tv_usec - start.tv_usec;
	return ((pass * 1000) + (upass / 1000));
}

void	*check_death(void *arg_struct)
{
	t_main	*checker;
	t_philo	*cur;
	int		time;

	checker = (t_main *)arg_struct;
	while (1)
	{
		cur = checker->head;
		while (cur != NULL)
		{
			gettimeofday(&cur->now, NULL);
			usleep(3000);
			time = (int)timer_ms(cur->time_eat, cur->now);
			if (time > checker->args.t_death)
			{
				print_death(cur, checker);
				checker->d_or_n = 1;
				pthread_mutex_lock(&checker->write);
				return (0);
			}
			cur = cur->next;
		}
	}
}
