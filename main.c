/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:48:16 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/20 20:34:17 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	*routine(void *arg)
// {
// 	int			eat;
// 	int			sleep;
// 	int			think;
// 	int			fork_r = 0;
// 	int			fork_l = 0;
// 	t_philo		*p;

// 	eat = 1;
// 	sleep = 2;
// 	think = 3;
// 	p = malloc(sizeof(t_philo));
// 	p = (t_philo *)arg;


int	hndl_input(char *argv[], int argc, t_data *data)
{
	printf("argc: %d\n", argc);
	if (argc  < 6 || data == NULL)
		return (1);
	data->nb_of_phil = (int)ft_l_atoi(argv[1]);
	data->time_to_die = (int)ft_l_atoi(argv[2]);
	data->time_to_eat = (int)ft_l_atoi(argv[3]);
	data->time_to_sleep = (int)ft_l_atoi(argv[4]);
	data->meals_to_eat = (int)ft_l_atoi(argv[5]);;
	return (0);
}

int	init_data(t_data *data)
{
	int				cnt;
	int				time;

	time = timestamp();
	cnt = 1;
	pthread_mutex_init(&data->status, NULL);
	data->philo = malloc(data->nb_of_phil * sizeof(struct s_philo));
	while (cnt < data->nb_of_phil)
	{
		data->philo[cnt].id = cnt;
		data->philo[cnt].meals = 0;
		data->philo[cnt].last_meal = time;
		pthread_mutex_init(&data->philo[cnt].fork, NULL);
		cnt++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		i;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	i = 0;
	if (hndl_input(argv, argc, data) == 0)
	{
		init_data(data);
		creat_data(data);
	}
	return (0);
}
