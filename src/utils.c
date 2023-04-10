/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:05:35 by codespace         #+#    #+#             */
/*   Updated: 2023/04/10 13:14:16 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include "../inc/defines.h"
#include <unistd.h>
#include <stdlib.h>

long long	gettime(void)
{
	struct timeval	tv;
	long long		milisec;

	gettimeofday(&tv, NULL);
	milisec = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milisec);
}

long long	passed_time(long long current_time, long long last_time)
{
	long long	result;

	result = current_time - last_time;
	return (result);
}

void	ft_usleep(long long time)
{
	long long	current;

	current = gettime();
	while (1)
	{
		if (passed_time(gettime(), current) >= time)
			break ;
		usleep(100);
	}
}

void	ft_free_destroy(t_house *house)
{
	int	i;

	i = 0;
	while (i < house->nphilos)
	{
		pthread_mutex_destroy(&house->philos[i].fork);
		i++;
	}
	free(house->philos);
	pthread_mutex_destroy(&house->print_sth);
	pthread_mutex_destroy(&house->block_is_alive);
}
