/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:58:26 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/28 16:57:38 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_main	main;
	int		i;
	t_philo	*cur;

	if (argc < 5 || argc > 6)
		return (error(NARG));
	if (philo_args(&main, argv) != 0)
		return (1);
	i = 1;
	while (i <= main.args.n)
		add_lst(main, i++);
	cur = main.head;
	while (cur != main.tail)
	{
		printf("Pos : %d\n", cur->i);
		cur = cur->next;
	}
	gettimeofday(&main.time.begin, NULL);
	return (0);
}
