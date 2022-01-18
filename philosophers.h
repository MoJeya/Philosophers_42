/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:30:06 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/18 20:39:58 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_time_info
{
	struct timeval	*t;
	struct timezone	*t_zone;
	struct tm		*today;
}t_time_inf;

typedef struct s_philo
{
	int				position;
	int				is_dead;
	int				is_sleep;
	int				is_eating;
	pthread_t		thread;
	int				status;
	pthread_mutex_t	print_status;
	
}t_philo;

void	time_in_ms(t_time_inf ti);

#endif
