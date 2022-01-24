/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:30:06 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/24 01:46:44 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int				nb_of_phil;
	int				time_to_eat;
	int				meals_eaten;
	int				meals_to_eat;
	long			start;
	int				time_to_die;
	int				time_to_sleep;
	int				is_dead;
	int				num_of_philo;
	struct s_philo	*philo;
	pthread_mutex_t	status;
}t_data;

struct	s_philo
{
	int				id;
	pthread_t		thread_id;
	int				meals;
	int				last_meal;
	pthread_mutex_t	fork;
	t_data			*data;
};

int				ft_l_atoi(const char *str);
void			*routine(void *arg);
int				creat_data(t_data *data);
int				join_threads(t_data *data);
long			timestamp(void);
int				check_death(t_data *data);
void			ft_ms_sleep(useconds_t time_ms);
void			print_message(t_data *data, char *status, int id);
void			free_thread(t_data *data);

#endif
