/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:48:16 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/24 01:43:46 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	hndl_input(char *argv[], int argc, t_data *data)
{
	if (argc  < 6 || data == NULL)
		return (1);
	data->nb_of_phil = (int)ft_l_atoi(argv[1]);
	data->time_to_die = (int)ft_l_atoi(argv[2]);
	data->time_to_eat = (int)ft_l_atoi(argv[3]);
	data->time_to_sleep = (int)ft_l_atoi(argv[4]);
	data->meals_to_eat = (int)ft_l_atoi(argv[5]);;
	data->is_dead = 0;
	data->meals_eaten = 0;
	data->start = 0;
	return (0);
}

int	init_data(t_data *data)
{
	int				cnt;
	int				time;

	time = timestamp();
	cnt = 0;
	pthread_mutex_init(&data->status, NULL);
	data->philo = malloc(data->nb_of_phil * sizeof(struct s_philo));
	while (cnt < data->nb_of_phil)
	{
		data->philo[cnt].id = cnt + 1;
		data->philo[cnt].meals = 0;
		data->philo[cnt].last_meal = time;
		pthread_mutex_init(&data->philo[cnt].fork, NULL);
		cnt++;
	}
	return (0);
}

int	join_threads(t_data *data)
{
	int	cnt;

	cnt = 0;
	while (cnt < data->nb_of_phil)
	{
		if (pthread_join(data->philo[cnt].thread_id, NULL) != 0)
			return (0);
		cnt++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		i;

	data = (t_data *)calloc(sizeof(t_data), 1);
	if (!data)
		return (1);
	i = 0;
	if (hndl_input(argv, argc, data) == 0)
	{
		init_data(data);
		creat_data(data);
		check_death(data);
		join_threads(data);	
		free_thread(data);
	}
	else
		return (1);
	pthread_mutex_destroy(&data->status);
	return (0);
}
