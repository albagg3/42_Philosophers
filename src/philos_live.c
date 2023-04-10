/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_live.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:53:53 by albagarc          #+#    #+#             */
/*   Updated: 2023/04/10 14:07:23 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include <pthread.h>
#include <stdio.h>
#include "../inc/utils.h"
#include <unistd.h>
#include <stdlib.h>

void	*start_living(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->num % 2 != 0)
		usleep(1500);
	while (philo->house->is_alive && !philo->house->is_full)
	{
		philo_eat(philo);
		philo_sleep(philo);
		print_info(philo, THINK);
	}
	return (0);
}

int	finish_eating(t_house *house, int i)
{
	if (house->philos[i].times_ate >= house->times_should_eat)
	{
		if (i == house->nphilos - 1)
		{
			house->is_full = 1;
			return (1);
		}
	}
	return (0);
}

void	is_anyone_dead(t_house *house)
{
	int	i;

	while (house->is_alive && !house->is_full)
	{
		i = -1;
		while (++i < house->nphilos)
		{
			pthread_mutex_lock(&house->block_is_alive);
			
			if (passed_time(gettime(), house->philos[i].last_eat) \
				>= house->time_to_die)
			{
				printf("muere %lld\n", house->philos[i].last_eat);
				print_info(house->philos, DIE);
				house->is_alive = 0;
				// pthread_mutex_unlock(&house->block_is_alive);
				return ;
			}
			pthread_mutex_unlock(&house->block_is_alive);
		}
		while (house->times_should_eat && --i)
		{
			if (finish_eating(house, i))
				return ;
			else
				break ;
		}
	}
}

int	create_philos(t_house *house)
{
	pthread_t		*th;
	int				i;

	th = malloc(sizeof(t_philo) * house->nphilos);
	if (!th)
		return (1);
	house->start_time = gettime();
	i = 0;
	pthread_mutex_init(&house->print_sth, NULL);
	pthread_mutex_init(&house->block_is_alive, NULL);
	while (i < house->nphilos)
	{
		if (pthread_create(&th[i], NULL, start_living, &house->philos[i]) != 0)
			return (1);
		house->philos[i].last_eat = gettime();
		i++;
	}
	is_anyone_dead(house);
	while (--i)
		if (pthread_join(th[i], NULL) != 0)
			return (1);
	free(th);
	return (0);
}
