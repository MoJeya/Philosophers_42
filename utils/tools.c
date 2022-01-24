/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:26:54 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/24 01:46:29 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 * 1000 + tv.tv_usec);
}

void	ft_ms_sleep(useconds_t time_ms)
{
	time_t	sleep_time;

	sleep_time = timestamp();
	while (timestamp() < (sleep_time + time_ms))
		usleep(50);
}

void	print_message(t_data *data, char *status, int id)
{
	pthread_mutex_lock(&data->status);
	printf("%li %d %s\n", (timestamp() - (long)data->start) / 1000,
		id, status);
	pthread_mutex_unlock(&data->status);
}
