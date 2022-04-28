/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:05:33 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/27 15:35:54 by lduboulo         ###   ########.fr       */
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
