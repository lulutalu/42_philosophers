/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:58:26 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/26 18:04:33 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	philo;
	t_time	time;

	if (argc < 5 || argc > 6)
		return (error(NARG));
	if (philo_args(&philo, argv) != 0)
		return (1);
	gettimeofday(&time.begin, NULL);
	usleep(1200);
	gettimeofday(&time.actual, NULL);
	printf("%.1f ms\n", timer_ms(&time));
	return (0);
}
