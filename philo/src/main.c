/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:58:26 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/02 14:42:12 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_main	main;
	int		status;
	t_philo	*cur;

	if (argc < 5 || argc > 6)
		return (error(NARG));
	if (philo_args(&main, argv) != 0)
		return (1);
	gettimeofday(&main.time.begin, NULL);
	main.head = NULL;
	main.tail = NULL;
	main.i = 1;
	status = 0;
	while (main.i <= main.args.n && status != 1)
		status = add_lst(&main.head, &main.tail, main.i++);
	if (status == 1)
		del_lst(&main.head, &main.tail);
	main.head->prev = main.tail;
	main.tail->next = main.head;
	cur = main.head;
	while (cur->i <= main.args.n)
	{
		pthread_create(&cur->id, NULL, &thread, &main);
	}
	return (0);
}
