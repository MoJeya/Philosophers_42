/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:51:32 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/20 20:31:09 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*eat(t_data *data, int num)
{
	pthread_mutex_lock(&data->philo[num].fork);
	pthread_mutex_lock(&data->philo[num % 2].fork);
	printf("Philosopher %d is eating\n", data->philo[num].id);
	usleep(3000);
	pthread_mutex_unlock(&data->philo[num].fork);
	pthread_mutex_unlock(&data->philo[num % 2].fork);
	printf("Philosopher %d has finisched eating!\n", data->philo[num].id);
	return (NULL);
}

void	*routine(void *arg)
{
	struct s_philo	*philo;

	philo = (struct s_philo *)arg;
	printf("Philosopher %d has enterd the room\n", philo->id);
	//eat
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
		printf("1\n");
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
