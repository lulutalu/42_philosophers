/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:05:33 by lduboulo          #+#    #+#             */
/*   Updated: 2022/05/04 18:39:55 by lduboulo         ###   ########.fr       */
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

	cur = main->head;
	while (cur->i <= main->args.n)
	{
		pthread_detach(cur->id);
		cur = cur->next;
	}
	del_lst(&main->head, &main->tail);
	return (1);
}
