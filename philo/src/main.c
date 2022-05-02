/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:58:26 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/02 20:36:47 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_main	main;
	int		status;
	t_philo	*cur;
	t_philo	philo;

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
	cur = main.head;
	gettimeofday(&philo.time.begin, NULL);
	while (cur != NULL && status == 0)
	{
		philo = *cur;
		status = pthread_create(&cur->id, NULL, p_thread, &philo);
		cur = cur->next;
	}
	if (status != 0)
		return (close_programm(&main));
	cur = main.head;
	status = -1;
	while (cur != NULL)
	{
		while (status != 0)
			status = pthread_join(cur->id, NULL);
		cur = cur->next;
	}
	return (0);
}
