/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:26:12 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/24 01:46:34 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	free_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_phil)
	{
		pthread_mutex_destroy(&data->philo[i].fork);
		i++;
	}
	pthread_mutex_destroy(&data->status);
	free(data->philo);
}