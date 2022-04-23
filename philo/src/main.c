/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:58:26 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/23 20:05:18 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*test(void *th)
{
	t_thread	*myth;
	int			t;

	myth = (t_thread *)th;
	t = 0;
	pthread_mutex_lock(&myth->mute);
	myth->i++;
	while (t < 9999999)
		t++;
	printf("%d\n", myth->i);
	pthread_mutex_unlock(&myth->mute);
	return (0);
}

int	main()
{
	pthread_t		id1;
	pthread_t		id2;
	t_thread		th;

	th.i = 0;
	if (pthread_mutex_init(&th.mute, NULL) < 0)
		exit (1);
	if (pthread_create(&id1, NULL, test, &th) < 0)
		exit (1);
	if (pthread_create(&id2, NULL, test, &th) < 0)
		exit (1);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	printf("c'est la fin\n");
	pthread_mutex_destroy(&th.mute);
	return (0);
}
