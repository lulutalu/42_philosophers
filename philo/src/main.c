/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:58:26 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/26 16:28:21 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

float	mspassed(float pass, float upass)
{
	return ((pass * 1000) + (upass / 1000));
}

float	calcul(t_time *time)
{
	float	pass;
	float	upass;

	pass = time->end.tv_sec - time->begin.tv_sec;
	upass = time->end.tv_usec - time->begin.tv_usec;
	return (mspassed(pass, upass));
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc < 5 || argc > 6)
		return (error(NARG));
	philo_args(&philo, argv);
	return (0);
}