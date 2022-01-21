/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:51:32 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/21 16:44:06 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*eat(int id, t_data *data)
{
	pthread_mutex_lock(&data->philo[id].fork);
	pthread_mutex_lock(&data->philo[(id + 1) % id].fork);
	printf("Philosopher %d is eating\n", id);
	usleep(3000);
	pthread_mutex_unlock(&data->philo[id].fork);
	pthread_mutex_unlock(&data->philo[(id + 1) % id].fork);
	printf("Philosopher %d has finisched eating!\n", id);
	data->meals_eaten++;
	data->philo[id].last_meal = timestamp();
	data->philo[id].meals++;
	return (NULL);
}

// int	check_if_dead(t_data *data, int id)
// {
// 	int	bol;

// 	bol = ft_timepass(data->philo[id]);
// 	printf("time is running %lu\n", (long)bol);
// 	return (bol);
// }

void	*routine(void *arg)
{
	struct s_philo	*philo;

	philo = (struct s_philo *)arg;
	// printf("%d is going to eat\n", philo->id);
	// printf("philo %d last meal: %d\n", philo->id, philo->meals);
	//check_if_dead(philo->data, philo->id);
	while (philo->data->meals_eaten < philo->data->meals_to_eat)
	{
		eat(philo->id, philo->data);
	}
	
	return (NULL);
}

int	creat_data(t_data *data)
{
	int				cnt;
	//struct s_philo	philo;

	//philo = (struct s_philo){ 0 };
	cnt = 0;
	while (cnt < data->nb_of_phil)
	{
		//philo = data->philo[cnt];
		if (pthread_create(&data->philo[cnt].thread_id, NULL, &routine, data->philo + cnt) != 0)
			return (1);
		cnt++;
	}
	cnt = 0;
	while (cnt < data->nb_of_phil)
	{
		//philo = data->philo[cnt];
		if (pthread_join(data->philo[cnt].thread_id, NULL) != 0)
			return (0);
		cnt++;
	}
	cnt = 0;
	while (cnt < data->nb_of_phil)
	{
		//philo = data->philo[cnt];
		pthread_mutex_destroy(&data->philo[cnt].fork);
		cnt++;
	}
	return (0);
}
