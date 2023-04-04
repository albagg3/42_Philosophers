/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_live.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:53:53 by albagarc          #+#    #+#             */
/*   Updated: 2023/04/04 18:29:18 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include <pthread.h>
#include <stdio.h>
#include "../inc/utils.h"
#include <unistd.h>
#include <stdlib.h>

void    philo_sleep(t_philo *philo)
{
    print_info(philo,SLEEP);
    ft_usleep(philo->house->time_to_sleep);
}


void    philo_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->house->philos[philo->left_fork_indx].fork);
    print_info(philo, FORK);
    pthread_mutex_lock(&philo->house->philos[philo->right_fork_indx].fork);
    print_info(philo, FORK);
	philo->last_eat = gettime();
    philo->times_ate++;
    print_info(philo, EAT);
    ft_usleep(philo->house->time_to_eat);
    pthread_mutex_unlock(&philo->house->philos[philo->left_fork_indx].fork);
    pthread_mutex_unlock(&philo->house->philos[philo->right_fork_indx].fork);
}

void	*start_living(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo*)arg;
	if(philo->num % 2 != 0)
		usleep(1500);
	if(philo->house->nphilos == 1)
	{
		print_info(philo,FORK);
		ft_usleep(philo->house->time_to_die);
		print_info(philo, DIE);
		philo->house->is_alive = 0;
	}
	while(philo->house->is_alive && !philo->house->is_full)
    {
        philo_eat(philo);
        philo_sleep(philo);
		print_info(philo, THINK);
    }
	return(0);
}


void	is_anyone_dead(t_house *house)
{
	long long current;
	int i;

	while(house->is_alive && !house->is_full)
	{
		i = 0;
		while( i < house->nphilos)
		{ 
			// write(1, "a\n", 2);
			current = gettime();
			pthread_mutex_lock(&house->block_is_alive);
			if(passed_time(current, house->philos[i].last_eat) >= house->time_to_die)
			{
				print_info(house->philos, DIE);
				house->is_alive = 0;
				return ;
			}
			pthread_mutex_unlock(&house->block_is_alive);
			i++;
		}
		i = 0;
		while (house->times_should_eat && i < house->nphilos)
		{
			// write(1, "b\n", 2);
			if (house->philos[i].times_ate >= house->times_should_eat)
			{
				if (i == house->nphilos - 1)
				{
					house->is_full = 1;
					return ;
				}
			}
			else
				break;
			i++;
		}
		
	}
}



int	create_philos(t_house *house)
{
	pthread_t *th;
	int i;

	th = malloc(sizeof(t_philo) * house->nphilos);
	if(!th)
		return(1);
	house->start_time = gettime();
	i = 0;
	pthread_mutex_init(&house->print_sth, NULL);
	pthread_mutex_init(&house->block_is_alive, NULL);
	while (i < house->nphilos)
	{
		if(pthread_create(&th[i], NULL, start_living, &house->philos[i]) != 0)
			return (1);
		house->philos[i].last_eat = gettime();
		i++;
	}
	is_anyone_dead(house);
	while (i--)
		if(pthread_join(th[i], NULL) != 0)
			return (1);
	free(th);
	return(0);
}