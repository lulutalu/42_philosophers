/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:44:52 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/26 17:48:34 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

double	timer_ms(t_time *time)
{
	double	pass;
	double	upass;

	pass = time->actual.tv_sec - time->begin.tv_sec;
	upass = time->actual.tv_usec - time->begin.tv_usec;
	return ((pass * 1000) + (upass / 1000));
}
