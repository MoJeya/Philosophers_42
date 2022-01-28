/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jointhreads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:02:20 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/28 17:42:54 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	detach_threads(t_data *data)
{
	int	cnt;

	cnt = 0;
	while (cnt < data->nb_of_phil)
	{
		if (pthread_detach(data->philo[cnt].thread_id) != 0)
			return (0);
		cnt++;
	}
	return (0);
}
