/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:48:16 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/18 20:52:15 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	int			eat;
	int			sleep;
	int			think;
	int			fork_r = 0;
	int			fork_l = 0;
	t_philo		*p;

	eat = 1;
	sleep = 2;
	think = 3;
	p = malloc(sizeof(t_philo));
	p = (t_philo *)arg;
	while (p->is_dead != 1)
	{
		//printf("philosopher %d has enterd the table\n", p->position);
		if (p->status == eat)
		{
			//schau ob forks passen
			printf("philosopher %d is Eating\n", p->position);
			fork_r = 1;
			fork_l = 1;
			p->is_eating = 1;
			usleep(30000);
			p->status = sleep;
		}
		if (p->status == sleep && p->is_sleep == 0)
		{
			printf("philosopher %d is sleeping\n", p->position);
			p->is_sleep = 1;
			usleep(30000);
			if (fork_r == 0 && fork_l == 0)
			{
				p->status = eat;
			}
			else
				p->status = think; 
			//function go to sleep
			//check if eat is possible
			//if eat is not possible 
			//think
		}
		if (p->status == think)
		{
			printf("philosopher %d is thinking\n", p->position);
			usleep(30000);
			if (fork_r == 0 &&  fork_l == 0 & p->is_sleep == 1)
			{
				p->status = eat;
			}
			if (fork_r == 1 || fork_l == 1)
			{
				printf("philosopher %d has Died!\n", p->position);
				p->is_dead = 1;
				if (p->is_dead == 1)
					exit(1);
			}
		}
	}
	return (0);
}

void	init_p(t_philo *p, int cnt, int sit_position)
{
	p->position = sit_position;
	p->is_dead = 0;
	p->is_sleep = 0;
	p->is_eating = 0;
	p->status = cnt+1;
}

int	main(void)
{
	t_philo		p[3];
	int			cnt;
	int			sit_position;

	cnt = 0;
	sit_position = 1;
	while (cnt < 3)
	{
		// if (cnt > 3)
			// init_p(&p[cnt], 3, sit_position);
		init_p(&p[cnt], cnt, sit_position);
		if (pthread_create(&p[cnt].thread, NULL, &routine, &p[cnt]) != 0)
			printf("Error!\n");
		cnt++;
		sit_position++;
	}
	cnt = 0;
	while (cnt < 3)
	{
		if (pthread_join(p[cnt].thread, NULL) != 0)
			printf("Error!\n");
		cnt++;
	}
	// init_p(&p[0], 1, 1);
	// if(pthread_create(&p[0].thread, NULL, &routine, &p[0]))
	return (0);
}
