/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:43:18 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/28 16:57:37 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*
 * Authorized Functions Library
*/

# include <string.h>	/* memset function */
# include <stdio.h> 	/* printf function */
# include <stdlib.h>	/* malloc, free functions */
# include <stddef.h>	/* Size_t variable */
# include <unistd.h>	/* write, usleep functions */
# include <sys/time.h>	/* gettimeofday function */
# include <pthread.h>	/* threads and mutex functions */

/*
 * Default Library
*/

# include "philosophers.h"
# include "utils.h"

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

typedef struct s_args
{
	long	n;
	long	t_death;
	long	t_eat;
	long	t_sleep;
	long	n_eat;
}				t_args;

typedef struct s_philo
{
	struct s_philo	*next;
	struct s_philo	*prev;
	int				i;
	pthread_t		id;
}				t_philo;

typedef struct s_main
{
	t_time	time;
	t_args	args;
	t_philo	*head;
	t_philo	*tail;
}				t_main;

/*
 * QOL functions
*/

int		error(char *error);
int		mem_check(void *ptr);

/*
 * Args Functions
*/

int		philo_args(t_main *main, char **argv);

/*
 * Linked List
*/

int		add_lst(t_main main, int n);

/*
 * Time Functions
*/

double	timer_ms(t_time *time);

#endif
