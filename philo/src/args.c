/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:47:02 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/26 18:04:36 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philo_args(t_philo *philo, char **argv)
{
	philo->n = ft_atol(argv[1]);
	philo->t_death = ft_atol(argv[2]);
	philo->t_eat = ft_atol(argv[3]);
	philo->t_sleep = ft_atol(argv[4]);
	if (argv[5] != NULL)
		philo->n_eat = ft_atol(argv[5]);
	if (philo->n < INT_MIN || philo->n > INT_MAX)
		return (error(INT_LIM));
	if (philo->t_death < INT_MIN || philo->t_death > INT_MAX)
		return (error(INT_LIM));
	if (philo->t_eat < INT_MIN || philo->t_eat > INT_MAX)
		return (error(INT_LIM));
	if (philo->t_sleep < INT_MIN || philo->t_sleep > INT_MAX)
		return (error(INT_LIM));
	if (philo->n_eat < INT_MIN || philo->n_eat > INT_MAX)
		return (error(INT_LIM));
	return (0);
}
