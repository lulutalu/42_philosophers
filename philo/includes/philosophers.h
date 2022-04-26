/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:43:18 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/26 16:28:19 by lduboulo         ###   ########.fr       */
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

# define NARG "\e[1;91mNumber of arguments incorrect\n\e[0m"

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
	struct timeval	end;
}				t_time;

typedef struct s_philo
{
	int	n;
	int	t_death;
	int	t_eat;
	int	t_sleep;
	int	n_eat;
}				t_philo;

/*
 * QOL functions
*/

int		error(char *error);

/*
 * Args Functions
*/

void	philo_args(t_philo *philo, char **argv);

#endif
