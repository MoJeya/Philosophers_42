/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:52:57 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/20 20:33:59 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long	ft_l_atoi(const char *str)
{
	long	i;
	long	result;
	long	negativ;

	result = 0;
	negativ = 1;
	i = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		negativ = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result == 2147483647)
			break ;
		i++;
	}
	return (result * negativ);
}