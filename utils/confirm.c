/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:47:01 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/24 14:59:27 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	kill_all(t_data *data, int id)
{
	int	i;

	pthread_mutex_lock(&data->status);
	data->is_dead = 1;
	printf("%li %i died\n",(timestamp() - data->start) / 1000, id);
	usleep(1000);
	i = 0;
	while (i < data->nb_of_phil)
		pthread_detach(data->philo[i++].thread_id);
}

void	*death_rountine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (1)
	{
		if (((timestamp() - data->philo[i].last_meal) / 1000)
			> (long)data->time_to_die)
		{
			kill_all(data, i);
			return (0);
		}
		if (i == data->nb_of_phil)
			i = 0;
		i++;
	}
	return (NULL);
}

int	check_death(t_data *data)
{
	pthread_t	id;

	if (pthread_create(&id, NULL, &death_rountine, data) != 0)
		return (1);
	pthread_join(id, NULL);
	return (0);
}