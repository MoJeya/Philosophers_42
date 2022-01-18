/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_in_ms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:23:31 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/18 18:15:38 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	time_in_ms(t_time_inf ti)
{
	gettimeofday(ti.t, ti.t_zone);
	ti.today = localtime(&ti.t->tv_sec);
	printf("It's %d:%0d:%0d.%d\n",
		ti.today->tm_hour,
		ti.today->tm_min,
		ti.today->tm_sec,
		ti.t->tv_usec);
}
