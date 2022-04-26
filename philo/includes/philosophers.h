/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:43:18 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/26 18:04:35 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*
 * Default Library
*/

# include "philosophers.h"
# include "utils.h"

/*
 * Authorized Functions Library
*/

# include <string.h>	/* memset function */
# include <stdio.h> 	/* printf function */
# include <stdlib.h>	/* malloc, free functions */
# include <unistd.h>	/* write, usleep functions */
# include <sys/time.h>	/* gettimeofday function */
# include <pthread.h>	/* threads and mutex functions */

/*
 * Macro for error
*/

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define NARG "\e[1;91mNumber of arguments incorrect\n\e[0m"
# define INT_LIM "\e[1;91mArgs value exceed integer limit\n\e[0m"

/*
 * Variables Structures
*/

typedef struct s_thread
{
	pthread_t		id;
	pthread_mutex_t	mute;
	int				i;
}				t_thread;

typedef struct s_time
{
	struct timeval	begin;
	struct timeval	actual;
}				t_time;

typedef struct s_philo
{
	long	n;
	long	t_death;
	long	t_eat;
	long	t_sleep;
	long	n_eat;
}				t_philo;

/*
 * QOL functions
*/

int		error(char *error);

/*
 * Args Functions
*/

int		philo_args(t_philo *philo, char **argv);

/*
 * Time Functions
*/

double	timer_ms(t_time *time);

#endif
