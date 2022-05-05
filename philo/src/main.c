/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:58:26 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/05 19:51:34 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_main			main;
	int				status;
	t_philo			*cur;

	if (argc < 5 || argc > 6)
		return (error(NARG));
	if (bin_start(&main, argv) == 1)
		return (1);
	gettimeofday(&main.start, NULL);
	main.i = 1;
	cur = main.head;
	while (main.i <= main.args.n && status == 0)
	{
		status = pthread_create(&cur->id, NULL, p_thread, &main);
		usleep(200);
		main.i++;
		cur = cur->next;
	}
	if (status != 0)
		return (close_programm(&main));
	/////////////////////////////////////////////
	cur = main.head;
	status = -1;
	while (cur != NULL)
	{
		while (status != 0)
			status = pthread_join(cur->id, NULL);
		if (main.d_or_n == 1)
			return (close_programm(&main));
		cur = cur->next;
		status = -1;
	}
	close_programm(&main);
	return (0);
}
