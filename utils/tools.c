/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:26:54 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/28 18:00:53 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// unsigned long	timestamp(void)
// {
// 	struct timeval	tv;

// 	gettimeofday(&tv, NULL);
// 	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
// }

long	timestamp(void)
{
	struct timeval  tp;
	long            milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

void	ft_ms_sleep(long time_ms)
{
	long	sleep_time;

	sleep_time = timestamp();
	while (1)
	{
		if (sleep_time + time_ms <= timestamp())
			break ;
		usleep(100);
	}
}

void	print_message(t_data *data, char *status, int id)
{
	pthread_mutex_lock(&data->status);
	if (id == -1)
		printf("%ld %s\n", (timestamp() - data->start), status);
	else
	{
		printf("%ld %d %s\n", (timestamp() - data->start),
			id + 1, status);
	}
	pthread_mutex_unlock(&data->status);
}
