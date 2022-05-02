/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:24:33 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/02 20:25:08 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*p_thread(void *arg_struct)
{
	t_philo	*cur;

	cur = (t_philo *)arg_struct;
	printf("Thread : %d\n", cur->i);
	usleep(1000);
	gettimeofday(&cur->time.actual, NULL);
	printf("Time passed in ms : %f\n", timer_ms(&cur->time));
	return (0);
}
