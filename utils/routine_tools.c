/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:51:32 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/24 01:43:38 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	eat(int id, t_data *data)
{
	int	max_phil;

	max_phil = data->nb_of_phil;
	if (id % 2)
	{
		pthread_mutex_lock(&data->philo[id].fork);
		print_message(data, "has taken a fork", id);
		pthread_mutex_lock(&data->philo[(id + 1) % max_phil].fork);
		print_message(data, "has taken a fork", id);
	}
	else
	{
		pthread_mutex_lock(&data->philo[(id + 1) % max_phil].fork);
		print_message(data, "has taken a fork", id);
		pthread_mutex_lock(&data->philo[id].fork);
		print_message(data, "has taken a fork", id);
	}
	data->philo[id].last_meal = timestamp();
	print_message(data, "is eating", id);
	ft_ms_sleep(data->time_to_eat * 1000);
	pthread_mutex_unlock(&data->philo[id].fork);
	pthread_mutex_unlock(&data->philo[(id + 1) % max_phil].fork);
	data->philo[id].meals++;
}

void	take_nap(t_data *data, int id)
{
	print_message(data, "is sleeping", id);
	ft_ms_sleep(data->time_to_sleep * 1000);
}

void	think(t_data *data, int id)
{
	print_message(data, "is thinking", id);
}

void	*routine(void *arg)
{
	struct s_philo	*philo;

	philo = (struct s_philo *)arg;
	if (philo->id % 2)
		ft_ms_sleep(1);
	while (philo->meals < philo->data->meals_to_eat)
	{
		eat(philo->id, philo->data);
		take_nap(philo->data, philo->id);
		think(philo->data, philo->id);
	}
	return (NULL);
}

int	creat_data(t_data *data)
{
	int				cnt;

	cnt = 0;
	data->start = timestamp();
	while (cnt < data->nb_of_phil)
	{
		data->philo[cnt].data = data;
		if (pthread_create(&data->philo[cnt].thread_id, NULL, &routine,
				&data->philo[cnt]) != 0)
			return (1);
		cnt++;
	}
	return (0);
}

