/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stamp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:26:54 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/21 13:49:31 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int64_t	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 * 1000 + tv.tv_usec);
}

int64_t	ft_timepass(struct s_philo philo)
{
	printf("1\n");

	int64_t	timeafter;
	int64_t	timestart;

	timestart = philo.last_meal;
	timeafter = timestart - timestamp();
	return (timeafter);
}
