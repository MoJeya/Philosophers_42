/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:47:01 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/27 18:47:42 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	kill_all(t_data *data, int id)
{
	data->is_dead = 1;
	print_message(data, "is Dead!", id);
	usleep(1000);
	return (0);
}

int	all_eaten(t_data *data, int id)
{
	if (data->philo[id].meals == data->meals_to_eat)
		data->meals_eaten++;
	if (data->meals_eaten == data->meals_to_eat)
	{
		data->is_running = 1;
		print_message(data, "Everyone has eaten!", id);
		usleep(100);
		return (0);
	}
	return (1);
}

void	*death_loop(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (1)
	{
		if (data->philo[i].last_meal > 0.1
			&& (timestamp() - data->philo[i].last_meal)
			> data->time_to_die)
		{
			data->is_dead = 1;
			if (kill_all(data, i) != 1)
				return (0);
		}	
		if (all_eaten(data, i) != 1)
		{	
			data->is_running = 1;
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

	if (pthread_create(&id, NULL, &death_loop, data) != 0)
		return (1);
	pthread_join(id, NULL);
	return (0);
}
