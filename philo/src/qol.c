/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:05:33 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/09 20:26:30 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	error(char *error)
{
	printf("%s", error);
	return (1);
}

int	mem_check(void *ptr)
{
	if (ptr == NULL)
		return (1);
	return (0);
}

int	close_programm(t_main *main)
{
	t_philo	*cur;
	int		i;

	pthread_join(main->checker, NULL);
	if (main->head != NULL)
	{
		cur = main->head;
		while (cur != NULL)
		{
			pthread_detach(cur->id);
			cur = cur->next;
		}
		del_lst(&main->head, &main->tail);
	}
	pthread_mutex_destroy(&main->write);
	pthread_mutex_destroy(&main->eat);
	i = 0;
	while (i < main->args.n)
		pthread_mutex_destroy(&main->fork[i++]);
	free(main->fork);
	return (1);
}

int	join_programm(t_main *main)
{
	t_philo	*cur;
	int		i;
												 
	cur = main->head;
	while (cur != NULL)
	{
		pthread_join(cur->id, NULL);
		cur = cur->next;
	}
	del_lst(&main->head, &main->tail);
	pthread_detach(main->checker);
	pthread_mutex_destroy(&main->write);
	pthread_mutex_destroy(&main->eat);
	i = 0;
	while (i < main->args.n)
		pthread_mutex_destroy(&main->fork[i++]);
	free(main->fork);
	return (0);
}
