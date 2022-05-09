/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:58:26 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/09 20:25:05 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_main	main;
	t_philo	*cur;
	int		status;

	if (argc < 5 || argc > 6)
		return (error(NARG));
	if (bin_start(&main, argv) == 1)
		return (1);
	gettimeofday(&main.start, NULL);
	printf("\e[1;97m---------------------------------------------------------\n");
	if (thread_init(&main) != 0)
		return (close_programm(&main));
	if (pthread_create(&main.checker, NULL, check_death, &main) != 0)
		return (close_programm(&main));
	if (main.args.n_eat != -1)
		return (join_programm(&main));
	cur = main.head;
	status = -1;
	close_programm(&main);
	return (0);
}
