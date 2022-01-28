/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:48:16 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/28 18:05:34 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	hndl_input(char **argv, int argc, t_data *data)
{
	printf("handle input start...\n");
	if (argc  < 5 || data == NULL)
		return (1);
	else if (argc == 5)
		data->meals_to_eat = -1;
	else
		data->meals_to_eat = ft_atoi(argv[5]);
	data->nb_of_phil = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->is_dead = 0;
	data->is_running = 0;
	data->lock = 1;
	printf("handle input end...\n");
	return (0);
}

int	init_data(t_data *data)
{
	int				cnt;

	printf("inti start...\n");
	pthread_mutex_init(&data->status, NULL);
	data->philo = malloc(data->nb_of_phil * sizeof(struct s_philo));
	if (!data->philo)
		return (1);
	cnt = -1;
	data->start = timestamp();
	data->meals_eaten = 0;
	while (++cnt < data->nb_of_phil)
	{
		data->philo[cnt].id = cnt;
		data->philo[cnt].meals = 0;
		pthread_mutex_init(&data->philo[cnt].fork, NULL);
	}
	printf("init end...\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;

	i = 0;
	if (hndl_input(argv, argc, &data) == 1 || init_data(&data) != 0)
	{
		write(2, "error\n", 6);
		return (1);
	}
	creat_data(&data);
	check_death(&data);
	detach_threads(&data);
	free_thread(&data);
	return (0);
}
