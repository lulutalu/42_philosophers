/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:47:02 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/26 19:49:27 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philo_args(t_main *main, char **argv)
{
	main->args.n = ft_atol(argv[1]);
	main->args.t_death = ft_atol(argv[2]);
	main->args.t_eat = ft_atol(argv[3]);
	main->args.t_sleep = ft_atol(argv[4]);
	if (argv[5] != NULL)
		main->args.n_eat = ft_atol(argv[5]);
	if (main->args.n < INT_MIN || main->args.n > INT_MAX)
		return (error(INT_LIM));
	if (main->args.t_death < INT_MIN || main->args.t_death > INT_MAX)
		return (error(INT_LIM));
	if (main->args.t_eat < INT_MIN || main->args.t_eat > INT_MAX)
		return (error(INT_LIM));
	if (main->args.t_sleep < INT_MIN || main->args.t_sleep > INT_MAX)
		return (error(INT_LIM));
	if (main->args.n_eat < INT_MIN || main->args.n_eat > INT_MAX)
		return (error(INT_LIM));
	return (0);
}
