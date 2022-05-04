/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:44:52 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/04 20:18:09 by lduboulo         ###   ########.fr       */
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

int	check_death(t_philo	*philo, t_main *main)
{
	double	time;

	gettimeofday(&philo->now, NULL);
	time = timer_ms(philo->time_eat, philo->now);
	if (time > (double)main->args.t_death)
	{
		pthread_mutex_lock(&main->write);
		printf("Philo %d died at %.2f ms\n", philo->i, \
				timer_ms(main->start, philo->now));
		pthread_mutex_unlock(&main->write);
		return (1);
	}
	return (0);
}
