/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:51:32 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/20 21:08:40 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*eat(t_data *data, int id)
{
	pthread_mutex_lock(&data->philo[id].fork);
	printf("Philosopher %d is eating\n", data->philo[id].id);
	usleep(3000);
	pthread_mutex_unlock(&data->philo[id].fork);
	printf("Philosopher %d has finisched eating!\n", data->philo[id].id);
	data->meals_eaten++;
	data->philo[id].last_meal = timestamp();
	data->philo[id].meals++;
	return (NULL);
}

void	*routine(void *arg)
{
	struct s_philo	*philo;

	philo = (struct s_philo *)arg;
	printf("Philosopher %d has enterd the room\n", philo->id);
	//eat
	//alle geraden sollen essen
	if (philo->id % 2 != 0)
		usleep(3000);
	else
	{
		while (philo->meals < philo->data->meals_to_eat || philo->data->death_lock == 0)
		{
			eat(philo->data, philo->id);
			sleep(philo->data, philo->id);
			think(philo->data, philo->id);
		}
		printf("%d is going to eat\n", philo->id);
	}
	//take a nap
	//think
	return (NULL);
}

int	creat_data(t_data *data)
{
	int	cnt;

	cnt = 1;
	while (cnt < data->nb_of_phil)
	{
		if (pthread_create(&data->philo[cnt].thread_id, NULL, &routine, &data->philo[cnt]) != 0)
		{
			return (1);
		}
		cnt++;
	}
	cnt = 0;
	while (cnt < data->nb_of_phil)
	{
		if (pthread_join(data->philo[cnt].thread_id, NULL) != 0)
			return (0);
	}
	return (0);
}
