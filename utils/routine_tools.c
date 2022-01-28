/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:51:32 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/28 19:10:15 by mjeyavat         ###   ########.fr       */
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
	data->philo[id].meals++;
	data->philo[id].last_meal = timestamp();
	print_message(data, "is eating", id);
	ft_ms_sleep(data->time_to_eat);
	pthread_mutex_unlock(&data->philo[id].fork);
	pthread_mutex_unlock(&data->philo[(id + 1) % max_phil].fork);
}

void	take_nap(t_data *data, int id)
{
	print_message(data, "is sleeping", id);
	ft_ms_sleep(data->time_to_sleep);
}

void	think(t_data *data, int id)
{
	print_message(data, "is thinking", id);
}

void	*routine(void *arg)
{
	struct s_philo	*philo;

	philo = (struct s_philo *)arg;
	while (1)
	{
		if (philo->data->init_cnt == philo->data->nb_of_phil)
			break ;
	}
	if (philo->id % 2)
		usleep(50);
	philo->data->start = timestamp();
	philo->last_meal = timestamp();
	while ((philo->data->meals_to_eat == -1
			|| philo->meals < philo->data->meals_to_eat)
				&& philo->data->is_dead == 0
						&& philo->data->is_running == 0)
	{
		eat(philo->id, philo->data);
		take_nap(philo->data, philo->id);
		think(philo->data, philo->id);
	}
	return (NULL);
}

int	creat_data(t_data *data)
{
	data->init_cnt = 0;
	while (data->init_cnt < data->nb_of_phil)
	{
		data->philo[data->init_cnt].data = data;
		if (pthread_create(&data->philo[data->init_cnt].thread_id, NULL, &routine,
				&data->philo[data->init_cnt]) != 0)
			return (1);
		data->init_cnt++;
		data->is_dead = 0;
	}
	return (0);
}
