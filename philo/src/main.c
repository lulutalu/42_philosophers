/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:58:26 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/04 20:18:13 by lduboulo         ###   ########.fr       */
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
	if (philo_args(&main, argv) != 0)
		return (1);
	main.head = NULL;
	main.tail = NULL;
	main.i = 1;
	status = 0;
	while (main.i <= main.args.n && status != 1)
		status = add_lst(&main.head, &main.tail, main.i++);
	if (status == 1)
		return (del_lst(&main.head, &main.tail));
	/////////////////////////////////////////////
	gettimeofday(&main.start, NULL);
	if (pthread_mutex_init(&main.write, NULL) != 0)
		return (1);
	////////////////////////////////////////////
	main.i = 1;
	cur = main.head;
	while (main.i <= main.args.n && status == 0)
	{
		status = pthread_create(&cur->id, NULL, p_thread, &main);
		usleep(100);
		main.i++;
		cur = cur->next;
	}
	if (status != 0)
		return (close_programm(&main));
	/////////////////////////////////////////////
	cur = main.head;
	while (cur != NULL)
	{
		pthread_join(cur->id, NULL);
		cur = cur->next;
	}
	pthread_mutex_destroy(&main.write);
	return (0);
}
