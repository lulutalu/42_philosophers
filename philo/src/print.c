/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:52:09 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/09 19:36:46 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_death(t_philo *philo, t_main *main)
{
	pthread_mutex_lock(&main->write);
	printf("|\e[1;31m 💀\t Philo %d\t died at     \t\e[1;32m%.1f ms\
\e[1;97m\t|\n", philo->i, timer_ms(main->start, philo->now));
	printf("--------------------------------------------------------\e[0m\n");
	pthread_mutex_unlock(&main->write);
}

void	print_take_fork(t_main *main, t_philo *philo)
{
	gettimeofday(&philo->now, NULL);
	pthread_mutex_lock(&main->write);
	printf("| 🥄\t Philo %d\t has taken a fork at \t\e[1;32m%.1f ms\e[1;97m\t|\
			\n", philo->i, timer_ms(main->start, philo->now));
	printf("---------------------------------------------------------------\n");
	pthread_mutex_unlock(&main->write);
}

void	print_eat(t_main *main, t_philo *philo)
{
	gettimeofday(&philo->now, NULL);
	pthread_mutex_lock(&main->write);
	printf("| 🍝\t Philo %d\t is eating at        \t\e[1;32m%.1f ms\
\e[1;97m\t|\n", philo->i, timer_ms(main->start, philo->now));
	printf("---------------------------------------------------------------\n");
	pthread_mutex_unlock(&main->write);
}

void	print_sleep(t_main *main, t_philo *philo)
{
	gettimeofday(&philo->now, NULL);
	pthread_mutex_lock(&main->write);
	printf("| 💤\t Philo %d\t is sleeping at      \t\e[1;32m%1.f ms\e[1;97m \
\t|\n", philo->i, timer_ms(main->start, philo->now));
	printf("---------------------------------------------------------------\n");
	pthread_mutex_unlock(&main->write);
}

void	print_thinking(t_main *main, t_philo *philo)
{
	gettimeofday(&philo->now, NULL);
	pthread_mutex_lock(&main->write);
	printf("| 💭\t Philo %d\t is thinking at      \t\e[1;32m%1.f ms\e[1;97m \
\t|\n", philo->i, timer_ms(main->start, philo->now));
	printf("---------------------------------------------------------------\n");
	pthread_mutex_unlock(&main->write);
}
